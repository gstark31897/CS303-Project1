#ifndef H_POLYNOMIAL
#define H_POLYNOMIAL

#include <vector>
#include <string>

#include "term.h"


class Polynomial
{
private:
    std::vector<Term> m_terms;

    friend std::ostream& operator<<(std::ostream &out, const Polynomial &poly);
    friend std::istream& operator>>(std::istream &in, Polynomial &poly);

public:
    Polynomial() {};
};
#endif
