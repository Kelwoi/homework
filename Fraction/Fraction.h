#pragma once
#include <iostream>
using namespace std;
class fraction {
private:
	int numerator;
	int Denominator;
public:
	fraction()
	{
	}
	fraction(const int& numerator) {
		set_numerator(numerator);
	}
	void set_numerator(const int& numerator) {
		this->numerator = numerator;
	}
	void set_denominator(const int& denominator) {
		this->Denominator = denominator;
	}
	fraction(const int& numerator, const int& denominator) {
		set_numerator(numerator);
		set_denominator(denominator);
	}
	fraction simplify() {
		if (numerator % 3 == 0 and Denominator % 3 == 0) {
		numerator /= 3;
		Denominator /= 3;
		return fraction (numerator, Denominator);
	}
	else if (numerator % 2 == 0 and Denominator % 2 == 0) {
		numerator /= 2;
		Denominator /= 2;
		return (numerator, Denominator);
	}

	}
	void print() {
		cout << this->numerator << endl;
		cout << "-" << endl;
		cout << this->Denominator << endl;
	}
	fraction operator + (const fraction& other) {
		if (Denominator == other.Denominator) {
			int num = numerator + other.numerator;
			int denom = Denominator;
			return fraction(num, denom);
		}
		else {

			int common_denom = Denominator * other.Denominator;
			int num = numerator * other.Denominator + other.numerator * Denominator;
			return fraction(num, common_denom);
		}

	}
	fraction operator - (const fraction& other) {
		if (Denominator == other.Denominator) {
			int num = numerator - other.numerator;
			int denom = Denominator;
			return fraction(num, denom);

		}
		else {

			int common_denom = Denominator * other.Denominator;
			int num = numerator * other.Denominator - other.numerator * Denominator;
			return fraction(num, common_denom);
		}
	}
	fraction operator * (const fraction& other) {
		int num = numerator * other.numerator;
		int denom = Denominator * other.Denominator;
		return fraction(num, denom);
	}
	fraction operator / (fraction& other)  {
		if (Denominator != other.Denominator) {
			int temp = other.numerator;
			other.numerator = other.Denominator;
			other.Denominator = temp;
		}
		int num = numerator * other.numerator;
		int denom = Denominator * other.Denominator;
		return fraction(num, denom);

	}
};
