#ifndef H_TERM
#define H_TERM

#include <istream>
#include <string>
#include <exception>


class TermException: public std::exception
{
private:
    std::string m_message;

public:
    TermException(std::string message);
    virtual const char* what() const throw() { return m_message.c_str(); };
};


class Term
{
private:
    int m_coefficient;
    int m_exponent;
    std::string m_variable;

    friend std::ostream& operator<<(std::ostream &out, const Term &term);
    friend std::istream& operator>>(std::istream &out, Term &term);

public:
    Term();
    Term(int coefficient, int exponent, std::string variable);

    Term& operator+=(const Term &other);

    bool isNegative() { return m_coefficient < 0; };
    int getCoefficient() { return m_coefficient; };
    int getExponent() { return m_exponent; };
};

#endif
