#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include "BooklistNode.h"
using namespace std;

BooklistNode::BooklistNode() {
    bookName = "none";
    authorName = "none";
    yearPublished = 0;
    nextNodePtr = NULL;
}

BooklistNode::BooklistNode(string initBookName, string initAuthorName,
    int initYearPublished, BooklistNode* nextLoc) {
    bookName = initBookName;
    authorName = initAuthorName;
    yearPublished = initYearPublished;
    nextNodePtr = nextLoc;
}

BooklistNode::~BooklistNode() {

}

void BooklistNode::SetNext(BooklistNode* nodePtr) {
    nextNodePtr = nodePtr;
}

string BooklistNode::GetBookName() const {
    return bookName;
}

string BooklistNode::GetAuthorName() const {
    return authorName;
}

int BooklistNode::GetYearPublished() const {
    return yearPublished;
}

BooklistNode* BooklistNode::GetNext() {
    return nextNodePtr;
}

string BooklistNode::PrintBooklistNode() {
    return bookName + "\n" + "Author Name: " + authorName + "\n" + "Year Published: " + to_string(yearPublished);
}