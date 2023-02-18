#include "Employees.h"
#include "Employee.h"
#include "Manager.h"
#include "Clerk.h"
#include "Vet.h"
#include "Stylist.h"
#include <iostream>
#include <fstream>
using namespace std;

bool testPassedClerkNoOvertime() {
    Employees employees;
    Employee* employee;
    Clerk* clerk;
    int numClerks, empNum;
    string line, result, fname, lname;
    //istringstream iSS, lineSS;
    double pay;

    numClerks = employees.getNumClerks();
    cout << "Number of clerks before add: " << numClerks << endl;
    employees.addEmployee("2 Patrick Brown 22222 12.50 40");
    cout << "addEmployee(\"2 Patrick Brown 22222 12.50 40\")" << endl;
    numClerks = employees.getNumClerks();
    cout << "Number of clerks after add: " << numClerks << endl;

    if (numClerks == 1) {
        employee = employees.getFirst();
        clerk = static_cast<Clerk*>(employee);
        pay = clerk->calcWeeklyPay();
        empNum = clerk->getEmpNum();
        lname = clerk->getLname();
        fname = clerk->getFname();

        if (pay - 500.00 < .01) {
            if (fname.compare("Patrick") == 0) {
                if (lname.compare("Brown") == 0) {
                    if (empNum == 22222) {
                        cout << "22222 Patrick Brown 500.00. Correctly added a clerk object" << endl;
                        return true;
                    }
                    else {
                        cout << "employee number should have been 22222. Yours was " << empNum << endl;
                        return false;
                    }
                }
                else {
                    cout << "last name should have been Brown. Yours was " << lname << endl;
                    return false;
                }
            }
            else {
                cout << "first name should have been Patrick. Yours was " << fname << endl;
                return false;
            }
        }
        else {
            cout << "Pay should have been 500.00. Your pay was " << pay << ". Pay is not calculated correctly" << endl;
            return false;
        }
    }

    else {
        cout << "Clerk object not added correctly or number of clerks was not updated correctly" << endl;

        return false;
    }
}

bool testPassedClerkOvertime() {
    Employees employees;
    Employee* employee;
    Clerk* clerk;
    int numClerks, empNum;
    string line, result, fname, lname;
    //istringstream iSS, lineSS;
    double pay;

    numClerks = employees.getNumClerks();
    cout << "Number of clerks before add: " << numClerks << endl;
    employees.addEmployee("2 Patrick Brown 22222 12.50 50");
    cout << "addEmployee(\"2 Patrick Brown 22222 12.50 50\")" << endl;
    numClerks = employees.getNumClerks();
    cout << "Number of clerks after add: " << numClerks << endl;

    if (numClerks == 1) {
        employee = employees.getFirst();
        clerk = static_cast<Clerk*>(employee);
        pay = clerk->calcWeeklyPay();
        empNum = clerk->getEmpNum();
        lname = clerk->getLname();
        fname = clerk->getFname();
        if (pay - 687.50 < .01) {
            if (fname.compare("Patrick") == 0) {
                if (lname.compare("Brown") == 0) {
                    if (empNum == 22222) {
                        cout << "22222 Patrick Brown 687.50. Correctly added a clerk object" << endl;
                        return true;
                    }
                    else {
                        cout << "employee number should have been 22222. Yours was " << empNum << endl;
                        return false;
                    }
                }
                else {
                    cout << "last name should have been Brown. Yours was " << lname << endl;
                    return false;
                }
            }
            else {
                cout << "first name should have been Patrick. Yours was " << fname << endl;
                return false;
            }
        }
        else {
            cout << "Pay should have been 687.50. Your pay was " << pay << ". Pay is not calculated correctly (don't forget about overtime)" << endl;
            return false;
        }
    }

    else {
        cout << "Clerk object not added correctly or number of clerks was not updated correctly" << endl;

        return false;
    }
}

bool testPassedManager() {
    Employees employees;
    Employee* emp;
    Manager* employee;
    int numManagers, empNum;
    string line, result, fname, lname;
    //istringstream iSS, lineSS;
    double pay;

    numManagers = employees.getNumManagers();
    cout << "Number of managers before add: " << numManagers << endl;
    employees.addEmployee("1 Eric Hall 11111 1200.00");
    cout << "addEmployee(\"1 Eric Hall 11111 1200.00\")" << endl;
    numManagers = employees.getNumManagers();
    cout << "Number of manager after add: " << numManagers << endl;

    if (numManagers == 1) {
        emp = employees.getFirst();
        employee = static_cast<Manager*>(emp);
        pay = employee->calcWeeklyPay();
        empNum = employee->getEmpNum();
        lname = employee->getLname();
        fname = employee->getFname();
        if (pay - 1200.00 < .01) {
            if (fname.compare("Eric") == 0) {
                if (lname.compare("Hall") == 0) {
                    if (empNum == 11111) {
                        cout << "11111 Eric Hall 1200.00. Correctly added a clerk object" << endl;
                        return true;
                    }
                    else {
                        cout << "employee number should have been 11111. Yours was " << empNum << endl;
                        return false;
                    }
                }
                else {
                    cout << "last name should have been Hall. Yours was " << lname << endl;
                    return false;
                }
            }
            else {
                cout << "first name should have been Eric. Yours was " << fname << endl;
                return false;
            }
        }
        else {
            cout << "Pay should have been 1200.00. Your pay was " << pay << ". Manager object not added correctly or pay is not calculated correctly" << endl;
            return false;
        }
    }

    else {
        cout << "Manager object not added correctly or number of managers was not updated correctly" << endl;

        return false;
    }
}

bool testPassedVet() {
    Employees employees;
    Employee* emp;
    Vet* employee;
    int numVets, empNum;
    string line, result, fname, lname;
    //istringstream iSS, lineSS;
    double pay;

    numVets = employees.getNumVets();
    cout << "Number of vets before add: " << numVets << endl;
    employees.addEmployee("3 Katie Bell 33333 55");
    cout << "addEmployee(\"3 Katie Bell 33333 55\")" << endl;
    numVets = employees.getNumVets();
    cout << "Number of vets after add: " << numVets << endl;

    if (numVets == 1) {
        emp = employees.getFirst();
        employee = static_cast<Vet*>(emp);
        pay = employee->calcWeeklyPay();
        empNum = employee->getEmpNum();
        lname = employee->getLname();
        fname = employee->getFname();
        if (pay - 1006.25 < .01) {
            if (fname.compare("Katie") == 0) {
                if (lname.compare("Bell") == 0) {
                    if (empNum == 33333) {
                        cout << "33333 Katie Bell 1006.25 Correctly added a vet object" << endl;
                        return true;
                    }
                    else {
                        cout << "employee number should have been 33333. Yours was " << empNum << endl;
                        return false;
                    }
                }
                else {
                    cout << "last name should have been Bell. Yours was " << lname << endl;
                    return false;
                }
            }
            else {
                cout << "first name should have been Katie. Yours was " << fname << endl;
                return false;
            }
        }
        else {
            cout << "Pay should have been 1006.25. Your pay was " << pay << ". Vet object not added correctly or pay is not calculated correctly" << endl;
            return false;
        }
    }

    else {
        cout << "Vet object not added correctly or number of vets was not updated correctly" << endl;

        return false;
    }
}

bool testPassedStylist() {
    Employees employees;
    Employee* emp;
    Stylist* employee;
    int numStylists, empNum;
    string line, result, fname, lname;
    //istringstream iSS, lineSS;
    double pay;

    numStylists = employees.getNumStylists();
    cout << "Number of Stylists before add: " << numStylists << endl;
    employees.addEmployee("4 Paul Johnson 44444 8.75 75");
    cout << "addEmployee(\"4 Paul Johnson 44444 8.75 75\")" << endl;
    numStylists = employees.getNumStylists();
    cout << "Number of Stylists after add: " << numStylists << endl;

    if (numStylists == 1) {
        emp = employees.getFirst();
        employee = static_cast<Stylist*>(emp);
        pay = employee->calcWeeklyPay();
        empNum = employee->getEmpNum();
        lname = employee->getLname();
        fname = employee->getFname();
        if (pay - 656.25 < .01) {
            if (fname.compare("Paul") == 0) {
                if (lname.compare("Johnson") == 0) {
                    if (empNum == 44444) {
                        cout << "44444 Paul Johnson 656.25 Correctly added a Stylist object" << endl;
                        return true;
                    }
                    else {
                        cout << "employee number should have been 44444. Yours was " << empNum << endl;
                        return false;
                    }
                }
                else {
                    cout << "last name should have been Johnson. Yours was " << lname << endl;
                    return false;
                }
            }
            else {
                cout << "first name should have been Paul. Yours was " << fname << endl;
                return false;
            }
        }
        else {
            cout << "Pay should have been 656.25. Your pay was " << pay << ". Stylist object not added correctly or pay is not calculated correctly" << endl;
            return false;
        }
    }

    else {
        cout << "Stylist object not added correctly or number of vets was not updated correctly" << endl;

        return false;
    }
}

bool testPassedCalcWeeklyPay() {
    Employees employees;
    string line, result, fname, lname;
    //istringstream iSS, lineSS;
    double pay;

    cout << "adding the following employees;" << endl;
    cout << "addEmployee(\"4 Paul Johnson 44444 8.75 75\")" << endl;
    cout << "addEmployee(\"1 Eric Hall 11111 1200.00\")" << endl;
    cout << "addEmployee(\"3 Katie Bell 33333 55\")" << endl;
    cout << "addEmployee(\"2 Patrick Brown 22222 12.50 50\")" << endl;

    employees.addEmployee("4 Paul Johnson 44444 8.75 75");
    employees.addEmployee("1 Eric Hall 11111 1200.00");
    employees.addEmployee("3 Katie Bell 33333 55");
    employees.addEmployee("2 Patrick Brown 22222 12.50 50");

    pay = employees.calculateWeeklyPay();

    if (pay - 3550.00 < .01) {
        cout << "Total Weekly Pay of 3500.00 was calculated correctly" << endl;
        return true;
    }

    else {
        cout << "Total Weekly Pay should have been 3550.00. Yours was " << pay << endl;
        return false;
    }
}

bool testPassedCopyconstructor() {
    Employees employees, employees2;
    string line, result, fname, lname;
    //istringstream iSS, lineSS;
    double pay, pay2;

    cout << "adding the following employees to Employees object employees;" << endl;
    cout << "addEmployee(\"4 Paul Johnson 44444 8.75 75\")" << endl;
    cout << "addEmployee(\"1 Eric Hall 11111 1200.00\")" << endl;
    cout << "addEmployee(\"3 Katie Bell 33333 55\")" << endl;
    cout << "addEmployee(\"2 Patrick Brown 22222 12.50 50\")" << endl;

    employees.addEmployee("4 Paul Johnson 44444 8.75 75");
    employees.addEmployee("1 Eric Hall 11111 1200.00");
    employees.addEmployee("3 Katie Bell 33333 55");
    employees.addEmployee("2 Patrick Brown 22222 12.50 50");

    pay = employees.calculateWeeklyPay();

    if (pay - 3550.00 < .01) {
        cout << "Total Weekly Pay of 3500.00 for employees was calculated correctly" << endl << endl;
        cout << "Creating new Employees object: Employees employees2(employees)" << endl;
        Employees employees2(employees);
        cout << "employees2.addEmployee(\"2 Georgia Jones 10111 12.50 40\")" << endl;
        employees2.addEmployee("2 Georgia Jones 10111 12.50 40");
        cout << "employees2.calculateWeeklyPay()" << endl;
        pay2 = employees2.calculateWeeklyPay();
        pay = employees.calculateWeeklyPay();
        cout << "workers" << endl;

        if (((pay2 - 4050.00) < .01) && ((pay - 3550.00) < .01)) {
            cout << "Copy Constructor working correctly, total Weekly Pay for employees2 = 4050.00\n"
                << "and total Weekly Pay for employees is still 3500.00" << endl;
            return true;
        }
        else {
            cout << "Total Weekly Pay should have been 4050.00. Yours was " << pay << endl;
            return false;
        }
    }

    else {
        cout << "Total Weekly Pay should have been 3550.00. Yours was " << pay << endl;
        return false;
    }
}

bool testPassedEquals() {
    Employees employees, employees3;
    string line, result, fname, lname;
    //istringstream iSS, lineSS;
    double pay, pay3;

    cout << "adding the following employees to Employees object employees;" << endl;
    cout << "addEmployee(\"4 Paul Johnson 44444 8.75 75\")" << endl;
    cout << "addEmployee(\"1 Eric Hall 11111 1200.00\")" << endl;
    cout << "addEmployee(\"3 Katie Bell 33333 55\")" << endl;
    cout << "addEmployee(\"2 Patrick Brown 22222 12.50 50\")" << endl;

    employees.addEmployee("4 Paul Johnson 44444 8.75 75");
    employees.addEmployee("1 Eric Hall 11111 1200.00");
    employees.addEmployee("3 Katie Bell 33333 55");
    employees.addEmployee("2 Patrick Brown 22222 12.50 50");

    pay = employees.calculateWeeklyPay();

    if (pay - 3550.00 < .01) {
        cout << "Total Weekly Pay of 3500.00 for employees was calculated correctly" << endl << endl;;
        cout << "Using assignment operator: employees3 = employees" << endl;
        employees3 = employees;
        cout << "employees3.addEmployee(\"2 Georgia Jones 10111 13.50 40\")" << endl;
        employees3.addEmployee("2 Georgia Jones 10111 13.50 40");
        cout << "employees3.calculateWeeklyPay()" << endl;
        pay3 = employees3.calculateWeeklyPay();
        pay = employees.calculateWeeklyPay();
        if (((pay3 - 4090.00) < .01) && ((pay - 3550.00) < .01)) {
            cout << "Operator= working correctly, total Weekly Pay for employees3 = 4090.00\n"
                "and total Weekly Pay for employees is still 3500.00" << endl;
            return true;
        }
        else {
            cout << "Total Weekly Pay should have been 4090.00. Yours was " << pay3
                << "\n or total weekly pay for employeees should have been 3550.00. Your was " << pay << endl;
            return false;
        }
    }

    else {
        cout << "Total Weekly Pay should have been 3550.00. Yours was " << pay << endl;
        return false;
    }
}

bool testPassedPrintReportEmployee() {
    Employees employees;

    ifstream in;
    string line;
    string fileName = "employees.txt";
    string result;
    char result1[80];
    int empNum;
    double total;

    in.open(fileName);
    if (!in) {
        cout << "Could not open file: " << fileName << endl;
        return false;
    }

    //read a line and add to employees
    while (!in.eof()) {
        getline(in, line);
        employees.addEmployee(line);
    }
    //report
    istringstream inp(employees.printReport());
    inp.getline(result1, 80, '\n'); //"Weekly Pay Report for Pete's Pets"
    inp.getline(result1, 80, '\n'); //empty line
    inp.getline(result1, 80, '\n'); //"Employee      Weekly Pay"
    inp >> empNum;
    if (empNum != 11111) {
        cout << "First employee number should be 11111, yours was " << empNum << endl;
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp >> empNum;
    if (empNum != 22222) {
        cout << "Second employee number should be 22222, yours was " << empNum << endl;
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp >> empNum;
    if (empNum != 33333) {
        cout << "Third employee number should be 33333, yours was " << empNum << endl;
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp >> empNum;
    if (empNum != 44444) {
        cout << "Fourth employee number should be 44444, yours was " << empNum << endl;
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp.getline(result1, 80, '\n'); //empty line
    inp >> result; //"Total"
    inp >> result; //"payroll"
    inp >> total;
    if (((total - 3550.00) > .01))
    {
        cout << "The total should have been 3500.00, yours was " << total << endl;
        return false;
    }
    inp >> result; //"Managers"
    inp >> total;
    if (total != 1) {
        cout << "The number of Managers should have been 1, yours was " << total << endl;
        return false;
    }
    inp >> result; //"Clerks"

    inp >> total;
    if (total != 1) {
        cout << "The number of Clerks should have been 1, yours was " << total << endl;
        return false;
    }
    inp >> result; //"Vets"
    inp >> total;
    if (total != 1) {
        cout << "The number of Vets should have been 1, yours was " << total << endl;
        return false;
    }
    inp >> result; //"Sylist"
    inp >> total;
    if (total != 1) {
        cout << "The number of Stylist should have been 1, yours was " << total << endl;
        return false;
    }
    return true;

}

bool testPassedPrintReportEmployeeA() {
    Employees employees;

    ifstream in;
    string line;
    string fileName = "employeesA.txt";
    string result;
    char result1[80];
    int empNum;
    double total;

    in.open(fileName);
    if (!in) {
        cout << "Could not open file: " << fileName << endl;
        return false;
    }

    //read a line and add to employees
    while (!in.eof()) {
        getline(in, line);
        employees.addEmployee(line);
    }
    //report
    istringstream inp(employees.printReport());
    inp.getline(result1, 80, '\n'); //"Weekly Pay Report for Pete's Pets"
    inp.getline(result1, 80, '\n'); //empty line
    inp.getline(result1, 80, '\n'); //"Employee      Weekly Pay"
    inp >> empNum;
    if (empNum != 11111) {
        cout << "First employee number should be 11111, yours was " << empNum << endl;
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp >> empNum;
    if (empNum != 12345) {
        cout << "Second employee number should be 12345, yours was " << empNum << endl;
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp >> empNum;
    if (empNum != 22222) {
        cout << "Next employee number should be 22222, yours was " << empNum << endl;
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp >> empNum;
    if (empNum != 23456) {
        cout << "Next employee number should be 23456, yours was " << empNum << endl;
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp >> empNum;
    if (empNum != 33333) {
        cout << "Next employee number should be 33333, yours was " << empNum << endl;
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp >> empNum;
    if (empNum != 34567) {
        cout << "Next employee number should be 34567, yours was " << empNum << endl;
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp >> empNum;
    if (empNum != 44444) {
        cout << "Next employee number should be 44444, yours was " << empNum << endl;
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp >> empNum;
    if (empNum != 45678) {
        cout << "Next employee number should be 45678, yours was " << empNum << endl;
        return false;
    }
    inp.getline(result1, 80, '\n'); //get the rest of the line
    inp.getline(result1, 80, '\n'); //empty line
    inp >> result; //"Total"
    inp >> result; //"payroll"
    inp >> total;
    if (((total - 6193.00) > .01))
    {
        cout << "The total should have been 6193.00, yours was " << total << endl;
        return false;
    }
    inp >> result; //"Managers"
    inp >> total;
    if (total != 1) {
        cout << "The number of Managers should have been 1, yours was " << total << endl;
        return false;
    }
    inp >> result; //"Clerks"

    inp >> total;
    if (total != 2) {
        cout << "The number of Clerks should have been 2, yours was " << total << endl;
        return false;
    }
    inp >> result; //"Vets"
    inp >> total;
    if (total != 3) {
        cout << "The number of Vets should have been 3, yours was " << total << endl;
        return false;
    }
    inp >> result; //"Sylist"
    inp >> total;
    if (total != 2) {
        cout << "The number of Stylist should have been 2, yours was " << total << endl;
        return false;
    }
    return true;

}


int main() {
    bool passed;
    cout << "UNIT TEST - addEmployee clerk no overtime" << endl;
    passed = testPassedClerkNoOvertime();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - addEmployee clerk overtime" << endl;
    passed = testPassedClerkOvertime();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - addEmployee manager" << endl;
    passed = testPassedManager();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - addEmployee vet" << endl;
    passed = testPassedVet();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - addEmployee stylist" << endl;
    passed = testPassedStylist();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - CalcWeeklyPay" << endl;
    passed = testPassedCalcWeeklyPay();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - copy constructor" << endl;
    passed = testPassedCopyconstructor();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - Equals Operator" << endl;
    passed = testPassedEquals();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - printReport (employees.txt)" << endl;
    passed = testPassedPrintReportEmployee();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - printReport (employeesA.txt)" << endl;
    passed = testPassedPrintReportEmployeeA();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    return 0;
}

