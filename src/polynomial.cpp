#include "polynomial.h"

#include <sstream>
#include <iostream>

using namespace std;


ostream& operator<<(ostream &out, const Polynomial &poly)
{
    for (auto it = poly.m_terms.begin(); it != poly.m_terms.end(); ++it)
        out << *it;
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
