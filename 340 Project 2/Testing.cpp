#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Book.h"
#include "ShoppingCart.h"

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

    Book item("Moby Dick", "Herman Melville", 15.99, 1);

    if (item.GetName() == "Moby Dick" && item.GetPrice() == 15.99 && item.GetAuthor() == "Herman Melville"
        && item.GetQuantity() == 1) {

        cout << "Item properly initialized." << endl;
        return true;
    }

    else {
        cout << "Item improperly initialized." << endl;
        cout << "GetName() returns " << item.GetName() << endl;
        cout << "GetPrice() returns " << item.GetPrice() << endl;
        cout << "GetAuthor() returns " << item.GetAuthor() << endl;
        cout << "GetQuantity() return " << item.GetQuantity() << endl;
        return false;
    }
}
bool testBookGettersAndSetters() {

    string result = "";
    Book item;

    item.SetName("War and Peace");
    if (item.GetName() == "War and Peace") {
        result += "Book name \"War and Peace\" correctly set and is accessible.\n";
    }
    else {
        result += "Book name set incorrectly or is inaccessible.\n";
        result += "GetName() returns " + item.GetName() + "\n";
        cout << result;
        return false;
    }


    item.SetPrice(50.99);
    if (item.GetPrice() == 50.99) {
        result += "Book price \"50.99\" correctly set and is accessible.\n";
    }
    else {
        result += "Book price set incorrectly or is inaccessible.\n";
        result += "GetPrice() returns " + to_string(item.GetPrice());
        cout << result;
        return false;
    }

    item.SetAuthor("Leo Tolstoy");
    if (item.GetAuthor() == "Leo Tolstoy") {
        result += "Book author \"Leo Tolstoy\" correctly set and is accessible.\n";
    }
    else {
        result += "Book author set incorrectly or is inaccessible.\n";
        result += "GetAuthor() returns " + item.GetAuthor();
        cout << result;
        return false;
    }

    item.SetQuantity(20);
    if (item.GetQuantity() == 20) {
        result += "Item quantity \"20\" correctly set and is accessible.\n";
    }
    else {
        result += "Item quantity set incorrectly or is inaccessible.\n";
        result += "GetQuantity() returns " + item.GetQuantity();
        cout << result;
        return false;
    }
    cout << result;
    return true;

}

bool testShoppingCartDefaultConstructor() {
    ShoppingCart cart;

    if (cart.GetCustomerName() == "none" &&
        cart.GetDate() == "January 1, 2021") {

        cout << "Shopping Cart properly initialized with default constructor." << endl;
        cout << "Accessors return correct values." << endl;
        return true;
    }

    else {
        cout << "Shopping Cart improperly initialized with default constructor." << endl;
        cout << "GetCustomerName() returns " << cart.GetCustomerName() << endl;
        cout << "GetDate() returns " << cart.GetDate() << endl;
        return false;
    }
}

bool testShoppingCartConstructor() {
    ShoppingCart cart("John Doe", "February 1, 2016");

    if (cart.GetCustomerName() == "John Doe" &&
        cart.GetDate() == "February 1, 2016") {

        cout << "Shopping Cart correctly initialized." << endl;
        return true;

    }

    else {
        cout << "Shopping Cart incorrectly initialized." << endl;
        cout << "GetCustomerName() returns " << cart.GetCustomerName() << endl;
        cout << "GetDate() returns " << cart.GetDate() << endl;

        return false;
    }

}

bool testGetNumItemsA() {

    ShoppingCart cart;

    int i = 0;
    for (i = 0; i < 6; ++i) {
        Book item;
        item.SetQuantity(1);
        cart.AddItem(item);
    }

    if (cart.GetNumItemsInCart() == 6) {
        cout << "GetNumItemsInCart() correctly returns 6" << endl;
        return true;
    }

    else {
        cout << "GetNumItemsInCart() incorrectly returns " << cart.GetNumItemsInCart() << endl;
        return false;
    }
}

bool testGetNumItemsB() {

    ShoppingCart cart;

    int i = 0;
    for (i = 0; i < 6; ++i) {
        Book item;
        item.SetQuantity(2);
        cart.AddItem(item);
    }

    if (cart.GetNumItemsInCart() == 12) {
        cout << "GetNumItemsInCart() correctly returns 12" << endl;
        return true;
    }

    else {
        cout << "GetNumItemsInCart() incorrectly returns " << cart.GetNumItemsInCart() << endl;
        return false;
    }
}

bool testGetCostOfCart() {

    ShoppingCart cart;

    Book item;
    item.SetPrice(2.99);
    item.SetQuantity(4);
    cart.AddItem(item);

    item.SetPrice(1.99);
    item.SetQuantity(2);
    cart.AddItem(item);

    if ((cart.GetCostOfCart() - 15.94) < .01) {
        cout << "GetCostOfCart() correctly returns 15.94" << endl;
        return true;
    }

    else {
        cout << "GetCostOfCart() incorrectly returns " << cart.GetCostOfCart() << endl;
        return false;
    }
}

bool testPrintBookCost() {

    Book item("War and Peace", "Leo Tolstoy", 18.99, 2);

    if (item.PrintBookCost() == "War and Peace 2 @ $18.99 = $37.98") {
        cout << "PrintBookCost() correctly returns \"War and Peace 2 @ $18.99 = $37.98\" " << endl;
        return true;
    }

    else {
        cout << "PrintBookCost() incorrectly returns " << item.PrintBookCost() << endl;
        return false;
    }
}

bool testPrintBookDetails() {
    Book item("War and Peace", "Leo Tolstoy", 18.99, 2);

    if (item.PrintBookDetails() == "War and Peace by Leo Tolstoy") {
        cout << "PrintBookDetails() correctly returns \"War and Peace by Leo Tolstoy\"" << endl;
        return true;
    }

    else {
        cout << "PrintBookDetails() incorrectly returns " << item.PrintBookDetails() << endl;
        return false;
    }
}

bool testPrintTotalMultiples()
{
    vector<string> results;

    ShoppingCart cart("John Doe", "August 18, 2021");
    Book item1("Moby Dick", "Herman Melville", 12.99, 2);
    cart.AddItem(item1);

    string result = cart.PrintTotal();
    results = split(result, '\n');

    if (results[0] == "OUTPUT SHOPPING CART" &&
        results[1] == "John Doe's Shopping Cart - August 18, 2021" &&
        results[2] == "Number of Items: 2" &&
        results[4] == "Moby Dick 2 @ $12.99 = $25.98" &&
        results[6] == "Total: $25.98") {
        cout << "PrintTotal() with multiples of one book returns correctly" << endl;
        return true;
    }

    else {
        cout << "PrintTotal() incorrectly returns \n";
        for (unsigned int i = 0; i < results.size(); i++)
            cout << results[i] << endl;
        cout << "\nSHOULD RETURN:" << endl;
        cout << "OUTPUT SHOPPING CART" << endl;
        cout << "John Doe's Shopping Cart - August 18, 2021" << endl;
        cout << "Number of Items: 2" << endl << endl;
        cout << "Moby Dick 2 @ $12.99 = $25.98" << endl << endl;
        cout << "Total: $25.98" << endl;

        return false;
    }
}

bool testPrintTotalEmpty()
{
    vector<string> results;

    ShoppingCart cart("John Doe", "August 18, 2021");

    string result = cart.PrintTotal();
    results = split(result, '\n');

    if (results[0] == "OUTPUT SHOPPING CART" &&
        results[1] == "John Doe's Shopping Cart - August 18, 2021" &&
        results[2] == "Number of Items: 0" &&
        results[4] == "SHOPPING CART IS EMPTY" &&
        results[6] == "Total: $0.00") {
        cout << "PrintTotal() with empty cart returns correctly" << endl;
        return true;
    }

    else {
        cout << "PrintTotal() incorrectly returns \n";
        for (unsigned int i = 0; i < results.size(); i++)
            cout << results[i] << endl;
        cout << "\nSHOULD RETURN:" << endl;
        cout << "OUTPUT SHOPPING CART" << endl;
        cout << "John Doe's Shopping Cart - August 18, 2021" << endl;
        cout << "Number of Items: 0" << endl << endl;
        cout << "SHOPPING CART IS EMPTY" << endl << endl;
        cout << "Total: $0.0" << endl;

        return false;
    }
}

bool testPrintTotal() {
    vector<string> results;

    ShoppingCart cart("John Doe", "August 18, 2021");
    Book item1("War and Peace", "Leo Tolstoy", 18.99, 2);
    Book item2("Moby Dick", "Herman Melville", 14.99, 3);
    cart.AddItem(item1);
    cart.AddItem(item2);

    string result = cart.PrintTotal();
    results = split(result, '\n');

    if (results[0] == "OUTPUT SHOPPING CART" &&
        results[1] == "John Doe's Shopping Cart - August 18, 2021" &&
        results[2] == "Number of Items: 5" &&
        results[4] == "War and Peace 2 @ $18.99 = $37.98" &&
        results[5] == "Moby Dick 3 @ $14.99 = $44.97" &&
        results[7] == "Total: $82.95") {
        cout << "PrintTotal() returns correctly" << endl;
        return true;
    }

    else {
        cout << "PrintTotal() incorrectly returns \n";
        for (unsigned int i = 0; i < results.size(); i++)
            cout << results[i] << endl;
        cout << "\nSHOULD RETURN:" << endl;
        cout << "OUTPUT SHOPPING CART" << endl;
        cout << "John Doe's Shopping Cart - August 18, 2021" << endl;
        cout << "Number of Items: 5" << endl << endl;
        cout << "War and Peace 2 @ $18.99 = $37.98" << endl;
        cout << "Moby Dick 3 @ $14.99 = $44.97" << endl << endl;
        cout << "Total: $82.95" << endl;

        return false;
    }
}

bool testPrintDescriptions() {

    vector<string> results;

    ShoppingCart cart("John Doe", "August 18, 2021");
    Book item1("War and Peace", "Leo Tolstoy", 18.99, 2);
    Book item2("Moby Dick", "Herman Melville", 14.99, 3);
    cart.AddItem(item1);
    cart.AddItem(item2);

    string result = cart.PrintDescriptions();
    results = split(result, '\n');

    if (results[0] == "OUTPUT ITEMS' DESCRIPTIONS" &&
        results[1] == "John Doe's Shopping Cart - August 18, 2021" &&
        results[3] == "Item Descriptions" &&
        results[4] == "War and Peace by Leo Tolstoy" &&
        results[5] == "Moby Dick by Herman Melville") {
        cout << "PrintDescriptions() returns correctly" << endl;
        return true;
    }

    else {
        cout << "PrintDescriptions() incorrectly returns \n";
        for (unsigned int i = 0; i < results.size(); i++)
            cout << results[i] << endl;
        cout << "\nSHOULD RETURN:" << endl;
        cout << "OUTPUT ITEMS' DESCRIPTIoNS" << endl;
        cout << "John Doe's Shopping Cart - August 18, 2021" << endl << endl;
        cout << "Item Descriptions" << endl;
        cout << "War and Peace by Leo Tolstoy" << endl;
        cout << "Moby Dick by Herman Melville" << endl;

        return false;
    }
}
bool testRemoveItem() {

    vector<string> results;

    ShoppingCart cart("John Doe", "August 18, 2021");
    Book item1("War and Peace", "Leo Tolstoy", 18.99, 2);
    Book item2("Moby Dick", "Herman Melville", 14.99, 3);
    Book item3("The Great Gatsby", "F. Scott Fitzgerald", 12.99, 1);
    cart.AddItem(item1);
    cart.AddItem(item2);
    cart.AddItem(item3);

    string result = cart.PrintDescriptions();
    results = split(result, '\n');

    if (results[0] == "OUTPUT ITEMS' DESCRIPTIONS" &&
        results[1] == "John Doe's Shopping Cart - August 18, 2021" &&
        results[3] == "Item Descriptions" &&
        results[4] == "War and Peace by Leo Tolstoy" &&
        results[5] == "Moby Dick by Herman Melville" &&
        results[6] == "The Great Gatsby by F. Scott Fitzgerald") {
        cout << "Before Remove PrintDescriptions() returns correctly" << endl;

        cart.RemoveItem("Moby Dick");
        string result = cart.PrintDescriptions();
        results = split(result, '\n');
        if (results[0] == "OUTPUT ITEMS' DESCRIPTIONS" &&
            results[1] == "John Doe's Shopping Cart - August 18, 2021" &&
            results[3] == "Item Descriptions" &&
            results[4] == "War and Peace by Leo Tolstoy" &&
            results[5] == "The Great Gatsby by F. Scott Fitzgerald") {
            cout << "After Remove PrintDescriptions() returns correctly" << endl;
            return true;
        }
        else {
            cout << "After Remove PrintDescriptions() incorrectly returns \n";
            for (unsigned int i = 0; i < results.size(); i++)
                cout << results[i] << endl;
            cout << "\nSHOULD RETURN:" << endl;
            cout << "OUTPUT ITEMS' DESCRIPTIoNS" << endl;
            cout << "John Doe's Shopping Cart - August 18, 2021" << endl << endl;
            cout << "Item Descriptions" << endl;
            cout << "War and Peace by Leo Tolstoy" << endl;
            cout << "The Great Gatsby by F.Scott Fitzgerald" << endl;

            return false;
        }
    }

    else {
        cout << "Before Remove PrintDescriptions() incorrectly returns \n";
        for (unsigned int i = 0; i < results.size(); i++)
            cout << results[i] << endl;
        cout << "\nSHOULD RETURN:" << endl;
        cout << "OUTPUT ITEMS' DESCRIPTIoNS" << endl;
        cout << "John Doe's Shopping Cart - August 18, 2021" << endl << endl;
        cout << "Item Descriptions" << endl;
        cout << "War and Peace by Leo Tolstoy" << endl;
        cout << "Moby Dick by Herman Melville" << endl;
        cout << "The Great Gatsby by F. Scott Fitzgerald" << endl;

        return false;
    }
}

bool testModifyQuantity() {
    vector<string> results;

    ShoppingCart cart("John Doe", "August 18, 2021");
    Book item1("War and Peace", "Leo Tolstoy", 18.99, 2);
    Book item2("Moby Dick", "Herman Melville", 14.99, 3);
    cart.AddItem(item1);
    cart.AddItem(item2);

    string result = cart.PrintTotal();
    results = split(result, '\n');

    if (results[0] == "OUTPUT SHOPPING CART" &&
        results[1] == "John Doe's Shopping Cart - August 18, 2021" &&
        results[2] == "Number of Items: 5" &&
        results[4] == "War and Peace 2 @ $18.99 = $37.98" &&
        results[5] == "Moby Dick 3 @ $14.99 = $44.97" &&
        results[7] == "Total: $82.95") {
        cout << "Before Modifying Quantity for Moby Dick PrintTotal() returns correctly" << endl;

        cart.ModifyQuantity("Moby Dick", 5);
        string result = cart.PrintTotal();
        results = split(result, '\n');
        if (results[0] == "OUTPUT SHOPPING CART" &&
            results[1] == "John Doe's Shopping Cart - August 18, 2021" &&
            results[2] == "Number of Items: 7" &&
            results[4] == "War and Peace 2 @ $18.99 = $37.98" &&
            results[5] == "Moby Dick 5 @ $14.99 = $74.95" &&
            results[7] == "Total: $112.93") {
            cout << "After Modifying Quantity for Moby Dick PrintTotal() returns correctly" << endl;
            return true;
        }
        else {
            cout << "After Modifying Quantity for Moby Dick PrintTotal() incorrectly returns \n";
            for (unsigned int i = 0; i < results.size(); i++)
                cout << results[i] << endl;
            cout << "\nSHOULD RETURN:" << endl;
            cout << "OUTPUT SHOPPING CART" << endl;
            cout << "John Doe's Shopping Cart - August 18, 2021" << endl;
            cout << "Number of Items: 5" << endl << endl;
            cout << "War and Peace 2 @ $18.99 = $37.98" << endl;
            cout << "Moby Dick 3 @ $14.99 = $74.95" << endl << endl;
            cout << "Total: $112.93" << endl;

            return false;
        }
    }

    else {
        cout << "PrintTotal() incorrectly returns \n";
        for (unsigned int i = 0; i < results.size(); i++)
            cout << results[i] << endl;
        cout << "\nSHOULD RETURN:" << endl;
        cout << "OUTPUT SHOPPING CART" << endl;
        cout << "John Doe's Shopping Cart - August 18, 2021" << endl;
        cout << "Number of Items: 5" << endl << endl;
        cout << "War and Peace 2 @ $18.99 = $37.98" << endl;
        cout << "Moby Dick 3 @ $14.99 = $44.97" << endl << endl;
        cout << "Total: $82.95" << endl;

        return false;
    }
}

//uncomment the following line to run, main in CMSC340Project2F22.cpp must be commented out
/*int main() {
    //int mainA() {
    bool passed;
    cout << "UNIT TEST - Book Constructor" << endl;
    passed = testBookConstructor();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - Book Getters and Setters" << endl;
    passed = testBookGettersAndSetters();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - shopping cart default constructor" << endl;
    passed = testShoppingCartDefaultConstructor();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - shopping cart constructor" << endl;
    passed = testShoppingCartConstructor();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - getNumItemsA" << endl;
    passed = testGetNumItemsA();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - getNumItemsB" << endl;
    passed = testGetNumItemsB();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - GetCostOfCart" << endl;
    passed = testGetCostOfCart();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - PrintBookCost" << endl;
    passed = testPrintBookCost();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - PrintBookDetails" << endl;
    passed = testPrintBookDetails();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - PrintTotal" << endl;
    passed = testPrintTotal();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - PrintTotal (Empty cart)" << endl;
    passed = testPrintTotalEmpty();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - PrintTotal (multiples of a book)" << endl;
    passed = testPrintTotalMultiples();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - PrintDescriptions" << endl;
    passed = testPrintDescriptions();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - RemoveItem" << endl;
    passed = testRemoveItem();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    cout << "UNIT TEST - ModifyQuantity" << endl;
    passed = testModifyQuantity();
    passed ? cout << "You PASSED this unit test\n\n" : cout << "You DID NOT PASS this unit test\n\n";
    return 0;
}*/
