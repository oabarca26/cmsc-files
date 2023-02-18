#include "DoubleLinkedList.h"
#include<string>
#include <iostream>
using namespace std;

bool findExists() {
	DoubleLinkedList<int> myList;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 3);

	if (*position == 3) {
		//test more stuff
		return true;
	}

	else {
		return false;
	}
}

bool findBeginning() {
	DoubleLinkedList<int> myList;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 1);

	if (*position == 1) {
		//test more stuff
		return true;
	}

	else {

		return false;
	}
}

bool findEnd() {
	DoubleLinkedList<int> myList;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 4);

	if (*position == 4) {
		//test more stuff
		return true;
	}

	else {

		return false;
	}
}

bool findSecond() {
	DoubleLinkedList<int> myList;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(4);
	myList.push_front(1);

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 4);

	if (*position == 4) {
		//test more stuff
		position = myList.find(++position, myList.end(), 4);
		if (position != NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	else {

		return false;
	}
}

bool findDoesntExist() {
	DoubleLinkedList<int> myList;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 5);

	if (position != NULL) {
		//test more stuff
		return false;
	}

	else {

		return true;
	}
}

bool insertBefore() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 3);

	if (*position == 3) {
		//test more stuff
		DoubleLinkedList<int>::Iterator pos = myList.insert_before(position, 5);
		result = myList.toString();
		cout << result << endl;
		if (result.substr(4, 3).compare("5 3") == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	else {
		return false;
	}
}

bool insertBeforeList() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 1);


	if (*position == 1) {
		//test more stuff
		DoubleLinkedList<int>::Iterator pos = myList.insert_before(position, 0);
		result = myList.toString();
		cout << result << endl;
		if (result.substr(0, 3).compare("0 1") == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	else {

		return false;
	}
}

bool insertBeforeDoesntExist() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 5);

	if (position != NULL) {
		return false;
	}

	else {
		DoubleLinkedList<int>::Iterator pos = myList.insert_before(position, 8);
		if (pos != NULL) {
			return false;
		}
		else {
			return true;
		}
	}
}

bool insertAfter() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 3);


	if (*position == 3) {
		//test more stuff

		DoubleLinkedList<int>::Iterator pos = myList.insert_after(position, 5);
		result = myList.toString();
		if (result.substr(4, 3).compare("3 5") == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	else {

		return false;
	}
}

bool insertAfterEndOfList() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 4);

	if (*position == 4) {
		//test more stuff
		DoubleLinkedList<int>::Iterator pos = myList.insert_after(position, 5);
		result = myList.toString();
		cout << result << endl;
		if (result.substr(0, 9).compare("1 2 3 4 5") == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	else {

		return false;
	}
}

bool insertAfterDoesntExist() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);


	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 5);


	if (position != NULL) {
		return false;
	}

	else {
		DoubleLinkedList<int>::Iterator pos = myList.insert_after(position, 8);
		if (pos != NULL) {
			return false;
		}
		else {
			cout << myList.toString() << endl;
			return true;
		}
	}
}

bool remove() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 3);

	if (*position == 3) {
		//test more stuff
		DoubleLinkedList<int>::Iterator pos = myList.remove(position);
		result = myList.toString();
		if (result.substr(2, 3).compare("2 4") == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	else {

		return false;
	}
}

bool removeEnd() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 4);

	if (*position == 4) {
		//test more stuff
		DoubleLinkedList<int>::Iterator pos = myList.remove(position);
		result = myList.toString();
		cout << result << endl;
		if (result.substr(0, 5).compare("1 2 3") == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	else {

		return false;
	}
}

bool removeDoesntExist() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 5);

	if (position != NULL) {
		return false;
	}

	else {
		DoubleLinkedList<int>::Iterator pos = myList.remove(position);
		if (pos != NULL) {
			return false;
		}
		else {

			return true;
		}
	}
}

bool reverseStringPartial() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 3);

	if (*position == 3) {
		//test more stuff
		result = myList.reverseString(position);
		if (result.substr(0, 5).compare("3 2 1") == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	else {

		return false;
	}
}

bool reverseStringEntireList() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 4);

	if (*position == 4) {
		//test more stuff
		result = myList.reverseString(position);
		if (result.substr(0, 7).compare("4 3 2 1") == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	else {

		return false;
	}
}

bool reverseStringDoesntExist() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 5);

	if (position != NULL) {
		return false;
	}

	else {
		result = myList.reverseString(position);
		if (result.compare("") != 0) {
			return false;
		}
		else {
			return true;
		}
	}
}

bool replace() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(3);
	myList.push_front(1);

	myList.replace(myList.begin(), myList.end(), 3, 8);
	result = myList.toString();

	if (result.substr(0, 9).compare("1 8 2 8 4") == 0) {
		//test more stuff

		DoubleLinkedList<int>::Iterator position1 = myList.find(myList.begin(), myList.end(), 1);
		DoubleLinkedList<int>::Iterator position2 = myList.find(myList.begin(), myList.end(), 2);
		myList.replace(position1, position2, 8, 9);
		result = myList.toString();
		if (result.substr(0, 9).compare("1 9 2 8 4") == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}


}

bool replaceDoesntExist() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);

	myList.replace(myList.begin(), myList.end(), 5, 9);
	result = myList.toString();
	if (result.substr(0, 7).compare("1 2 3 4") == 0) {
		return true;
	}
	else {
		return false;
	}
}
int main() {

	bool passed;
	cout << "UNIT TEST - findExists" << endl;
	passed = findExists();
	passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - findBeginning" << endl;
	passed = findBeginning();
	passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - findEnd" << endl;
	passed = findEnd();
	passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - findSecond" << endl;
	passed = findSecond();
	passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - findDoesntExist" << endl;
	passed = findDoesntExist();
	passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - insertBefore" << endl;
	passed = insertBefore();
	passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - insertBeforeList" << endl;
	passed = insertBeforeList();
	passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - insertBeforeDoesntExist" << endl;
	passed = insertBeforeDoesntExist();
	passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - insertAfter" << endl;
	passed = insertAfter();
	passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - insertAfterEndOfList" << endl;
	passed = insertAfterEndOfList();
	passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - insertAfterDoesntExist" << endl;
	passed = insertAfterDoesntExist();
	passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - remove" << endl;
	passed = remove();
	passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - removeDoesntExist" << endl;
	passed = removeDoesntExist();
	passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - removeEnd" << endl;
	passed = removeEnd();
	passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - reverseStringPartial" << endl;
	passed = reverseStringPartial();
	passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - reverseStringEntireList" << endl;
	passed = reverseStringEntireList();
	passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - reverseStringDoesntExist" << endl;
	passed = reverseStringDoesntExist();
	passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - replace" << endl;
	passed = replace();
	passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - replaceDoesntExist" << endl;
	passed = replaceDoesntExist();
	passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";


	return 0;

}