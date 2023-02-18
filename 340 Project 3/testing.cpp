/*
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Booklist.h"
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

bool testBookConstructor() {
    cout << "Testing the default constructor" << endl;
    bool result = false;
    BooklistNode* testNode = new BooklistNode();

    if ((testNode->GetBookName() == "none") &&
        (testNode->GetAuthorName() == "none") &&
        (testNode->GetYearPublished() == 0) &&
        (testNode->GetNext() == NULL)) {

        cout << "Default constructor correctly initialized node and accessors return the correct values." << endl;
        result = true;
    }

    else {
        cout << "Default constructor incorrectly intialized node and/or accessors did not return the correct values." << endl;
        cout << "GetBookName() returned " << testNode->GetBookName() << endl;
        cout << "GetAuthorName() returned " << testNode->GetAuthorName() << endl;
        cout << "GetYearPublished() returned " << testNode->GetYearPublished() << endl;
        cout << "GetNext() returned " << testNode->GetNext() << endl;
        result = false;
    }
    delete testNode;
    return result;
}

bool testBookParameterizedConstructor() {
    cout << "Testing the parameterized constructor with War and Peace" << endl;
    bool result = false;
    Booklist* booklist = new Booklist();
    booklist->add("War and Peace", "Leo Tolstoy", 1867);
    BooklistNode* testNode = booklist->getHead();

    if ((testNode->GetBookName() == "War and Peace") &&
        (testNode->GetAuthorName() == "Leo Tolstoy") &&
        (testNode->GetYearPublished() == 1867) &&
        (testNode->GetNext() == 0)) {

        cout << "Parameterized constructor correctly initialized node and accessors return the correct values." << endl;
        result = true;
    }

    else {
        cout << "Parameterized constructor incorrectly intialized node and/or accessors did not return the correct values." << endl;
        cout << "GetBookName() returned " << testNode->GetBookName() << endl;
        cout << "GetAuthorName() returned " << testNode->GetAuthorName() << endl;
        cout << "GetYearPublished() returned " << testNode->GetYearPublished() << endl;
        cout << "GetNext() returned " << testNode->GetNext() << endl;
        result = false;
    }
    delete booklist;
    return result;
}



bool testAdd() {
    bool success = false;
    Booklist* booklist = new Booklist();
    booklist->add("Moby Dick", "Herman Melville", 1851);
    booklist->add("Anna Karenina", "Leo Tolstoy", 1877);

    cout << "Added in this order: Moby Dick, Anna Karenina" << endl;
    BooklistNode* head = booklist->getHead();
    BooklistNode* testNode = head;

    if ((testNode->GetBookName() == "Moby Dick") &&
        (testNode->GetAuthorName() == "Herman Melville") &&
        (testNode->GetYearPublished() == 1851)) {

        cout << "add for 1st node successful." << endl;

        testNode = testNode->GetNext();

        if ((testNode->GetBookName() == "Anna Karenina") &&
            (testNode->GetAuthorName() == "Leo Tolstoy") &&
            (testNode->GetYearPublished() == 1877)) {

            cout << "add for 2nd node successful." << endl;
            success = true;
        }
        else {
            cout << "add for 2nd node unsuccessful" << endl;
        }
    }

    else {
        cout << "add for 1st node unsuccessful." << endl;
        cout << testNode->GetBookName() << endl;
        cout << testNode->GetAuthorName() << endl;
        cout << testNode->GetYearPublished() << endl;
        cout << testNode->GetNext() << endl;
    }
    delete booklist;
    return success;
}

bool testAddDuplicate() {
    bool success = false;
    Booklist* booklist = new Booklist();
    booklist->add("Moby Dick", "Herman Melville", 1851);
    booklist->add("Anna Karenina", "Leo Tolstoy", 1877);
    booklist->add("Moby Dick", "Herman Melville", 1851);

    cout << "Added in this order: Moby Dick, Anna Karenina, Moby Dick (duplicate)" << endl;
    BooklistNode* head = booklist->getHead();
    BooklistNode* testNode = head;

    if ((testNode->GetBookName() == "Moby Dick") &&
        (testNode->GetAuthorName() == "Herman Melville") &&
        (testNode->GetYearPublished() == 1851)) {

        cout << "add for 1st node successful." << endl;

        testNode = testNode->GetNext();

        if ((testNode->GetBookName() == "Anna Karenina") &&
            (testNode->GetAuthorName() == "Leo Tolstoy") &&
            (testNode->GetYearPublished() == 1877)) {

            cout << "add for 2nd node successful." << endl;

            if (testNode->GetNext() == NULL)
            {
                cout << "successfully did not add the second Moby Dick" << endl;
                success = true;

            }
            else {
                cout << "unsuccessful in not adding the duplicate Moby Dick" << endl;
            }
        }
        else {
            cout << "add for 2nd node unsuccessful" << endl;
        }
    }

    else {
        cout << "add for 1st node unsuccessful." << endl;
        cout << testNode->GetBookName() << endl;
        cout << testNode->GetAuthorName() << endl;
        cout << testNode->GetYearPublished() << endl;
        cout << testNode->GetNext() << endl;
    }
    delete booklist;
    return success;
}

bool testFound() {
    Booklist* booklist = new Booklist();
    bool success = false;
    booklist->add("Moby Dick", "Herman Melville", 1851);
    booklist->add("Anna Karenina", "Leo Tolstoy", 1877);

    cout << "Added in this order: Moby Dick, Anna Karenina" << endl;

    if (booklist->found("Moby Dick")) {
        cout << "successfully found Moby Dick" << endl;

        if (booklist->found("Anna Karenina")) {
            cout << "successfully found Anna Karenina" << endl;

            if (!booklist->found("Hello World")) {
                cout << "successfully did not find Hello World" << endl;
                success = true;
            }
            else {
                cout << "unsuccessful in NOT finding a song that is not in the list" << endl;
            }
        }
        else {
            cout << "unsuccessful in finding Moby Dick" << endl;
        }

    }
    else {
        cout << "unsuccessful in finding Anna Karenina" << endl;
    }
    delete booklist;
    return success;

}

bool testFoundNot() {
    bool success = false;
    Booklist* booklist = new Booklist();
    booklist->add("Moby Dick", "Herman Melville", 1851);
    booklist->add("Anna Karenina", "Leo Tolstoy", 1877);

    cout << "Added in this order: Moby Dick, Anna Karenina" << endl;

    if (!booklist->found("Harry Potter")) {
        cout << "successfully did not find Harry Potter" << endl;
        success = true;

    }
    else {
        cout << "unsuccessful - thinks it found Harry Potter" << endl;
    }
    delete booklist;
    return success;

}

bool testRemove() {
    bool success = false;
    Booklist* booklist = new Booklist();
    booklist->add("Moby Dick", "Herman Melville", 1851);
    booklist->add("Anna Karenina", "Leo Tolstoy", 1877);
    booklist->add("War and Peace", "Leo Tolstoy", 1867);
    booklist->add("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    booklist->add("The Curious Case of Benjamin Button", "F. Scott Fitzgerald", 1922);
    cout << "Added in this order: Moby Dick, Anna Karenina, War and Peace, The Great Gatsby, The Curious Case of Benjamin Button" << endl;

    if (booklist->remove("Moby Dick")) {
        BooklistNode* head = booklist->getHead();
        if (head->GetBookName() == "Anna Karenina") {
            cout << "successfully removed Moby Dick" << endl;

            if (booklist->remove("The Great Gatsby")) {
                BooklistNode* head = booklist->getHead(); //Anna Karenina
                head = head->GetNext(); //War and Peace
                head = head->GetNext(); //should be The Curious Case of Benjamin Button
                if (head->GetBookName() == "The Curious Case of Benjamin Button") {
                    cout << "successfully removed The Great Gatsby" << endl;
                    success = true;
                }
                else {
                    cout << "unsuccessful in removing The Great Gatsby" << endl;
                }
            }
            else {
                cout << "unsuccessful in removing The Great Gatsby" << endl;
            }
        }
        else {
            cout << "unsuccessful in removing Moby Dick" << endl;;
        }
    }
    else {
        cout << "unsuccessful in removing Moby Dick" << endl;
    }
    delete booklist;
    return success;

}

bool testMoveFront() {
    bool success = false;
    Booklist* booklist = new Booklist();
    booklist->add("Moby Dick", "Herman Melville", 1851);
    booklist->add("Anna Karenina", "Leo Tolstoy", 1877);
    booklist->add("War and Peace", "Leo Tolstoy", 1867);
    booklist->add("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    booklist->add("The Curious Case of Benjamin Button", "F. Scott Fitzgerald", 1922);

    cout << "Added in this order: Moby Dick, Anna Karenina, War and Peace, The Great Gatsby, The Curious Case of Benjamin Button" << endl;
    cout << "Moving War and Peace to front" << endl;
    if (booklist->moveFront("War and Peace")) {
        BooklistNode* head = booklist->getHead();
        if (head->GetBookName() == "War and Peace") {
            head = head->GetNext();
            if (head->GetBookName() == "Moby Dick") {
                head = head->GetNext();
            }
            else {
                cout << "unsuccessful in moving War and Peace to front" << endl;
                success = false;
            }
            cout << "Moving The Great Gatsby to front" << endl;
            if (booklist->moveFront("The Great Gatsby")) {
                BooklistNode* head = booklist->getHead();
                if (head->GetBookName() == "The Great Gatsby") {
                    head = head->GetNext();
                    if (head->GetBookName() == "War and Peace") {
                        cout << "successfully moved The Great Gatsby to front" << endl;
                        success = true;
                    }
                    else {
                        cout << "unsuccessful in moving The Great Gatsby to front" << endl;
                        success = false;
                    }

                }
                else {
                    cout << "unsuccessful in moving The Great Gatsby to front" << endl;
                    success = false;
                }
            }
            else {
                cout << "unsuccessful in moving The Great Gatsby to front" << endl;
                success = false;
            }
        }
        else {
            cout << "unsuccessful in moving War and Peace to front" << endl;
            success = false;
        }
    }
    else {
        cout << "unsuccessful in moving War and Peace to front" << endl;
        success = false;
    }
    delete booklist;
    return success;

}

bool testTotalBooks() {
    bool success = false;
    Booklist* booklist = new Booklist();
    booklist->add("Moby Dick", "Herman Melville", 1851);
    booklist->add("Anna Karenina", "Leo Tolstoy", 1877);
    booklist->add("War and Peace", "Leo Tolstoy", 1867);
    booklist->add("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    booklist->add("The Curious Case of Benjamin Button", "F. Scott Fitzgerald", 1922);
    cout << "Added in this order: Moby Dick, Anna Karenina, War and Peace, The Great Gatsby, The Curious Case of Benjamin Button" << endl;
    cout << "Total number of books" << endl;
    int total = booklist->totalBooks();
    if (total == 5) {
        cout << "totalBooks() is successful" << endl;
        success = true;
    }
    else {
        cout << "totalBooks() is unsuccessful" << endl;
    }
    delete booklist;
    return success;
}


bool testMoveFrontAndADD() {
    bool success = false;
    Booklist* booklist = new Booklist();
    booklist->add("Moby Dick", "Herman Melville", 1851);
    booklist->add("Anna Karenina", "Leo Tolstoy", 1877);
    booklist->add("War and Peace", "Leo Tolstoy", 1867);
    booklist->add("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    booklist->add("The Curious Case of Benjamin Button", "F. Scott Fitzgerald", 1922);
    cout << "Added in this order: Moby Dick, Anna Karenina, War and Peace, The Great Gatsby, The Curious Case of Benjamin Button" << endl;
    cout << "Moving The Curious Case of Benjamin Button to front" << endl;
    if (booklist->moveFront("The Curious Case of Benjamin Button")) {
        BooklistNode* head = booklist->getHead();
        if (head->GetBookName() == "The Curious Case of Benjamin Button") {
            head = head->GetNext();
            if (head->GetBookName() == "Moby Dick") {
                cout << "successfully moved The Curious Case of Benjamin Button to front" << endl;
            }
            else {
                cout << "unsuccessful in moving The Curious Case of Benjamin Button to front" << endl;
                delete booklist;
                return false;
            };
            booklist->add("The Last Tycoon", "F. Scott Fitzgerald", 1941);
            if (booklist->getHead()->GetBookName() == "The Curious Case of Benjamin Button" && booklist->getTail()->GetBookName() == "The Last Tycoon") {
                cout << "successfully added the Last Tycoon to the end of the list" << endl;
                success = true;
            }
            else {
                cout << "unsuccessfully added the Last Tycoon to the end of the list" << endl;
            }
        }
        else {
            cout << "unsuccessful in moving The Curious Case of Benjamin Button to front" << endl;
        }
    }
    else {
        cout << "unsuccessful in moving The Curious Case of Benjamin Button to front" << endl;
    }
    delete booklist;
    return success;

}

bool testDisplayAuthor() {
    bool success = false;
    string result = "";
    vector<string> results;
    Booklist* booklist = new Booklist();
    booklist->add("Moby Dick", "Herman Melville", 1851);
    booklist->add("Anna Karenina", "Leo Tolstoy", 1877);
    booklist->add("War and Peace", "Leo Tolstoy", 1867);
    booklist->add("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    booklist->add("The Curious Case of Benjamin Button", "F. Scott Fitzgerald", 1922);
    cout << "Added in this order: Moby Dick, Anna Karenina, War and Peace, The Great Gatsby, The Curious Case of Benjamin Button" << endl;
    cout << "Ask for all books with Leo Tolstoy as author" << endl;
    result = booklist->displayAuthor("Leo Tolstoy");
    results = split(result, '\n');
    if (results[0] == "1." &&
        results[1] == "Anna Karenina" &&
        results[2] == "Author Name: Leo Tolstoy" &&
        results[3] == "Year Published: 1877" &&
        results[5] == "2." &&
        results[6] == "War and Peace" &&
        results[7] == "Author Name: Leo Tolstoy" &&
        results[8] == "Year Published: 1867") {
        cout << result;
        cout << "Authors displayed correctly\n";
        success = true;
    }
    else {
        cout << "Authors did not display correctly\n";
        cout << result;
    }
    delete booklist;
    return success;

}

bool testDisplayList() {
    bool success = false;
    string result = "";
    vector<string> results;
    Booklist* booklist = new Booklist();
    booklist->add("Moby Dick", "Herman Melville", 1851);
    booklist->add("Anna Karenina", "Leo Tolstoy", 1877);
    booklist->add("War and Peace", "Leo Tolstoy", 1867);
    booklist->add("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    booklist->add("The Curious Case of Benjamin Button", "F. Scott Fitzgerald", 1922);
    cout << "Added in this order: Moby Dick, Anna Karenina, War and Peace, The Great Gatsby, The Curious Case of Benjamin Button" << endl;
    result = booklist->displayList();
    results = split(result, '\n');
    if (results[0] == "1." &&
        results[1] == "Moby Dick" &&
        results[2] == "Author Name: Herman Melville" &&
        results[3] == "Year Published: 1851" &&
        results[5] == "2." &&
        results[6] == "Anna Karenina" &&
        results[7] == "Author Name: Leo Tolstoy" &&
        results[8] == "Year Published: 1877" &&
        results[10] == "3." &&
        results[11] == "War and Peace" &&
        results[12] == "Author Name: Leo Tolstoy" &&
        results[13] == "Year Published: 1867") {
        cout << result;
        cout << "List displayed correctly\n";;
        success = true;
    }
    else {
        cout << "List did not display correctly\n";
        cout << result;
    }
    delete booklist;
    return success;

}


int main() {
    bool passed;
    cout << "UNIT TEST - Book Constructor" << endl;
    passed = testBookConstructor();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - Book Parameterized Constructor" << endl;
    passed = testBookParameterizedConstructor();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - Add" << endl;
    passed = testAdd();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - Add Duplicate" << endl;
    passed = testAddDuplicate();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - found" << endl;
    passed = testFound();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - found - Not" << endl;
    passed = testFoundNot();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - remove" << endl;
    passed = testFound();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - moveFront" << endl;
    passed = testMoveFront();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - totalBooks" << endl;
    passed = testTotalBooks();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - moveFront and then add" << endl;
    passed = testMoveFrontAndADD();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - displayAuthor" << endl;
    passed = testDisplayAuthor();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";

    cout << "UNIT TEST - displayList" << endl;
    passed = testDisplayList();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    return 0;
}*/