#include "stdafx.h"
#include "Fraction.h"


Fraction::Fraction(double nNum, double nDen)
{
	if (nDen == 0)
		throw invalid_argument("Denominator cannot be 0");

	m_nNumerator = nNum;
	m_nDenominator = nDen;
}

Fraction Fraction::operator+(const Fraction& rh) const
{
	double Num1 = GetNumerator() * rh.GetDenominator();
	double Num2 = rh.GetNumerator() * GetDenominator();
	double GCD = GetDenominator() * rh.GetDenominator();
	return Fraction(Num1 + Num2, GCD);
}

Fraction Fraction::operator+=(const Fraction& rh)
{
	m_nNumerator = (GetNumerator() * rh.GetDenominator()) + (rh.GetNumerator() * GetDenominator());
	m_nDenominator = GetDenominator() * rh.GetDenominator();
	return *this;
}

Fraction Fraction::operator-(const Fraction& rh) const
{
	double Num1 = GetNumerator() * rh.GetDenominator();
	double Num2 = rh.GetNumerator() * GetDenominator();
	double GCD = GetDenominator() * rh.GetDenominator();
	return Fraction(Num1 - Num2, GCD);
}

Fraction Fraction::operator-=(const Fraction& rh)
{
	m_nNumerator = (GetNumerator() * rh.GetDenominator()) - (rh.GetNumerator() * GetDenominator());
	m_nDenominator = GetDenominator() * rh.GetDenominator();
	return *this;

}

Fraction Fraction::operator*(const Fraction& rh) const
{
	return Fraction(GetNumerator() * rh.GetNumerator(), GetDenominator() * rh.GetDenominator());
}

Fraction Fraction::operator*=(const Fraction& rh)
{
	m_nNumerator *= rh.GetNumerator();
	m_nDenominator *= rh.GetDenominator();
	return *this;
}

Fraction Fraction::operator/(const Fraction& rh) const
{
	return Fraction(GetNumerator() * rh.GetDenominator(), GetDenominator() * rh.GetNumerator());
}

Fraction Fraction::operator/=(const Fraction& rh)
{
	m_nNumerator *= rh.GetDenominator();
	m_nDenominator *= rh.GetNumerator();
	return *this;
}

bool Fraction::operator==(const Fraction& rh) const
{
	return IsDoubleEqual((GetNumerator() * rh.GetDenominator()),(GetDenominator() * rh.GetNumerator()));
}

bool Fraction::operator<(const Fraction& rh) const
{
	return (GetNumerator() * rh.GetDenominator()) < (GetDenominator() * rh.GetNumerator());

}

bool Fraction::operator>(const Fraction& rh) const
{
	return (GetNumerator() * rh.GetDenominator()) > (GetDenominator() * rh.GetNumerator());

}

ostream& operator<<(ostream& out, const Fraction& rh)
{
	// Handle 0 special case
	if (rh.GetNumerator() == 0)
		return out << "0";

	// Could add more here to return the fraction in the most simplified form
	return out << rh.GetNumerator() << "/" << rh.GetDenominator();
}