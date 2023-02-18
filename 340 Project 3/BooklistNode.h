#ifndef BOOKLISTNODE_H
#define BOOKLISTNODE_H

#include <string>
using namespace std;



class BooklistNode {
public:
    BooklistNode();
    BooklistNode(string initBookName, string initAuthorName,
        int yearPublished, BooklistNode* nextLoc = 0);
    ~BooklistNode();
    void SetNext(BooklistNode* nodePtr);
    string GetBookName() const;
    string GetAuthorName() const;
    int GetYearPublished() const;
    BooklistNode* GetNext();
    string PrintBooklistNode();


private:
    string bookName;
    string authorName;
    int yearPublished;
    BooklistNode* nextNodePtr;
};
#endif