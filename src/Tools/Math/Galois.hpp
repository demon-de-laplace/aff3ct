#ifndef GALOIS_HPP
#define GALOIS_HPP

#include <vector>
#include <mipp.h>

namespace aff3ct
{
namespace tools
{
class Galois
{
protected:
	const int K;
	const int N; // number of non-nul elements in the field : N = 2^m - 1
	const int m; // order of the Galois Field
	const int t;
	const int d;

public:
	Galois(const int& K, const int& N, const int& m, const int& t);
	virtual ~Galois();

	void Select_Polynomial(); // move this private section
	void Generate_GF();
	void Compute_BCH_Generator_Polynomial();

	int get_m() const;

	mipp::vector<int> alpha_to; // log table of GF(2**m)
	mipp::vector<int> index_of; // antilog table of GF(2**m)
	mipp::vector<int> p;        // coefficients of a primitive polynomial used to generate GF(2**m)
	mipp::vector<int> g;        // coefficients of the generator polynomial, g(x)
};
}
}

#endif /* GALOIS_HPP */
