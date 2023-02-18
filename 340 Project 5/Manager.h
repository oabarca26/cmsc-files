#pragma once
#include "Employee.h"

class Manager : public Employee
{
private:
	double salary;

public:
	Manager(string fname, string lname, int empNum, double sal);
	Manager(Manager& other);
	~Manager();
	Manager* clone() { return new Manager(*this); }
	double calcWeeklyPay();
	string toString();
	string getFname();
	string getLname();
	int getEmpNum();
	double getSalary();
};
#pragma once
