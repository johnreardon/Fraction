#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Fraction
{
public:
	Fraction(double lNum, double lDen);

	double GetNumerator() const { return m_nNumerator; }
	double GetDenominator() const { return m_nDenominator; }

	// Add
	Fraction operator+(const Fraction& rh) const;
	Fraction operator+=(const Fraction& rh);

	// Subtract
	Fraction operator-(const Fraction& rh) const;
	Fraction operator-=(const Fraction& rh);

	// Multiply
	Fraction operator*(const Fraction& rh) const;
	Fraction operator*=(const Fraction& rh);

	// Divide
	Fraction operator/(const Fraction& rh) const;
	Fraction operator/=(const Fraction& rh);

	// Equality/Non-Equality
	bool operator==(const Fraction& rh) const;
	bool operator!=(const Fraction& rh) const { return !operator==(rh); }

	// Less/Greater than
	bool operator<(const Fraction& rh) const;
	bool operator>(const Fraction& rh) const;

	// Double cast
	operator double() { return m_nNumerator / m_nDenominator; }

	double AsDouble() { return (double)*this; }

	string AsString() {
		std::ostringstream strs;
		strs << (double)*this;
		return strs.str();
	}

	// Output
	friend ostream& operator<<(ostream& out, const Fraction& rh);
private:
	double m_nNumerator;
	double m_nDenominator;

	// This is not a perfect double comarison but its better than using == directly.
	// We ran into this issue in my current posistion and did a lot of research to determine the best fix.
	bool IsDoubleEqual(double first, double second) const
	{
		if (first == second || abs(first - second) < DBL_EPSILON)
			return true;
		return false;
	}
};

