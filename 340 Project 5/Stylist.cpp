#include "Stylist.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

Stylist::Stylist(string fname, string lname, int empNum, double pay, int num) : Employee(fname, lname, empNum) {
	payrate = pay;
	numAppts = num;
}

Stylist::Stylist(Stylist& other) : Employee(other) {
	payrate = other.payrate;
	numAppts = other.numAppts;
}

Stylist::~Stylist() {

}

double Stylist::calcWeeklyPay() {
	double paySum;
	paySum = getPay() * getNumAppts();
	return paySum;
}

string Stylist::toString() {
	stringstream myStringStream;
	myStringStream << left << getEmpNum() << " " << getFname() << " " << getLname() << right << setw(10) << fixed << setprecision(2)
		<< calcWeeklyPay() << endl;
	string myString = myStringStream.str();
	return myString;
}

string Stylist::getFname() {
	return Employee::getFname();
}

string Stylist::getLname() {
	return Employee::getLname();
}

int Stylist::getEmpNum() {
	return Employee::getEmpNum();
}

double Stylist::getPay() {
	return payrate;
}

int Stylist::getNumAppts() {
	return numAppts;
}