#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include "Booklist.h"
using namespace std;
void PrintMenu(const string booklistTitle) {
    //Put your code here
    Booklist* booklist = new Booklist();
    char userOpt;
    string bookName;
    string bookAuthor;
    int yearPub;
    int total;
    bool repeat;
    do {
        repeat = false;
    cout << "Favorites BOOKLIST MENU" << endl;
    cout << "a - Add book" << endl;
    cout << "d - Remove book" << endl;
    cout << "m - Move book to front" << endl;
    cout << "s - Output books by specific author" << endl;
    cout << "t - Output total number of books in booklist" << endl;
    cout << "o - Output full booklist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    
        cout << "Choose an option: ";
        cin >> userOpt;

        switch (userOpt) {
        case 'a':
            cout << endl;
            cout << "ADD BOOK" << endl;
            cout << "Enter the book's name:" << endl;
            cin.ignore();
            getline(cin, bookName);
            cout << "Enter author's name:" << endl;
            getline(cin, bookAuthor);
            cout << "Enter year published: " << endl;
            cin >> yearPub;
            booklist->add(bookName, bookAuthor, yearPub);
            cout << endl;
            repeat = true;
            break;
        case 'd':
            cout << endl;
            cout << "REMOVE BOOK" << endl;
            cout << "Enter book's name: " << endl;
            getline(cin, bookName);
            cin.ignore();
            booklist->remove(bookName);
            cout << endl;
            repeat = true;
            break;
        case 'm':
            cout << endl;
            cout << "MOVE BOOK TO BEGINNING" << endl;
            cout << "Enter book's name: " << endl;
            getline(cin, bookName);
            cin.ignore();
            booklist->moveFront(bookName);
            cout << endl;
            repeat = true;
            break;
        case 's':
            cout << endl;
            cout << "OUTPUT BOOKS BY SPECIFIC AUTHOR" << endl;
            cout << "Enter author's name:" << endl;
            getline(cin, bookAuthor);
            cin.ignore();
            booklist->displayAuthor(bookName);
            cout << endl;
            repeat = true;
            break;
        case 't':
            cout << endl;
            cout << "OUTPUT TOTAL NUMBER OF BOOKS IN BOOKLIST" << endl;
            cout << "Total books: ";
            total = booklist->totalBooks();
            cout << total << " books" << endl;
            cout << endl;
            repeat = true;
            break;
        case 'o':
            cout << endl;
            cout << booklistTitle << " - OUTPUT FULL PLAYLIST" << endl;
            booklist->displayList();
            cout << endl;
            repeat = true;
            break;
        case 'q':
            cout << endl;
            repeat = false;
            break;
        default:
            cout << endl;
            repeat = true;
        }
    } while (repeat == true);
    delete booklist;
}

/*int main() {
    string booklistTitle;

    // Prompt user for booklist title
    cout << "Enter booklist's title:" << endl;
    getline(cin, booklistTitle);
    cout << endl;

    // Output book list menu options
    PrintMenu(booklistTitle);

    return 0;
}*/