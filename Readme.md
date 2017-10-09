#  Fraction Sample Code

### Class Fraction supports

* +, -, *, /
* +=, -=, *=, /=
* ==, !=
* <, >
* cast to double (double)
* AsDouble()
* Display via cout << and AsString()

### Fraction::IsDoubleEqual()

Comparing doubles directly using == is prone to false negatives due to the internal representations of float/doubles.  I believe there are better implementations that abs( a - b) < DBL_EPSILON but for simplicity and time I used this equality check.
