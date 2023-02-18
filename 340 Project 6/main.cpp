#include <iostream>
#include "DoubleLinkedList.h"
using namespace std;

/*int main()
{
	DoubleLinkedList<int> myList;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);
	cout << "Original string" << endl;
	cout << myList.toString() << endl << endl;

	cout << "Insert 33 after 3" << endl;
	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 3);
	position = myList.insert_before(position, 33);
	cout << myList.toString() << endl << endl;

	cout << "Reverse the string" << endl;
	position = myList.find(myList.begin(), myList.end(), 4);
	cout << myList.reverseString(position) << endl << endl;

	DoubleLinkedList<string> stringList;
	stringList.push_front("four");
	stringList.push_front("three");
	stringList.push_front("two");
	stringList.push_front("one");
	cout << "Original string" << endl;
	cout << stringList.toString() << endl << endl;

	DoubleLinkedList<string>::Iterator pos = stringList.find(stringList.begin(), stringList.end(), "two");
	pos = stringList.insert_after(pos, "2 1/2");
	cout << "Insert 2 1/2 after two" << endl;
	cout << stringList.toString() << endl << endl;

	pos = stringList.find(stringList.begin(), stringList.end(), "four");
	pos = stringList.insert_after(pos, "five");
	cout << "Insert five after four" << endl;
	cout << stringList.toString() << endl << endl;

	pos = stringList.find(stringList.begin(), stringList.end(), "one");
	pos = stringList.insert_before(pos, "zero");
	cout << "Insert zero before one" << endl;
	cout << stringList.toString() << endl;


	return 0;
}*/