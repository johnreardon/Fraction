// FractionTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
	cout << "Test 0 denominator exception" << endl;
	try {
		Fraction err(1, 0);
	}
	catch (invalid_argument e)
	{
		cout << "Caught invalid argument exception. Error: " << e.what() << endl;
	}

	cout << "Test Add" << endl;
	Fraction add1(1, 2);
	Fraction add2(1, 3);
	cout << add1 + add2 << endl;

	add1 += add2;
	cout << add1 << endl;

	cout << "Test Subtract" << endl;
	Fraction sub1(1, 2);
	Fraction sub2(1, 4);
	cout << sub1 - sub2 << endl;
	cout << sub1 - sub2 << endl;

	sub1 -= sub2;
	cout << sub1 << endl;

	cout << "Test Multiply" << endl;
	Fraction m1(1, 2);
	Fraction m2(3, 8);
	cout << m1 * m2 << endl;

	m1 *= m2;
	cout << m1 << endl;
	
	cout << "Test Divide" << endl;
	Fraction d1(1, 2);
	Fraction d2(3, 8);
	cout << d1 / d2 << endl;

	d1 /= d2;
	cout << d1 << endl;

	cout << "Test Eqaulity/Non-Equality" << endl;
	Fraction e1(1, 3);
	Fraction e2(4, 12);
	cout << ((e1 == e2) ? "Equal":"NotEqual") << endl;
	cout << ((e1 != e2) ? "NotEqual" : "Equal") << endl;

	Fraction e3(4, 9);
	Fraction e4(5, 11);
	cout << ((e3 == e4) ? "Equal":"NotEqual") << endl;
	cout << ((e3 != e4) ? "NotEqual" : "Equal") << endl;

	cout << "Test Less Than" << endl;
	Fraction lt1(1, 3);
	Fraction lt2(2, 3);
	cout << ((lt1 < lt2) ? "Less Than" : "Greater Than") << endl;
	cout << ((lt1 > lt2) ? "Greater Than" : "Less Than") << endl;

	cout << "Test Greater Than" << endl;
	Fraction gt1(2, 3);
	Fraction gt2(1, 3);
	cout << ((gt1 < gt2) ? "Less Than" : "Greater Than") << endl;
	cout << ((gt1 > gt2) ? "Greater Than" : "Less Than") << endl;


	cout << "Test Casts" << endl;
	Fraction cst1(2, 3);
	Fraction cst2(1, 10);
	cout << ((double)cst1) << endl;
	cout << ((float)cst1) << endl;
	cout << ((double)cst2) << endl;
	cout << ((float)cst2) << endl;

	double dres = 1.15 + (double)cst2;
	cout << dres << endl;

	cout << "Test AsDouble" << endl;
	Fraction asD(7, 8);
	cout << asD.AsDouble() << endl;

	cout << "Test AsString()" << endl;
	cout << asD.AsString() << endl;

    return 0;
}

