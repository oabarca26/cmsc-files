#pragma once
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "Employee.h"
#include "Manager.h"
#include "Clerk.h"
#include "Vet.h"
#include "Stylist.h"

using namespace std;
class Employees
{
private:
	vector<Employee*>* workers;
	int numManagers, numClerks, numVets, numStylists;

public:
	Employees();
	~Employees();
	Employees(const Employees& other);
	void addEmployee(string line);
	double calculateWeeklyPay();
	string printReport();
	int getNumManagers() { return numManagers; }
	int getNumClerks() { return numClerks; }
	int getNumStylists() { return numStylists; }
	int getNumVets() { return numVets; }
	Employee* getFirst() { return workers->at(0); }
	Employees& operator=(const Employees& other);
	bool static compareEmployees(const Employee* left, const Employee* right) {
		return(*left < *right);
	}

};
#pragma once
