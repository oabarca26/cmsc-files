#include <fstream>
#include <iostream>
#include <string>
#include "Employees.h"
using namespace std;


/*int main() {
	Employees employees;

	ifstream in;
	string line;
	string fileName;
	cout << "Filename :";
	getline(cin, fileName);
	in.open(fileName);
	if (!in) {
		cout << "Could not open file: " << fileName << endl;
		exit(0);
	}

	//read a line and add to employees
	while (!in.eof()) {
		getline(in, line);
		employees.addEmployee(line);
	}
	cout << employees.printReport();

	in.close();
}*/