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
    poly.m_terms.clear();
    // grab a line from the input stream
    string line;
    getline(in, line);
    // make a stream from the line
    stringstream ss(line);
    // keep reading terms from it until we get to the end
    Term term;
    while (!ss.eof())
    {
        ss >> term;
        poly.addTerm(term);
    }
}


Polynomial& Polynomial::operator+=(const Polynomial &poly)
{
    // Iterate through all the terms in the other polynomial
    //     if we don't have a term with the same variable and exponent, then add 0 coefficient term to our own list
    for (list<Term>::const_iterator it = poly.m_terms.begin(); it != poly.m_terms.end(); ++it)
    {
        bool found = false;
        for (list<Term>::iterator it2 = m_terms.begin(); it2 != m_terms.end(); ++it2)
        {
            if (it->getExponent() == it2->getExponent() && it->getVariable() == it2->getVariable())
            {
                found = true;
                break;
            }
        }

        // Add it to our terms if we didn't find one
        if (!found)
        {
            Term temp = Term(0, it->getExponent(), it->getVariable());
            addTerm(temp);
        }
    }

    for (list<Term>::iterator it = m_terms.begin(); it != m_terms.end(); ++it)
    {
        for (list<Term>::const_iterator it2 = poly.m_terms.begin(); it2 != poly.m_terms.end(); ++it2)
        {
            if (it->getExponent() == it2->getExponent() && it->getVariable() == it2->getVariable())
            {
                (*it) += (*it2);
            }
        }
    }
    return *this;
}


void Polynomial::addTerm(Term &term)
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

