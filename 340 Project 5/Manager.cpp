#include "Manager.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

Manager::Manager(string fname, string lname, int empNum, double sal) : Employee(fname, lname, empNum) {
	salary = sal;
}

Manager::Manager(Manager& other) : Employee(other) {
	salary = other.salary;
}

Manager::~Manager() {

}

double Manager::calcWeeklyPay() {
	return getSalary();
}

string Manager::toString() {
	stringstream myStringStream;
	myStringStream << left << getEmpNum() << " " << getFname() << " " << getLname() << right << setw(10) << fixed << setprecision(2)
		<< calcWeeklyPay() << endl;
	string myString = myStringStream.str();
	return myString;
}

string Manager::getFname() {
	return Employee::getFname();
}

string Manager::getLname() {
	return Employee::getLname();
}

int Manager::getEmpNum() {
	return Employee::getEmpNum();
}

double Manager::getSalary() {
	return salary;
}