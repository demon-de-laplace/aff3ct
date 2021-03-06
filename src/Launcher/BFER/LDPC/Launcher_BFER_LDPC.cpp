#include <iostream>

#if defined(SYSTEMC)
#include "Simulation/BFER/Standard/SystemC/SC_Simulation_BFER_std.hpp"
#elif defined(STARPU)
#include "Simulation/BFER/Standard/StarPU/SPU_Simulation_BFER_std.hpp"
#else
#include "Simulation/BFER/Standard/Threads/Simulation_BFER_std_threads.hpp"
#endif
#include "Tools/Codec/LDPC/Codec_LDPC.hpp"

#include "Launcher_BFER_LDPC.hpp"

using namespace aff3ct::tools;
using namespace aff3ct::simulation;
using namespace aff3ct::launcher;

template <typename B, typename R, typename Q>
Launcher_BFER_LDPC<B,R,Q>
::Launcher_BFER_LDPC(const int argc, const char **argv, std::ostream &stream)
: Launcher_BFER<B,R,Q>(argc, argv, stream)
{
	this->params.code     .type             = "LDPC";
	this->params.encoder  .type             = "AZCW";
	this->params.encoder  .systematic       = true;
	this->params.quantizer.n_bits           = 6;
	this->params.quantizer.n_decimals       = 2;
	this->params.decoder  .type             = "BP_FLOODING";
	this->params.decoder  .implem           = "SPA";
	this->params.decoder  .n_ite            = 10;
	this->params.decoder  .offset           = 0.f;
	this->params.decoder  .normalize_factor = 1.f;
	this->params.decoder  .enable_syndrome  = true;
	this->params.decoder  .syndrome_depth   = 2;
}

template <typename B, typename R, typename Q>
void Launcher_BFER_LDPC<B,R,Q>
::build_args()
{
	Launcher_BFER<B,R,Q>::build_args();

	// ---------------------------------------------------------------------------------------------------------- code
	this->req_args[{"cde-alist-path"}] =
		{"string",
		 "path to the AList formated file."};

	// ------------------------------------------------------------------------------------------------------- encoder
	this->opt_args[{"enc-type"}][2] += ", LDPC, LDPC_H, LDPC_DVBS2";

	// ------------------------------------------------------------------------------------------------------- decoder
	this->opt_args[{"dec-type", "D"}].push_back("BP, BP_FLOODING, BP_LAYERED");
	this->opt_args[{"dec-implem"   }].push_back("ONMS, SPA, LSPA, GALA");
	this->opt_args[{"dec-ite", "i"}] =
		{"positive_int",
		 "maximal number of iterations in the turbo decoder."};
	this->opt_args[{"dec-off"}] =
		{"float",
		 "offset used in the offset min-sum BP algorithm (works only with \"--dec-implem ONMS\")."};
	this->opt_args[{"dec-norm"}] =
		{"positive_float",
		 "normalization factor used in the normalized min-sum BP algorithm (works only with \"--dec-implem ONMS\")."};
	this->opt_args[{"dec-no-synd"}] =
		{"",
		 "disable the syndrome detection (disable the stop criterion in the LDPC decoders)."};
	this->opt_args[{"dec-synd-depth"}] =
		{"positive_int",
		 "successive number of iterations to validate the syndrome detection."};
	this->opt_args[{"dec-simd"}] =
		{"string",
		 "the SIMD strategy you want to use.",
		 "INTER"};
}

template <typename B, typename R, typename Q>
void Launcher_BFER_LDPC<B,R,Q>
::store_args()
{
	Launcher_BFER<B,R,Q>::store_args();

	// ---------------------------------------------------------------------------------------------------------- code
	if(this->ar.exist_arg({"cde-alist-path"})) this->params.code.alist_path = this->ar.get_arg({"cde-alist-path"});

	// ------------------------------------------------------------------------------------------------------- decoder
	if(this->ar.exist_arg({"dec-ite",   "i"})) this->params.decoder.n_ite            = this->ar.get_arg_int  ({"dec-ite", "i"  });
	if(this->ar.exist_arg({"dec-off"       })) this->params.decoder.offset           = this->ar.get_arg_float({"dec-off"       });
	if(this->ar.exist_arg({"dec-norm"      })) this->params.decoder.normalize_factor = this->ar.get_arg_float({"dec-norm"      });
	if(this->ar.exist_arg({"dec-synd-depth"})) this->params.decoder.syndrome_depth   = this->ar.get_arg_int  ({"dec-synd-depth"});
	if(this->ar.exist_arg({"dec-no-synd"   })) this->params.decoder.enable_syndrome  = false;
	if(this->ar.exist_arg({"dec-simd"      })) this->params.decoder.simd_strategy    = this->ar.get_arg      ({"dec-simd"      });

	if (this->params.decoder.simd_strategy == "INTER" && !this->ar.exist_arg({"sim-inter-lvl"}))
		this->params.simulation.inter_frame_level = mipp::nElReg<Q>();
}

template <typename B, typename R, typename Q>
Simulation* Launcher_BFER_LDPC<B,R,Q>
::build_simu()
{
	this->codec = new Codec_LDPC<B,Q>(this->params);
#if defined(SYSTEMC)
	return new SC_Simulation_BFER_std     <B,R,Q>(this->params, *this->codec);
#elif defined(STARPU)
	return new SPU_Simulation_BFER_std    <B,R,Q>(this->params, *this->codec);
#else
	return new Simulation_BFER_std_threads<B,R,Q>(this->params, *this->codec);
#endif
}

template <typename B, typename R, typename Q>
std::vector<std::pair<std::string,std::string>> Launcher_BFER_LDPC<B,R,Q>
::header_code()
{
	auto p = Launcher_BFER<B,R,Q>::header_code();

	p.push_back(std::make_pair("AList file path", this->params.code.alist_path));

	return p;
}

template <typename B, typename R, typename Q>
std::vector<std::pair<std::string,std::string>> Launcher_BFER_LDPC<B,R,Q>
::header_decoder()
{
	auto p = Launcher_BFER<B,R,Q>::header_decoder();

	std::string syndrome = this->params.decoder.enable_syndrome ? "on" : "off";

	if (!this->params.decoder.simd_strategy.empty())
		p.push_back(std::make_pair("SIMD strategy", this->params.decoder.simd_strategy));

	p.push_back(std::make_pair("Num. of iterations (i)", std::to_string(this->params.decoder.n_ite)));
	if (this->params.decoder.implem == "ONMS")
	{
		p.push_back(std::make_pair("Offset", std::to_string(this->params.decoder.offset)));
		p.push_back(std::make_pair("Normalize factor", std::to_string(this->params.decoder.normalize_factor)));
	}
	p.push_back(std::make_pair("Stop criterion (syndrome)", syndrome));

	if (this->params.decoder.enable_syndrome)
		p.push_back(std::make_pair("Stop criterion depth",  std::to_string(this->params.decoder.syndrome_depth)));

	return p;
}

template <typename B, typename R, typename Q>
std::vector<std::pair<std::string,std::string>> Launcher_BFER_LDPC<B,R,Q>
::header_encoder()
{
	auto p = Launcher_BFER<B,R,Q>::header_encoder();

	if (this->params.encoder.type == "LDPC")
		p.push_back(std::make_pair("Path", this->params.encoder.path));

	return p;
}
// ==================================================================================== explicit template instantiation 
#include "Tools/types.h"
#ifdef MULTI_PREC
template class aff3ct::launcher::Launcher_BFER_LDPC<B_8,R_8,Q_8>;
template class aff3ct::launcher::Launcher_BFER_LDPC<B_16,R_16,Q_16>;
template class aff3ct::launcher::Launcher_BFER_LDPC<B_32,R_32,Q_32>;
template class aff3ct::launcher::Launcher_BFER_LDPC<B_64,R_64,Q_64>;
#else
template class aff3ct::launcher::Launcher_BFER_LDPC<B,R,Q>;
#endif
// ==================================================================================== explicit template instantiation
