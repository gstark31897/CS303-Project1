#ifndef H_POLYNOMIAL
#define H_POLYNOMIAL

#include <list>
#include <string>

#include "term.h"


class Polynomial
{
private:
    std::list<Term> m_terms;

    friend std::ostream& operator<<(std::ostream &out, const Polynomial &poly);
    friend std::istream& operator>>(std::istream &in, Polynomial &poly);

public:
    Polynomial() {};

    void clear() { m_terms.clear(); };
    void addTerm(const Term &term);

    Polynomial& operator+=(const Polynomial &poly);
    Polynomial& operator+=(const Term &term);
};

#endif
