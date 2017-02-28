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
    // throw an exception if the variables do not match (and their variables are not zero)
    if (m_variable != other.getVariable() && m_exponent != 0 && other.getExponent() != 0)
        throw TermException("Term variables do not match");
    // throw an exception if the exponents do not match
    if (m_exponent != other.m_exponent)
        throw TermException("Term exponents do not match");
    // add the coefficients
    m_coefficient += other.m_coefficient;
    return *this;
}


bool Term::operator<(const Term &other) const
{
    // compare the exponents
    return m_exponent < other.getExponent();
}



bool Term::operator>(const Term &other) const
{
    // compare the exponents
    return m_exponent > other.getExponent();
}


bool Term::operator==(const Term &other) const
{
    // compare the exponents
    return m_exponent == other.getExponent() && m_variable == other.getVariable();
}


ostream& operator<<(ostream &out, const Term &term)
{
    // don't print anything if we multiply by zero
    if (term.getCoefficient() == 0)
        return out;
    // print out the coefficient if it is not one
    if (term.getCoefficient() != 1)
        // only print out a minus if it's negative one and there's a variable to print
        if (term.getCoefficient() == -1 && term.getExponent() != 0 && term.getVariable().size() > 0)
            out << '-';
        else
            out << term.getCoefficient();
    // print out the variable if the exponent is not zero
    if (term.getExponent() != 0)
        out << term.getVariable();
    // print out the exponent if it is not zero or one
    if (term.getExponent() != 1 && term.getExponent() != 0)
        out << '^' << term.getExponent();
    return out;
}


istream& operator>>(istream &in, Term &term)
{
    char c;
    bool negative = false;
    // read until we find the first coefficient
    while (true)
    {
        // check the next character
        c = in.peek();
        // throw an error if we get to the end of the file
        if (in.eof())
            throw TermException("No input to read term from");
        // set negative if we find a minus sign
        if (c == '-')
            negative = !negative;
        // consume the character if it's before the coefficient
        if (c == ' ' || c == '+' || c == '-')
            in >> c;
        // break if it's part of the coefficient
        else
            break;
    }

    // read the coefficient
    in >> term.m_coefficient;
    // we failed to read a number, assume that the coefficient is 1 and move to reading the variable
    if (in.fail())
    {
        term.m_coefficient = 1;
        in.clear();
    }
    // make it negative if we found a minus sign
    if (negative)
        term.m_coefficient *= -1;

    // set the exponent and variable for the term
    term.m_exponent = 1;
    term.m_variable.clear();
    // read the variable component of the term
    while(true)
    {
        // check the next character
        c = in.peek();
        // stop if we find eof, this is still valid since we can have just a coefficient with an implied exponent
        if (in.eof())
        {
            if (term.m_variable.size() == 0)
                term.m_exponent = 0;
            return in;
        }
        // we found the start of another term, return
        if (c == '-' || c == '+' || c == ' ')
            return in;
        // consume the character
        in >> c;
        // we found the carrot, break
        if (c == '^')
            break;
        // add the character to the term's variable section
        term.m_variable += c;
    }

    // read the exponent
    in >> term.m_exponent;
    // we failed to read a number, throw an exception
    if (in.fail())
        throw TermException("Unexpected character");

    return in;
}

