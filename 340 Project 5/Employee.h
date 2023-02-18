#pragma once
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Employee
{
private:
	string firstName, lastName;
	int empNumber;

public:
	Employee(string fname, string lname, int eNum) {
		firstName = fname;
		lastName = lname;
		empNumber = eNum;
	};
	virtual ~Employee() {};
	virtual Employee* clone() = 0;
	virtual double calcWeeklyPay() = 0;
	virtual string toString() {
		ostringstream oSS;
		oSS << empNumber << " " << firstName << " " << lastName;
		return oSS.str();
	}

	int getEmpNum() { return empNumber; }
	string getFname() { return firstName; }
	string getLname() { return lastName; }

	friend bool operator>(const Employee& lhs, const Employee& rhs) {
		if (lhs.empNumber > rhs.empNumber) return true;
		return false;
	}

	friend bool operator<(const Employee& lhs, const Employee& rhs) {
		if (lhs.empNumber < rhs.empNumber) return true;
		return false;
	}

};
#pragma once
