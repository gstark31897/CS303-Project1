#include "polynomial.h"

#include <sstream>
#include <iostream>

using namespace std;


ostream& operator<<(ostream &out, const Polynomial &poly)
{
    // print a zero if we don't have any terms
    if (poly.m_terms.size() == 0)
    {
        out << 0;
        return out;
    }
    // iterate through all the terms
    list<Term>::const_iterator it = poly.m_terms.begin();
    while (true)
    {
        // print out the term
        out << *it;
        // check if there is a next term
        if (++it != poly.m_terms.end())
        {
            // print a plus sign if there is a next term that is not negative
            if (!it->isNegative())
            {
                out << '+';
            }
        }
        else
            break;
    }
    return out;
}


istream& operator>>(istream &in, Polynomial &poly)
{
    // clear the terms
    poly.clear();
    // grab a line from the input stream
    string line;
    getline(in, line);
    // make a stream from the line
    stringstream ss(line);
    // keep reading terms from it until we get to the end
    Term term;
    while (!ss.eof())
    {
        // add the term to the polynomial
        ss >> term;
        poly += term;
    }
}


Polynomial& Polynomial::operator+=(const Polynomial &poly)
{
    // iterate through all the terms in the second polynomial
    for (list<Term>::const_iterator it = poly.m_terms.begin(); it != poly.m_terms.end(); ++it)
    {
        // add the terms to this polynomial
        addTerm(*it);
    }
    return *this;
}


Polynomial& Polynomial::operator+=(const Term &term)
{
    // just an operator for the addTerm method
    addTerm(term);
    return *this;
}


void Polynomial::addTerm(const Term &term)
{
    // Just add the term if we don't have any yet
    if (m_terms.size() == 0)
    {
        m_terms.push_back(term);
        return;
    }
    // look for a smaller term
    for (list<Term>::iterator it = m_terms.begin(); it != m_terms.end(); ++it)
    {
        // put this term before the smaller one
        if (*it < term)
        {
            m_terms.insert(it, term);
            return;
        }
        // add if to the existing term if we find duplicate exponents
        if (*it == term)
        {
            *it += term;
            // remove the term if the two canceled eachother out
            if (it->getCoefficient() == 0)
                m_terms.erase(it);
            return;
        }
    }
    // we didn't find any smaller terms, put this one on the end
    m_terms.push_back(term);
}

