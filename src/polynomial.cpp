#include "polynomial.h"

#include <sstream>
#include <iostream>

using namespace std;


ostream& operator<<(ostream &out, const Polynomial &poly)
{
    if (poly.m_terms.size() == 0)
    {
        out << 0;
        return out;
    }

    list<Term>::const_iterator it = poly.m_terms.begin();
    while (true)
    {
        out << *it;
        if (++it != poly.m_terms.end())
        {
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
    // Grab a line from the input stream
    string line;
    getline(in, line);

    std::cout << "Got Line: " << line << std::endl;

    stringstream ss(line);
    Term term;
    while (!ss.eof())
    {
        ss >> term;
        std::cout << "Got Term: " << term << std::endl;
        poly.addTerm(term);
        //poly.m_terms.push_back(term);
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
            //m_terms.push_back(Term(0, it->getExponent(), it->getVariable()));
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

    for (list<Term>::const_iterator it = m_terms.begin(); it != m_terms.end(); ++it)
    {
        if (*it < term)
        {
            m_terms.insert(it, term);
            return;
        }
    }
}

