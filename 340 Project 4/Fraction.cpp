#include "Fraction.h"
#include "utilities.h"
#include <numeric>
#include <string>
using namespace std;

//These functions are used for testing.
//setFraction doesn't call simplify
void Fraction::setFraction(int numerator, int denominator) {
	if (denominator != 0) {
		this->numerator = numerator;
		this->denominator = denominator;
	}
	else {
		numerator = 0;
		denominator = 1;
	}
}

int Fraction::getNumerator() const { return numerator; }

int Fraction::getDenominator() const { return denominator; }

//returns a vector with the numberator as the first element and the denominator as the second element
vector<int> Fraction::getFraction() {
	vector<int> result;
	result.push_back(numerator);
	result.push_back(denominator);
	return result;
}

Fraction::Fraction() {
	numerator = 0;
	denominator = 1;
}

Fraction::Fraction(int num, int den) {
	vector<int> result;
	result = simplify(num, den);
	if (den == 0) {
		return;
	}
	else {
		numerator = result[0];
		denominator = result[1];
	}
}

Fraction::Fraction(const Fraction& number) {
	numerator = number.numerator;
	denominator = number.denominator;
}
Fraction::Fraction(vector<int> number) {
	vector<int> result;
	result = simplify(number[0], number[1]);
	numerator = result[0];
	denominator = result[1];
}

Fraction::~Fraction() {

}

bool Fraction::isDefault() const {
	if (numerator != 0 || denominator != 1)
		return false;
	else
		return true;
}

string Fraction::toString() const {
	return to_string(numerator) + "/" + to_string(denominator);
}

Fraction Fraction::operator+(const Fraction rhs) {
	int totalDen = lcm(denominator, rhs.denominator);
	return simplify((((totalDen / denominator) * numerator) + ((totalDen / rhs.denominator) * rhs.numerator)), totalDen);
}

Fraction Fraction::operator-(const Fraction rhs) {
	int totalDen = lcm(denominator, rhs.denominator);
	return simplify((((totalDen / denominator) * numerator) - ((totalDen / rhs.denominator) * rhs.numerator)), totalDen);
}

Fraction& Fraction::operator=(const Fraction& rhs) {
	numerator = rhs.numerator;
	denominator = rhs.denominator;
	return (*this);
}

bool Fraction::operator<(const Fraction& rhs) {
	if (numerator < rhs.numerator) {
		return true;
	}
	if (numerator == rhs.numerator && denominator < rhs.denominator) {
		return true;
	}
	return false;
}

Fraction Fraction::operator*(const Fraction b) {
	return simplify(numerator *= b.numerator, denominator *= b.denominator);
}

Fraction Fraction::operator/(const Fraction b) {
	return simplify(numerator *= b.denominator, denominator *= b.numerator);
}

bool Fraction::operator==(const Fraction& b) {
	vector<int> result;
	result = simplify(numerator, denominator);
	vector<int> resultTwo;
	resultTwo = simplify(b.numerator, b.denominator);
	if (numerator == b.numerator && denominator == b.denominator) {
		return true;
	}
	else if (result[0] == resultTwo[0] && result[1] == resultTwo[1]) {
		return true;
	}
	return false;
}

ostream& operator<<(ostream& out, const Fraction number) {
	if (number.numerator == 0) {
		cout << 0 << endl;
		return out;
	}
	else if (number.numerator == number.denominator) {
		cout << 1 << endl;
		return out;
	}
	else {
		cout << number.numerator << "/" << number.denominator;
		return out;
	}
}

istream& operator>>(istream& in, Fraction& number) {
	in >> number.numerator >> number.denominator;
	return in;
}