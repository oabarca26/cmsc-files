#pragma once
#include "Employee.h"
class Vet : public Employee
{
private:
	double numVaccines;

	const double basePay = 800.0;
	const double vacPay = 3.75;

public:
	Vet(string fname, string lname, int empNum, double numVac);
	Vet(Vet& other);
	~Vet();
	Vet* clone() { return new Vet(*this); }
	double calcWeeklyPay();
	string toString();
	string getFname();
	string getLname();
	int getEmpNum();
	double getNumVac();
};
#pragma once
