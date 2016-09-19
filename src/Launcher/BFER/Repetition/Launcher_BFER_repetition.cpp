#include <iostream>

#include "Tools/Display/bash_tools.h"
#include "Launcher_BFER_repetition.hpp"
#include "../../../Simulation/BFER/Repetition/Simulation_BFER_repetition.hpp"

template <typename B, typename R, typename Q>
Launcher_BFER_repetition<B,R,Q>
::Launcher_BFER_repetition(const int argc, const char **argv, std::ostream &stream)
: Launcher_BFER<B,R,Q>(argc, argv, stream)
{
	this->params.code     .type       = "Repetition";
	this->params.encoder  .buffered   = true;
	this->params.quantizer.n_bits     = 6;
	this->params.quantizer.n_decimals = 2;
	this->params.decoder  .type       = "REPETITION";
	this->params.decoder  .implem     = "STD";
}

template <typename B, typename R, typename Q>
void Launcher_BFER_repetition<B,R,Q>
::build_args()
{
	Launcher_BFER<B,R,Q>::build_args();

	// ------------------------------------------------------------------------------------------------------- encoder
	this->opt_args[{"enc-no-buff"}] =
		{"",
		 "disable the buffered encoding."};
}

template <typename B, typename R, typename Q>
void Launcher_BFER_repetition<B,R,Q>
::store_args()
{
	Launcher_BFER<B,R,Q>::store_args();

	// ------------------------------------------------------------------------------------------------------- encoder
	if(this->ar.exist_arg({"enc-no-buff"})) this->params.encoder.buffered = false;
}

template <typename B, typename R, typename Q>
void Launcher_BFER_repetition<B,R,Q>
::print_header()
{
	Launcher_BFER<B,R,Q>::print_header();

	std::string buff_enc = ((this->params.encoder.buffered) ? "on" : "off");

	// display configuration and simulation parameters
	this->stream << "# " << bold("* Buffered encoding             ") << " = " << buff_enc << std::endl;
}

template <typename B, typename R, typename Q>
void Launcher_BFER_repetition<B,R,Q>
::build_simu()
{
	this->simu = new Simulation_BFER_repetition<B,R,Q>(this->params);
}

// ==================================================================================== explicit template instantiation 
#include "Tools/types.h"
#ifdef MULTI_PREC
template class Launcher_BFER_repetition<B_8,R_8,Q_8>;
template class Launcher_BFER_repetition<B_16,R_16,Q_16>;
template class Launcher_BFER_repetition<B_32,R_32,Q_32>;
template class Launcher_BFER_repetition<B_64,R_64,Q_64>;
#else
template class Launcher_BFER_repetition<B,R,Q>;
#endif
// ==================================================================================== explicit template instantiation