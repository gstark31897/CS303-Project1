#include "polynomial.h"

#include <sstream>
#include <iostream>

using namespace std;


ostream& operator<<(ostream &out, const Polynomial &poly)
{
    vector<Term>::const_iterator it = poly.m_terms.begin();
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
    out << endl;
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
        poly.m_terms.push_back(term);
    }
}


Polynomial& Polynomial::operator+=(const Polynomial &poly)
{
    // Iterate through all the terms in the other polynomial
    //     if we don't have a term with the same variable and exponent, then add 0 coefficient term to our own list
    for (auto it = poly.m_terms.begin(); it != poly.m_terms.end(); ++it)
    {
        bool found = false;
        for (auto it2 = m_terms.begin(); it2 != m_terms.end(); ++it2)
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
            m_terms.push_back(Term(0, it->getExponent(), it->getVariable()));
        }
    }

    for (auto it = m_terms.begin(); it != m_terms.end(); ++it)
    {
        for (auto it2 = poly.m_terms.begin(); it2 != poly.m_terms.end(); ++it2)
        {
            if (it->getExponent() == it2->getExponent() && it->getVariable() == it2->getVariable())
            {
                (*it) += (*it2);
            }
        }
    }
    return *this;
}
