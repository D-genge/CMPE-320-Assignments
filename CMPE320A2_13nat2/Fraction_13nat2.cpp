#include "Fraction_13nat2.h"
#include <iostream>
#include <string>
using namespace std;



FractionException::FractionException(const string& message) : message(message) {}
string& FractionException::what() { return message; }

Fraction::Fraction() {
	_numerator = 0;
	_denominator = 1;
}

Fraction::Fraction(int num) {
	_numerator = num;
	_denominator = 1;
}

Fraction::Fraction(int num, int denom) {
	if (denom <= 0){
		throw FractionException ("Please give a number greater than 0.");
	}
	//simplify fraction by dividing numerator and denominator by gcd
	int gcd_frac = gcd(num, denom);
	_numerator = num/gcd_frac;
	_denominator = denom/gcd_frac;
}


//function to find greatest common divisor taken from: https://www.tutorialspoint.com/cplusplus-program-to-find-gcd
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
// Function to return LCM of two numbers:https://www.geeksforgeeks.org/program-to-find-lcm-of-two-numbers/
int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

//to simplify a fraction, divide the numerator and denominator by the GCD
Fraction simplify(const Fraction& value) {
	int gcd_frac = gcd(value._denominator, value._denominator);
	return Fraction(value._numerator / gcd_frac, value._denominator / gcd_frac);
}


// Pre-increment
Fraction& Fraction::operator++() {
	_numerator = _numerator + _denominator;
	return *this;
}

//post-increment
Fraction Fraction::operator++(int unused) {
	Fraction clone(_numerator, _denominator);
	_numerator = _numerator + _denominator; //increment the original variable by 1 by adding the denominator
	return clone; //return the clone
}

//unary negation (-#)
Fraction& Fraction::operator-() {
	_numerator = -_numerator;
	return *this;
}

Fraction& Fraction::operator+=(const Fraction& right) {
	//make sure the denominators are the same with LCM
	//simplify to same denominator
	int lcm_denom = lcm(_denominator, right._denominator);
	//divide lcm denominator by orig. denominator and save to variable
	int self_mult = lcm_denom / _denominator;
	int right_mult = lcm_denom / right._denominator;
	_numerator = _numerator*self_mult + right._numerator*right_mult;
	_denominator = lcm_denom;
	return *this;
}


//+, -, *, /
Fraction operator+(const Fraction& left, const Fraction& right) {
	//make sure the denominators are the same with LCM
	//simplify to same denominator
	int lcm_denom = lcm(left._denominator, right._denominator);
	//divide lcm denominator by orig. denominator and save to variable
	int left_mult = lcm_denom / left._denominator;
	int right_mult = lcm_denom / right._denominator;

	return simplify(Fraction(left._numerator*left_mult+right._numerator*right_mult, lcm_denom));

}

Fraction operator-(const Fraction& left, const Fraction& right) {
	//make sure the denominators are the same with LCM
	//simplify to same denominator
	int lcm_denom = lcm(left._denominator, right._denominator);
	//divide lcm denominator by orig. denominator and save to variable
	int left_mult = lcm_denom / left._denominator;
	int right_mult = lcm_denom / right._denominator;

	return simplify(Fraction(left._numerator * left_mult - right._numerator * right_mult, lcm_denom));


}

Fraction operator/(const Fraction& left, const Fraction& right) {
	//to divide a fraction, multiply by reciprocal
	return simplify(Fraction(left._numerator*right._denominator, left._denominator*right._numerator));


}

Fraction operator*(const Fraction& left, const Fraction& right) {
	return simplify(Fraction(left._numerator*right._numerator, left._denominator*right._denominator));

}

ostream& operator<<(ostream& out, const Fraction& value) {
	out << "[" << value._numerator << "/" << value._denominator << "]";
	return out;
}

istream& operator>>(istream& in, const Fraction& value) {
	in >> value._numerator >> value._denominator;
	return in;
}

//==, !=, >, <
bool operator==(const Fraction& left, const Fraction& right) {
	//two fractions are equal if they simplify to the same fraction
	if (left._denominator == right._denominator) {
		return (left._numerator == right._denominator);
	}
	else {

		//simplify to same denominator
		int lcm_denom = lcm(left._denominator, right._denominator);
		//divide lcm denominator by orig. denominator and save to variable
		int left_mult = lcm_denom / left._denominator;
		int right_mult = lcm_denom / right._denominator;
		return (left._numerator * left_mult == right._numerator * right_mult);
	}
	}

bool operator!=(const Fraction& left, const Fraction& right) {
	return (!(left == right));
}

bool operator>(const Fraction& left, const Fraction& right) {

	return (left._numerator * lcm(left._denominator, right._denominator) / left._denominator) > (right._numerator * lcm(left._denominator, right._denominator) / right._denominator);


}

bool operator>=(const Fraction& left, const Fraction& right) {

	return (left._numerator * lcm(left._denominator, right._denominator) / left._denominator) >= (right._numerator * lcm(left._denominator, right._denominator) / right._denominator);

}

bool operator<=(const Fraction& left, const Fraction& right) {

	return (left._numerator * lcm(left._denominator, right._denominator) / left._denominator) <= (right._numerator * lcm(left._denominator, right._denominator) / right._denominator);

}

bool operator<(const Fraction& left, const Fraction& right) {

	return (left._numerator * lcm(left._denominator, right._denominator) / left._denominator) < (right._numerator * lcm(left._denominator, right._denominator) / right._denominator);
}

int main() {

} 
