#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Fraction
{
private:
	int numerator;
	int denominator;

public:
	//default constructor
	Fraction();
	//parameterized constructor
	Fraction(int numerator, int denominator);
	//copy constructor
	Fraction(const Fraction& number);
	//conversion constructor
	//first element is numerator, second is denominator
	Fraction(vector<int> number);

	//destructor
	~Fraction();

	//returns false if a numerator and denominator were entered (numerator != 0 || denominator != 1), 
	//returns true if default then no numerator or denominator were entered
	bool isDefault() const;

	//returns string representative of fraction
	//if numerator = 4 and denominator = 5, returns "4/5"
	string toString() const;

	//These functions are used for testing.
	void setFraction(int numerator, int denominator);
	int getNumerator() const;
	int getDenominator() const;
	vector<int> getFraction();

	//Operators
	Fraction operator+(const Fraction rhs);
	Fraction operator-(const Fraction rhs);
	Fraction operator*(const Fraction rhs);
	Fraction operator/(const Fraction rhs);
	bool operator==(const Fraction& rhs);
	Fraction& operator=(const Fraction& rhs);
	bool operator<(const Fraction& rhs);

	//friends functions for insertion and extraction operator
	friend ostream& operator<<(ostream& out, const Fraction number);
	friend istream& operator>>(istream& in, Fraction& number);

};