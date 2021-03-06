#include <iostream>

#if defined(SYSTEMC)
#include "Simulation/BFER/Standard/SystemC/SC_Simulation_BFER_std.hpp"
#elif defined(STARPU)
#include "Simulation/BFER/Standard/StarPU/SPU_Simulation_BFER_std.hpp"
#else
#include "Simulation/BFER/Standard/Threads/Simulation_BFER_std_threads.hpp"
#endif
#include "Tools/Codec/Uncoded/Codec_uncoded.hpp"

#include "Launcher_BFER_uncoded.hpp"

using namespace aff3ct::tools;
using namespace aff3ct::simulation;
using namespace aff3ct::launcher;

template <typename B, typename R, typename Q>
Launcher_BFER_uncoded<B,R,Q>
::Launcher_BFER_uncoded(const int argc, const char **argv, std::ostream &stream)
: Launcher_BFER<B,R,Q>(argc, argv, stream)
{
	this->params.code     .type       = "Channel";
	this->params.encoder  .type       = "NO";
	this->params.quantizer.n_bits     = 6;
	this->params.quantizer.n_decimals = 2;
	this->params.decoder  .type       = "NO";
	this->params.decoder  .implem     = "HARD_DECISION";
}

template <typename B, typename R, typename Q>
void Launcher_BFER_uncoded<B,R,Q>
::build_args()
{
	Launcher_BFER<B,R,Q>::build_args();

	// ------------------------------------------------------------------------------------------------------- encoder
	this->opt_args[{"enc-type"}][2] = "NO";

	// ------------------------------------------------------------------------------------------------------- decoder
	this->opt_args[{"dec-type", "D"}].push_back("NONE");
	this->opt_args[{"dec-implem"   }].push_back("NONE");
}

template <typename B, typename R, typename Q>
void Launcher_BFER_uncoded<B,R,Q>
::store_args()
{
	Launcher_BFER<B,R,Q>::store_args();
}

template <typename B, typename R, typename Q>
Simulation* Launcher_BFER_uncoded<B,R,Q>
::build_simu()
{
	this->codec = new Codec_uncoded<B,Q>(this->params);
#if defined(SYSTEMC)
	return new SC_Simulation_BFER_std     <B,R,Q>(this->params, *this->codec);
#elif defined(STARPU)
	return new SPU_Simulation_BFER_std    <B,R,Q>(this->params, *this->codec);
#else
	return new Simulation_BFER_std_threads<B,R,Q>(this->params, *this->codec);
#endif
}

// ==================================================================================== explicit template instantiation 
#include "Tools/types.h"
#ifdef MULTI_PREC
template class aff3ct::launcher::Launcher_BFER_uncoded<B_8,R_8,Q_8>;
template class aff3ct::launcher::Launcher_BFER_uncoded<B_16,R_16,Q_16>;
template class aff3ct::launcher::Launcher_BFER_uncoded<B_32,R_32,Q_32>;
template class aff3ct::launcher::Launcher_BFER_uncoded<B_64,R_64,Q_64>;
#else
template class aff3ct::launcher::Launcher_BFER_uncoded<B,R,Q>;
#endif
// ==================================================================================== explicit template instantiation
