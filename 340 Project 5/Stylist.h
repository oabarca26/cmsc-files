#pragma once
#include "Employee.h"
class Stylist : public Employee
{
private:
	double payrate;
	int numAppts;

public:
	Stylist(string fname, string lname, int empNum, double pay, int num);
	Stylist(Stylist& other);
	~Stylist();
	Stylist* clone() { return new Stylist(*this); }
	double calcWeeklyPay();
	string toString();
	string getFname();
	string getLname();
	int getEmpNum();
	double getPay();
	int getNumAppts();
};
#pragma once
