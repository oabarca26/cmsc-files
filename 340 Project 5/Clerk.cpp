#include "Clerk.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

Clerk::Clerk(string fname, string lname, int empNum, double w, int h) : Employee(fname, lname, empNum) {
	wage = w;
	hours = h;
}

Clerk::Clerk(Clerk& other) : Employee(other) {
	wage = other.wage;
	hours = other.hours;
}

Clerk::~Clerk() {

}
//8.75 35             12.50 50
double Clerk::calcWeeklyPay() {
	double paySum = 0.0;
	int overtimeHours;
	double overtimeWage;

	if (getHours() > 40) {
		paySum = getWage() * 40;
		overtimeHours = getHours() - 40;
		overtimeWage = overtimeHours * (getWage() * 1.5);
		paySum += overtimeWage;
	}
	else {
		paySum = getWage() * getHours();
	}

	return paySum;
}

string Clerk::toString() {
	stringstream myStringStream;
	myStringStream << left << getEmpNum() << " " << getFname() << " " << getLname() << right << setw(10) << fixed << setprecision(2)
		<< calcWeeklyPay() << endl;
	string myString = myStringStream.str();
	return myString;
}

string Clerk::getFname() {
	return Employee::getFname();
}

string Clerk::getLname() {
	return Employee::getLname();
}

int Clerk::getEmpNum() {
	return Employee::getEmpNum();
}

double Clerk::getWage() {
	return wage;
}

int Clerk::getHours() {
	return hours;
}