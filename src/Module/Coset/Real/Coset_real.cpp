#include "Coset_real.hpp"

using namespace aff3ct::module;

template <typename B, typename D>
Coset_real<B,D>::Coset_real(const int size, const int n_frames, const std::string name)
: Coset<B,D>(size, n_frames, name)
{
}

template <typename B, typename D>
Coset_real<B,D>::~Coset_real()
{
}

template <typename B, typename D>
void Coset_real<B,D>::apply(const B *ref, const D *in_data, D *out_data)
{
	for (auto i = 0; i < this->size * this->n_frames; i++)
		out_data[i] = ref[i] ? -in_data[i] : in_data[i];
}

// ==================================================================================== explicit template instantiation
#include "Tools/types.h"
#ifdef MULTI_PREC
template class aff3ct::module::Coset_real<B_8,  Q_8 >;
template class aff3ct::module::Coset_real<B_16, Q_16>;
template class aff3ct::module::Coset_real<B_32, Q_32>;
template class aff3ct::module::Coset_real<B_64, Q_64>;
#else
template class aff3ct::module::Coset_real<B,Q>;
#endif
// ==================================================================================== explicit template instantiation
