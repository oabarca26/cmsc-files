
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
    bool result = false;
    BooklistNode* testNode = new BooklistNode();

    if ((testNode->GetBookName() == "none") &&
        (testNode->GetAuthorName() == "none") &&
        (testNode->GetYearPublished() == 0) &&
        (testNode->GetNext() == NULL)) {

        result = true;
    }

    else {
        result = false;
    }
    delete testNode;
    return result;
}

bool testBookParameterizedConstructor() {
    bool result = false;
    Booklist* booklist = new Booklist();
    booklist->add("War and Peace", "Leo Tolstoy", 1867);
    BooklistNode* testNode = booklist->getHead();

    if ((testNode->GetBookName() == "War and Peace") &&
        (testNode->GetAuthorName() == "Leo Tolstoy") &&
        (testNode->GetYearPublished() == 1867) &&
        (testNode->GetNext() == 0)) {

        result = true;
    }

    else {
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

    BooklistNode* head = booklist->getHead();
    BooklistNode* testNode = head;

    if ((testNode->GetBookName() == "Moby Dick") &&
        (testNode->GetAuthorName() == "Herman Melville") &&
        (testNode->GetYearPublished() == 1851)) {


        testNode = testNode->GetNext();

        if ((testNode->GetBookName() == "Anna Karenina") &&
            (testNode->GetAuthorName() == "Leo Tolstoy") &&
            (testNode->GetYearPublished() == 1877)) {


            success = true;
        }
        else {

        }
    }

    else {

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

    BooklistNode* head = booklist->getHead();
    BooklistNode* testNode = head;

    if ((testNode->GetBookName() == "Moby Dick") &&
        (testNode->GetAuthorName() == "Herman Melville") &&
        (testNode->GetYearPublished() == 1851)) {


        testNode = testNode->GetNext();

        if ((testNode->GetBookName() == "Anna Karenina") &&
            (testNode->GetAuthorName() == "Leo Tolstoy") &&
            (testNode->GetYearPublished() == 1877)) {



            if (testNode->GetNext() == NULL)
            {

                success = true;

            }
            else {

            }
        }
        else {

        }
    }

    else {

    }
    delete booklist;
    return success;
}

bool testFound() {
    Booklist* booklist = new Booklist();
    bool success = false;
    booklist->add("Moby Dick", "Herman Melville", 1851);
    booklist->add("Anna Karenina", "Leo Tolstoy", 1877);



    if (booklist->found("Moby Dick")) {


        if (booklist->found("Anna Karenina")) {


            if (!booklist->found("Hello World")) {

                success = true;
            }
            else {

            }
        }
        else {

        }

    }
    else {

    }
    delete booklist;
    return success;

}

bool testFoundNot() {
    bool success = false;
    Booklist* booklist = new Booklist();
    booklist->add("Moby Dick", "Herman Melville", 1851);
    booklist->add("Anna Karenina", "Leo Tolstoy", 1877);



    if (!booklist->found("Harry Potter")) {

        success = true;

    }
    else {

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

    if (booklist->remove("Moby Dick")) {
        BooklistNode* head = booklist->getHead();
        if (head->GetBookName() == "Anna Karenina") {

            if (booklist->remove("The Great Gatsby")) {
                BooklistNode* head = booklist->getHead(); //Anna Karenina
                head = head->GetNext(); //War and Peace
                head = head->GetNext(); //should be The Curious Case of Benjamin Button
                if (head->GetBookName() == "The Curious Case of Benjamin Button") {
                    success = true;
                }
                else {

                }
            }
            else {

            }
        }
        else {
        }
    }
    else {
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

    if (booklist->moveFront("War and Peace")) {
        BooklistNode* head = booklist->getHead();
        if (head->GetBookName() == "War and Peace") {
            head = head->GetNext();
            if (head->GetBookName() == "Moby Dick") {
                head = head->GetNext();
            }
            else {
                success = false;
            }
            if (booklist->moveFront("The Great Gatsby")) {
                BooklistNode* head = booklist->getHead();
                if (head->GetBookName() == "The Great Gatsby") {
                    head = head->GetNext();
                    if (head->GetBookName() == "War and Peace") {
                        success = true;
                    }
                    else {
                        success = false;
                    }

                }
                else {
                    success = false;
                }
            }
            else {
                success = false;
            }
        }
        else {
            success = false;
        }
    }
    else {
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
    int total = booklist->totalBooks();
    if (total == 5) {
        success = true;
    }
    else {
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
    if (booklist->moveFront("The Curious Case of Benjamin Button")) {
        BooklistNode* head = booklist->getHead();
        if (head->GetBookName() == "The Curious Case of Benjamin Button") {
            head = head->GetNext();
            if (head->GetBookName() == "Moby Dick") {
            }
            else {
                delete booklist;
                return false;
            };
            booklist->add("The Last Tycoon", "F. Scott Fitzgerald", 1941);
            if (booklist->getHead()->GetBookName() == "The Curious Case of Benjamin Button" && booklist->getTail()->GetBookName() == "The Last Tycoon") {
                success = true;
            }
            else {
            }
        }
        else {
        }
    }
    else {
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
        success = true;
    }
    else {
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
        success = true;
    }
    else {
    }
    delete booklist;
    return success;

}


int main() {
    bool passed;
    cout << "UNIT TEST - Book Constructor" << endl;
    passed = testBookConstructor();
    passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n";

    cout << "UNIT TEST - Book Parameterized Constructor" << endl;
    passed = testBookParameterizedConstructor();
    passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n";

    cout << "UNIT TEST - Add" << endl;
    passed = testAdd();
    passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n";

    cout << "UNIT TEST - Add Duplicate" << endl;
    passed = testAddDuplicate();
    passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n";

    cout << "UNIT TEST - found" << endl;
    passed = testFound();
    passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n";

    cout << "UNIT TEST - found - Not" << endl;
    passed = testFoundNot();
    passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n";

    cout << "UNIT TEST - remove" << endl;
    passed = testFound();
    passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n";

    cout << "UNIT TEST - moveFront" << endl;
    passed = testMoveFront();
    passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n";

    cout << "UNIT TEST - totalBooks" << endl;
    passed = testTotalBooks();
    passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n";

    cout << "UNIT TEST - moveFront and then add" << endl;
    passed = testMoveFrontAndADD();
    passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n";

    cout << "UNIT TEST - displayAuthor" << endl;
    passed = testDisplayAuthor();
    passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n";

    cout << "UNIT TEST - displayList" << endl;
    passed = testDisplayList();
    passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n";
    return 0;
}