#pragma once
#include <iostream>
#include <string>
using namespace std;


class Fraction {
	int _numerator, _denominator;
public:
	//declare functions
	Fraction();
	Fraction(int num);
	Fraction(int num, int denom);
	int numerator() { return _numerator; }
	int denominator() { return _denominator; }
	
	

	Fraction& operator++();	
	Fraction  operator++(int);	
	Fraction& operator+=(const Fraction& right);

	Fraction& operator-();

	friend Fraction operator+(const Fraction& left, const Fraction& right);
	friend Fraction operator/(const Fraction& left, const Fraction& right);
	friend Fraction operator*(const Fraction& left, const Fraction& right);
	friend Fraction operator-(const Fraction& left, const Fraction& right);
	friend bool operator==(const Fraction& left, const Fraction& right);
	friend bool operator!=(const Fraction& left, const Fraction& right);
	friend bool operator>(const Fraction& left, const Fraction& right);
	friend bool operator<(const Fraction& left, const Fraction& right);
	friend bool operator>=(const Fraction& left, const Fraction& right);
	friend bool operator<=(const Fraction& left, const Fraction& right);
	friend ostream& operator<<(ostream& out, const Fraction& value);
	friend istream& operator>>(istream& in, const Fraction& value);

	friend Fraction simplify(const Fraction& value);
};


class FractionException {
public:
	FractionException(const string& message);
	string& what();
private:
	string message;

};