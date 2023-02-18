#include "Vet.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

Vet::Vet(string fname, string lname, int empNum, double numVac) : Employee(fname, lname, empNum){
	numVaccines = numVac;
}

Vet::Vet(Vet& other) : Employee(other){
	numVaccines = other.numVaccines;
}

Vet::~Vet() {

}

double Vet::calcWeeklyPay() {
	double paySum = 800.00;
	paySum += 3.75 * getNumVac();
	return paySum;
}

string Vet::toString() {
	stringstream myStringStream;
	myStringStream << left << getEmpNum() << " " << getFname() << " " << getLname() << right << setw(10) << fixed << setprecision(2)
		<< calcWeeklyPay() << endl;
	string myString = myStringStream.str();
	return myString;
}

string Vet::getFname() {
	return Employee::getFname();
}

string Vet::getLname() {
	return Employee::getLname();
}

int Vet::getEmpNum() {
	return Employee::getEmpNum();
}

double Vet::getNumVac() {
	return numVaccines;
}