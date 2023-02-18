#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include "ShoppingCart.h"
#include "Book.h"
using namespace std;

int main() {
    string userName, userDate;
    ShoppingCart userCart, userMenu;
    cout << "Enter customer's name:" << endl;
    getline(cin, userName);
    cout << "Enter today's date:" << endl;
    getline(cin, userDate);
    cout << endl << "Customer name: " << userName;
    cout << endl << "Today's date: " << userDate << endl;
    userCart = ShoppingCart(userName, userDate);
    userMenu.PrintMenu(userCart);
    return 0;
}
char ShoppingCart::PrintMenu(ShoppingCart item) {
    char userOpt;
    Book userBook;
    string bookName;
    double bookPrice;
    string bookAuthor;
    int bookQuantity;
    bool repeat;
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    do {
        repeat = false;
        cout << "Choose an option: ";
        cin >> userOpt;

        switch (userOpt) {
        case 'a':
            cout << "ADD ITEM TO CART" << endl;
            cout << "Enter the book name :" << endl;
            cin.ignore();
            getline(cin, bookName);
            cout << "Enter the book author :" << endl;
            getline(cin, bookAuthor);
            cout << "Enter the book price :" << endl;
            cin >> bookPrice;
            cout << "Enter the book quantity :" << endl;
            cin >> bookQuantity;
            userBook = Book(bookName, bookAuthor, bookPrice, bookQuantity);
            AddItem(userBook);
            repeat = true;
            break;
        case 'd':
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove :" << endl;
            getline(cin, bookName);
            cin.ignore();
            RemoveItem(bookName);
            repeat = true;
            break;
        case 'c':
            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter name of item to change quantity :" << endl;
            cin.ignore();
            getline(cin, bookName);
            cout << "Enter the new quantity :" << endl;
            cin >> bookQuantity;
            ModifyQuantity(bookName, bookQuantity);
            repeat = true;
            break;
        case 'i':
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            PrintDescriptions();
            repeat = true;
            break;
        case 'o':
            cout << "OUTPUT SHOPPING CART" << endl;
            cout << item.GetCustomerName() << "\'s Shopping Cart - " << item.GetDate() << endl;
            PrintTotal();
            repeat = true;
            break;
        case 'q':
            return 0;
            break;
        default:
            repeat = true;
        }
    } while (repeat);
    return 0;
}