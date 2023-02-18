#pragma once
#include "Employee.h"
class Clerk : public Employee
{
private:
	double wage;
	int hours;

public:
	Clerk(string fname, string lname, int empNum, double w, int h);
	Clerk(Clerk& other);
	~Clerk();
	Clerk* clone() {
		return new Clerk(*this);
	}
	double calcWeeklyPay();
	string toString();
	string getFname();
	string getLname();
	int getEmpNum();
	double getWage();
	int getHours();
};
#pragma once
