#include "Employees.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

Employees::Employees() {
	workers = new vector<Employee*>;
	numManagers = 0;
	numClerks = 0;
	numVets = 0;
	numStylists = 0;
}

Employees:: ~Employees() {
	
}

Employees::Employees(const Employees& other) {
	workers = new vector<Employee*>;
	numManagers = other.numManagers;
	numClerks = other.numClerks;
	numVets = other.numVets;
	numStylists = other.numStylists;
}

void Employees::addEmployee(string line) {
	string first;
	string last;
	int empNum;
	int empCode;
	int hours;
	int numApp;
	double numVac;
	double pay;
	double salary;
	double wage;
	stringstream myStringStream(line);

	myStringStream >> empCode;

		if (empCode == 1) {
			myStringStream >> first >> last >> empNum >> salary;
			Manager* managerPtr = new Manager(first, last, empNum, salary);
			workers->push_back(managerPtr);
			numManagers++;
		}
		if (empCode == 2) {
			myStringStream >> first >> last >> empNum >> wage >> hours;
			Clerk* clerkPtr = new Clerk(first, last, empNum, wage, hours);
			workers->push_back(clerkPtr);
			numClerks++;
		}
		if (empCode == 3) {
			myStringStream >> first >> last >> empNum >> numVac;
			Vet* vetPtr = new Vet(first, last, empNum, numVac);
			workers->push_back(vetPtr);
			numVets++;
		}
		if (empCode == 4) {
			myStringStream >> first >> last >> empNum >> pay >> numApp;
			Stylist* stylistPtr = new Stylist(first, last, empNum, pay, numApp);
			workers->push_back(stylistPtr);
			numStylists++;
		}
}

double Employees::calculateWeeklyPay() {
	unsigned int i;
	double totalSum = 0.00;
	for (i = 0; i < workers->size(); i++) {
		totalSum = totalSum + workers->at(i)->calcWeeklyPay();
	}
	return totalSum;
}

string Employees::printReport() {
	stringstream myStringStream;
	unsigned int i;
	sort(workers->begin(), workers->end(), compareEmployees);
	myStringStream << "Weekly Pay Report for Pete's Pets" << endl << left << setw(25) << "Employee" << right << setw(10) << "Weekly Pay" << endl;
	
	for (i = 0; i < workers->size(); i++) {
		myStringStream << workers->at(i)->toString();
	}

	myStringStream <<"Total payroll : " << fixed << setprecision(2) << calculateWeeklyPay() << endl << "Managers : " << getNumManagers() << endl
		<< "Clerks : " << getNumClerks() << endl << "Vets : " << getNumVets() << endl << "Stylist : " << getNumStylists() << endl;

	string myString = myStringStream.str();
	return myString;
}

Employees& Employees::operator=(const Employees& other) {
	numManagers = other.numManagers;
	numClerks = other.numClerks;
	numVets = other.numVets;
	numStylists = other.numStylists;
	return (*this);
}


// to sort the vector by Employee Number using the compareEmployees function
// sort(vectorName->begin(), vectorName->end(), compareEmployees);