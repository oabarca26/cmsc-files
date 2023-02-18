/*
 * testing.cpp
 *
 *  Created on: Oct 7, 2022
 *      Author: User
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Fraction.h"
using namespace std;


vector<string> split(string resultString, char delimiter) {
    stringstream resultStream(resultString);
    vector<string> result;
    string str, str2;

    while (getline(resultStream, str, delimiter)) {
        result.push_back(str);
    }
    return result;
}

bool testDefaultConstructor() {
    Fraction* testNode = new Fraction();
    cout << "Creating a Fraction with the default constructor\n";
    cout << "Should have values of 0 and 1\n";

    if ((testNode->getNumerator() == 0) &&
        (testNode->getDenominator() == 1)) {

        cout << "Default constructor correctly initialized node and accessors return the correct values." << endl;
        delete testNode;
        return true;
    }

    else {
        cout << "Default constructor incorrectly intialized node and/or accessors did not return the correct values." << endl;
        cout << "getNumerator() returned " << testNode->getNumerator() << endl;
        cout << "getDenominator() returned " << testNode->getDenominator() << endl;
        delete testNode;
        return false;
    }
}

bool testParameterizedConstructor() {
    Fraction* testNode = new Fraction(5, 3);
    cout << "Creating a fraction with the values 5 and 3\n";

    if ((testNode->getNumerator() == 5) &&
        (testNode->getDenominator() == 3)) {

        cout << "Parameterized constructor correctly initialized the correct values." << endl;
        delete testNode;
        return true;
    }

    else {
        cout << "Parameterized constructor incorrectly intialized to the correct values." << endl;
        cout << "getNumerator() returned " << testNode->getNumerator() << endl;
        cout << "getDenominator() returned " << testNode->getDenominator() << endl;
        delete testNode;
        return false;
    }
}

bool testParameterizedConstructorAndReduce() {
    Fraction* testNode = new Fraction(6, 3);

    cout << "creating a new Fraction(6,3), should reduce to 2,1\n";

    if ((testNode->getNumerator() == 2) &&
        (testNode->getDenominator() == 1)) {

        cout << "Parameterized constructor correctly initialized the correct values." << endl;
        delete testNode;
        return true;
    }

    else {
        cout << "Parameterized constructor incorrectly intialized to the correct values." << endl;
        cout << "getNumerator returned " << testNode->getNumerator() << endl;
        cout << "getDenominator() returned " << testNode->getDenominator() << endl;
        delete testNode;
        return false;
    }
}

bool testCopyConstructor() {
    Fraction number;
    number.setFraction(3, 4);
    Fraction* test = new Fraction(number);

    if ((test->getNumerator() == 3) &&
        (test->getDenominator() == 4)) {

        cout << "Copy constructor correctly initialized the correct values." << endl;
        delete test;
        return true;
    }

    else {
        cout << "Copy constructor incorrectly intialized to the correct values." << endl;
        cout << "getNumerator returned " << test->getNumerator() << endl;
        cout << "getDenominator() returned " << test->getDenominator() << endl;
        delete test;
        return false;
    }
}

bool testConversionConstructor() {
    vector<int> number;
    number.push_back(3);
    number.push_back(4);
    Fraction* test = new Fraction(number);

    cout << "Creating a fraction with values 3 and 4 in a vector<int>\n";
    if ((test->getNumerator() == 3) &&
        (test->getDenominator() == 4)) {

        cout << "Conversion constructor correctly initialized the correct values." << endl;
        delete test;
        return true;
    }

    else {
        cout << "Conversion constructor incorrectly intialized to the correct values." << endl;
        cout << "getNumerator returned " << test->getNumerator() << endl;
        cout << "getDenominator() returned " << test->getDenominator() << endl;
        delete test;
        return false;
    }
}

bool testConversionConstructorANDreduce() {
    vector<int> number;
    number.push_back(6);
    number.push_back(4);
    Fraction* test = new Fraction(number);

    cout << "Creating a fraction with values 6 and 4 in a vector<int>\n";
    cout << "Should reduce to 3 and 2\n";
    if ((test->getNumerator() == 3) &&
        (test->getDenominator() == 2)) {

        cout << "Conversion constructor correctly initialized the correct values." << endl;
        delete test;
        return true;
    }

    else {
        cout << "Conversion constructor incorrectly intialized to the correct values." << endl;
        cout << "getNumerator returned " << test->getNumerator() << endl;
        cout << "getDenominator() returned " << test->getDenominator() << endl;
        delete test;
        return false;
    }
}

bool testoperatorPlus() {
    Fraction num1;
    num1.setFraction(4, 5);
    Fraction num2;
    num2.setFraction(2, 3);
    Fraction test;

    cout << "adding 4/5 to 2/3, results should be 22/15\n";
    test = num1 + num2;

    if ((test.getNumerator() == 22) &&
        (test.getDenominator() == 15)) {

        cout << "The + operator returned correct values." << endl;
        return true;
    }

    else {
        cout << "The + operation did not return the correct values." << endl;
        cout << "getNumerator() returned " << test.getNumerator() << " should have returned 22" << endl;
        cout << "getDenominator() returned " << test.getDenominator() << "should have returned 15" << endl;

        return false;
    }
}

bool testoperatorPlusANDreduce() {
    Fraction num1;
    num1.setFraction(3, 4);
    Fraction num2;
    num2.setFraction(6, 8);
    Fraction test;

    cout << "adding 3/4 to 6/8, results should be 3/2\n";
    cout << "I used a .setFraction to set the results to 6 8, this has been written for you"
        << "and doesn't reduce the fraction automatically\n";
    test = num1 + num2;

    if ((test.getNumerator() == 3) &&
        (test.getDenominator() == 2)) {

        cout << "The + operator returned correct values." << endl;
        return true;
    }

    else {
        cout << "The + operation did not return the correct values." << endl;
        cout << "getNumerator() returned " << test.getNumerator() << " should have returned 3" << endl;
        cout << "getDenominator() returned " << test.getDenominator() << "should have returned 2" << endl;

        return false;
    }
}


bool testoperatorMinus() {
    Fraction num1;
    num1.setFraction(4, 5);
    Fraction num2;
    num2.setFraction(2, 3);
    Fraction test;

    cout << "Creates fractions 4/5 and 2/3, 4/5 - 2/3 = 2/15\n";
    test = num1 - num2;

    if ((test.getNumerator() == 2) &&
        (test.getDenominator() == 15)) {

        cout << "The - operator returned correct values." << endl;
        return true;
    }

    else {
        cout << "The - operation did not return the correct values." << endl;
        cout << "getNumerator() returned " << test.getNumerator() << " should have returned 2" << endl;
        cout << "getDenominator() returned " << test.getDenominator() << "should have returned 15" << endl;

        return false;
    }
}

bool testoperatorMinusANDreduce() {
    Fraction num1;
    num1.setFraction(4, 5);
    Fraction num2;
    num2.setFraction(3, 15);
    Fraction test;

    cout << "Creates fractions 4/5 and 3/15, 4/5 - 3/15 = 3/5\n";
    test = num1 - num2;

    if ((test.getNumerator() == 3) &&
        (test.getDenominator() == 5)) {

        cout << "The - operator returned correct values." << endl;
        return true;
    }

    else {
        cout << "The - operation did not return the correct values." << endl;
        cout << "getNumerator() returned " << test.getNumerator() << " should have returned 3" << endl;
        cout << "getDenominator() returned " << test.getDenominator() << "should have returned 5" << endl;

        return false;
    }
}

bool testoperatorMult() {
    Fraction num1;
    num1.setFraction(4, 5);
    Fraction num2;
    num2.setFraction(2, 3);
    Fraction test;

    cout << "Creating fractions 4/5 and 2/3, 4/5 * 2/3 = 8/15\n";

    test = num1 * num2;

    if ((test.getNumerator() == 8) &&
        (test.getDenominator() == 15)) {

        cout << "The * operator returned correct values." << endl;
        return true;
    }

    else {
        cout << "The * operation did not return the correct values." << endl;
        cout << "getNumerator() returned " << test.getNumerator() << " should have returned 8" << endl;
        cout << "getDenominator() returned " << test.getDenominator() << "should have returned 15" << endl;

        return false;
    }
}

bool testoperatorMultANDreduce() {
    Fraction num1;
    num1.setFraction(4, 5);
    Fraction num2;
    num2.setFraction(5, 3);
    Fraction test;

    cout << "Creating fractions 4/5 and 5/3, 4/5 * 5/3 = 20/15 which reduces to 4/3\n";

    test = num1 * num2;

    if ((test.getNumerator() == 4) &&
        (test.getDenominator() == 3)) {

        cout << "The * operator returned correct values." << endl;
        return true;
    }

    else {
        cout << "The * operation did not return the correct values." << endl;
        cout << "getNumerator() returned " << test.getNumerator() << " should have returned 4" << endl;
        cout << "getDenominator() returned " << test.getDenominator() << "should have returned 3" << endl;

        return false;
    }
}

bool testoperatorLessThan() {
    Fraction num1;
    num1.setFraction(4, 5);
    Fraction num2;
    num2.setFraction(2, 3);
    Fraction test;

    cout << "Creating fractions of 4/5 and 2/3, 4/5 < 2/3 is FALSE\n";
    if (num1 < num2) {
        cout << "Incorrectly returned true\n";
        return false;
    }
    else {
        cout << "Correctly returned false\n";
        return true;
    }
}

bool testoperatorGreaterThan() {
    Fraction num1;
    num1.setFraction(4, 5);
    Fraction num2;
    num2.setFraction(2, 3);
    Fraction test;

    cout << "Creating fractions of 4/5 and 2/3, 4/5 > 2/3 is TRUE\n";
    if (num2 < num1) {
        cout << "Correctly returned true\n";
        return true;
    }
    else {
        cout << "Incorrectly returned false\n";
        return false;
    }
}

bool testoperatorDivide() {
    Fraction num1;
    num1.setFraction(4, 5);
    Fraction num2;
    num2.setFraction(2, 3);
    Fraction test;

    cout << "Created a fraction of 4/5 and 2/3, 4/5 / 2/3 = 6/5 (reduced)" << endl;
    test = num1 / num2;

    if ((test.getNumerator() == 6) &&
        (test.getDenominator() == 5)) {

        cout << "The / operator returned correct values." << endl;
        return true;
    }

    else {
        cout << "The / operation did not return the correct values." << endl;
        cout << "getNumerator() returned " << test.getNumerator() << " should have returned 6" << endl;
        cout << "getDenominator() returned " << test.getDenominator() << "should have returned 5" << endl;

        return false;
    }
}

bool testoperatorEquivalent() {
    Fraction num1;
    num1.setFraction(4, 5);
    Fraction num2;
    num2.setFraction(2, 3);
    Fraction test;

    cout << "Created fractions 4/5 and 2/3, 4/5 == 2/3 should be false" << endl;
    if (num1 == num2) {
        cout << "Incorrectly returned true\n";
        return false;
    }
    else {
        cout << "Correctly returned false\n";
        cout << "setting 4/5 to 4/6, 4/6 == 2/3 should be true" << endl;
        num1.setFraction(4, 6);
        if (num1 == num2) {
            cout << "Correctly returned true\n";
            return true;
        }
        else {
            cout << "Incorrectly returned false\n";
            return false;
        }
        return true;
    }

}

bool testoperatorAssign() {
    Fraction num1;
    num1.setFraction(4, 5);
    Fraction num2;
    num2.setFraction(2, 3);
    Fraction test;

    cout << "Created fractions of 4/5 and 2/3\n";
    cout << "Values of num1 and num2 before =" << endl;
    cout << "num1 = (" << num1.toString() << " num2 = " << num2.toString() << endl;
    num1 = num2;
    cout << "Values of num1 and num2 after =" << endl;
    cout << "num1 = (" << num1.toString() << " num2 = " << num2.toString() << endl;

    if ((num1.getNumerator() == 2) &&
        (num1.getDenominator() == 3) &&
        (num2.getNumerator() == 2) &&
        (num2.getDenominator() == 3)) {

        cout << "The = operator returned correct values." << endl;
        return true;
    }

    else {
        cout << "The = operation did not return the correct values." << endl;
        cout << "num1.getNumerator() returned " << num1.getNumerator() << " should have returned 2" << endl;
        cout << "num1.getDenominator() returned " << num1.getDenominator() << "should have returned 3" << endl;
        cout << "num2.getNumerator() returned " << num2.getNumerator() << " should have returned 2" << endl;
        cout << "num2.getDenominator() returned " << num2.getDenominator() << "should have returned 3" << endl;

        return false;
    }
}
int main() {
    bool passed;
    cout << "UNIT TEST - Default Constructor" << endl;
    passed = testDefaultConstructor();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - Parameterized Constructor" << endl;
    passed = testParameterizedConstructor();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - Parameterized Constructor AND Reduce" << endl;
    passed = testParameterizedConstructorAndReduce();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - Copy Constructor" << endl;
    passed = testCopyConstructor();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - Conversion Constructor" << endl;
    passed = testConversionConstructor();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - Conversion Constructor AND reduce" << endl;
    passed = testConversionConstructorANDreduce();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - operator+" << endl;
    passed = testoperatorPlus();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - operator+ AND reduce" << endl;
    passed = testoperatorPlusANDreduce();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - operator-" << endl;
    passed = testoperatorMinus();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - operator- AND reduce" << endl;
    passed = testoperatorMinusANDreduce();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - operator+" << endl;
    passed = testoperatorMult();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - operator+ AND reduce" << endl;
    passed = testoperatorMultANDreduce();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - operator<" << endl;
    passed = testoperatorLessThan();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - operator>" << endl;
    passed = testoperatorGreaterThan();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - operator/" << endl;
    passed = testoperatorDivide();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - operator==" << endl;
    passed = testoperatorEquivalent();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - operator=" << endl;
    passed = testoperatorAssign();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    return 0;
}


