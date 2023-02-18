#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include "Booklist.h"
using namespace std;

Booklist::Booklist() {
    head = NULL;
    tail = NULL;
}

Booklist::~Booklist() {
    while (head != NULL) {
        BooklistNode* next = head->GetNext();
        delete head;
        head = next;
    }
}

bool Booklist::add(string name, string artist, int yearPublished) {
    BooklistNode* newNode = new BooklistNode(name, artist, yearPublished);
    newNode->SetNext(NULL);

    if (head == NULL) {
        head = newNode;
        tail = head;
        return true;
    }
    else {
        BooklistNode* temp = head;
        while (temp->GetNext() != NULL) {
            if (temp->GetBookName() == name) {
                return false;
            }
            temp = temp->GetNext();
        }
        temp->SetNext(newNode);
        tail = temp->GetNext();
        return true;
    }
    return false;
}

BooklistNode* Booklist::found(string bookName) {
    BooklistNode* temp = head;

    if (temp != NULL) {
        while (temp != NULL) {
            if (temp->GetBookName() == bookName) {
                return temp;
            }
            temp = temp->GetNext();
        }
    }
    else {
        cout << "Booklist is empty";
    }
    return NULL;
}

bool Booklist::remove(string bookname) {
    BooklistNode* temp = head;
    BooklistNode* prev = NULL;

    if (temp != NULL) {
        if (temp->GetBookName() == bookname) {
            head = temp->GetNext();
            delete temp;
            return true;
        }
        else{
            while (temp != NULL && temp->GetBookName() != bookname) {
                prev = temp;
                temp = temp->GetNext();
            }
            prev->SetNext(temp->GetNext());
            delete temp;
            return true;
        }
    }
    return false;
}

bool Booklist::moveFront(string bookname) {
    BooklistNode* temp = head;

    if (temp != NULL) {
        while (temp != NULL) {
            if (temp->GetBookName() == bookname) {
                string tempBName = temp->GetBookName();
                string tempAName = temp->GetAuthorName();
                int tempName = temp->GetYearPublished();
                remove(bookname);
                BooklistNode* newNode = new BooklistNode(tempBName, tempAName, tempName);
                newNode->SetNext(head);
                head = newNode;
                return true;
            }
            temp = temp->GetNext();
        }
            cout << bookname << " not in list";
            return false;
    }
    return false;
}

string Booklist::displayAuthor(string authorName) {
    int cntr = 0;
    BooklistNode* temp = head;
    stringstream myStringStream;

    if (temp != NULL) {
        while (temp != NULL) {
            if (temp->GetAuthorName() == authorName) {
                cntr++;
                myStringStream << cntr << "." << endl << temp->GetBookName() << endl << "Author Name: " << temp->GetAuthorName() << endl
                    << "Year Published: " << temp->GetYearPublished() << endl << endl;
            }
            temp = temp->GetNext();
        }
    }
    else {
        cout << "Booklist is empty";
    }
    string myString = myStringStream.str();
    return myString;
}

int Booklist::totalBooks() {
    int bookCntr = 0;
    BooklistNode* temp = head;

    if (temp != NULL) {
        while (temp != NULL) {
            bookCntr++;
            temp = temp->GetNext();
        }
    }
    else {
        bookCntr = 0;
    }
    return bookCntr;
}

string Booklist::displayList() {
    int cntr = 1;
    BooklistNode* temp = head;
    stringstream myStringStream;

    if (temp != NULL) {
        while (temp != NULL) {
            myStringStream << cntr << "." << endl << temp->GetBookName() << endl << "Author Name: " << temp->GetAuthorName() << endl
                << "Year Published: " << temp->GetYearPublished() << endl << endl;
            cntr++;
            temp = temp->GetNext();
        }
    }
    else {
        cout << "Booklist is empty";
    }
    string myString = myStringStream.str();
    return myString;
}

BooklistNode* Booklist::getHead() {
    return head;
}

BooklistNode* Booklist::getTail() {
    return tail;
}