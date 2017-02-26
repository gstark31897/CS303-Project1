#include "term.h"

#include <iostream>
using namespace std;



TermException::TermException(string message)
{
    m_message = message;
}


Term::Term()
{
    m_coefficient = 0;
    m_exponent    = 0;
    m_variable    = "";
}


Term::Term(int coefficient, int exponent, string variable)
{
    m_coefficient = coefficient;
    m_exponent    = exponent;
    m_variable    = variable;
}


Term& Term::operator+=(const Term &other)
{
    if (m_variable != other.m_variable && m_exponent != 0 && other.m_exponent != 0)
        throw TermException("Term variables do not match");
    if (m_exponent != other.m_exponent)
        throw TermException("Term exponents do not match");
    m_coefficient += other.m_coefficient;
    return *this;
}


ostream& operator<<(ostream &out, const Term &term)
{
    if (term.m_coefficient == 0)
        return out;
    out << term.m_coefficient;
    if (term.m_exponent != 0)
    {
        out << term.m_variable;
        if (term.m_exponent > 0)
            out << '^' << term.m_exponent;
    }
    return out;
}


istream& operator>>(istream &in, Term &term)
{
    char c = in.peek();
    term.m_variable.clear();
    bool negative = false;
    while (c == ' ' || c == '+' || c == '-')
    {
        if (c == '-')
            negative = true;
        in >> c;
        c = in.peek();
    }
    in >> term.m_coefficient;
    if (negative)
        term.m_coefficient *= -1;

    c = in.peek();
    while (c != '^' && c != ' ' && c != '+' && c != '-' && c != '\0' && c != '\n' && !in.eof())
    {
        in >> c;
        term.m_variable += c;
        c = in.peek();
    }

    if (term.m_variable.empty())
    {
        std::cout << "no variable" << std::endl;
        term.m_exponent = 0;
        return in;
    }

    if (c == '^')
    {
        in >> c;
        in >> term.m_exponent;
    }
    else
    {
        term.m_exponent = 1;
    }
}

