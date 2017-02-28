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

    bool operator<(const Term &other) const;
    bool operator>(const Term &other) const;
    bool operator==(const Term &other) const;

    bool isNegative() const { return m_coefficient < 0; };
    bool isZero() const { return m_coefficient == 0; };
    std::string getVariable() const { return m_variable; };
    int getCoefficient() const { return m_coefficient; };
    int getExponent() const { return m_exponent; };
};

#endif
