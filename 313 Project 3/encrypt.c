/*----------------------------------------------------------------------------*/
/* Define libraries to be included */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable : 4996)
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Define Structures*/
typedef struct  eNode {
    char name[100];           /*contains email address*/
    struct eNode* next; /*next is used to navigate through structures.*/
} eNode;
eNode* firste, * currente, * newe; /*pointers used to create original linked list*/
eNode* encryptfirst, * encryptcurrent, * encryptnew; /*pointers you can use to create your encrypted list*/
/* firste is used to point to first record in the original linked list
encryptfirst must point to the first record in your encrypted list
*/

/* Define Functions (prototypes)*/
void listAll(eNode*);
void shiftEncrypt(eNode* first, int shiftAmt);
char encrypt(char name, int shiftAmt);
void deleteList(eNode* first);

/*----------------------------------------------------------------------------*/
/* Main Function */

//int main(int argc, char **argv)
//argc is the number of arguments used to run your program
//argv is an array of char* arguments
//argv[0] is the name of the executable
//argv[1] is the first argument that you pass in (if you passed in any).
int main(int argc, char** argv)
{
    char name[100];
    char shift[10];
    firste = NULL;
    int counter = 9;
    int shiftAmt;
    encryptfirst = NULL;

    FILE* datafile = fopen("names5.txt", "r");/* open file for reading*/
    if (datafile == NULL) { printf("can't open\n"); }
    else
    {
        //get shiftAmt
        fgets(shift, 9, datafile);
        //convert to in
        shiftAmt = atoi(shift);
        //get first name
        fgets(name, 99, datafile);
        //strcspn returns the index where the second string is in the first string
        //replaces it with a 0 for a cstring (terminating 0)
        name[strcspn(name, "\n")] = 0;
        int length = strlen(name);
        newe = malloc(sizeof(eNode)); //allocate a new node
        //just in case there wasn't a newline, put in a terminating 0
        name[length] = '\0';
        strcpy(newe->name, name); //copy name into node
        newe->next = NULL;
        firste = newe;
        while (fgets(name, 99, datafile)) //pick up the next 9 names
        {
            name[strcspn(name, "\n")] = 0;
            length = strlen(name);
            name[length] = '\0';
            newe = malloc(sizeof(eNode)); //allocate a new node
            strcpy(newe->name, name); //copy name into node
            if (firste != NULL) {
                newe->next = firste; // add new Node to beginning
            }
            firste = newe; //beginning of list updated
            counter--;
        }
        fclose(datafile);  /* close file - good practice to close files after use*/
    }

    printf("Names\n");
    listAll(firste);
    printf("\nEncrypting ...\n");
    shiftEncrypt(firste, shiftAmt);
    printf("\nEncrypted Names\n");
    listAll(encryptfirst);
    printf("\nOriginal Names\n");
    listAll(firste);

    //deallocate the original linked list
    deleteList(firste);
    //deallocate the encrypted linked list
    deleteList(encryptfirst);
}

//This function is to deallocate a linked list
void deleteList(eNode* first)
{
    eNode* next;
    currente = first;
    while (currente != NULL)
    {
        next = currente->next;
        free(currente);
        currente = next;
    }
    first = NULL;
}

/*This function takes as a parameter the first element in a linked list and displays the name
  for all the nodes in the linked list.*/

void listAll(eNode* firstelement)
{
    eNode* next;
    currente = firstelement;
    while (currente != NULL)
    {
        next = currente->next;
        printf("%s\n", currente->name);
        currente = next;
    }
    firstelement = NULL;
}


/*shiftEncrypt(eNode *original, int shift). This function takes as a parameter the first element in a linked list.
 * 	The name in the node will be encrypted and placed into a new linked list.
 * 	For each node in the original linked list
 * 		i. 	Create a new node in your encrypted linked list
 * 		ii. 	The name of the encrypted node will be a version of the current message by shifting every
         alphabetic letter in the message by the indicated number of positions in the alphabet. If a
         character gets shifted past the beginning or end of the alphabet, wrap around to the other end to continue.
        iii. 	Lower case letters will be shifted to a lowercase letter and uppercase letters will be shifted
          to an uppercase letter. For example, a shift value of 6 would shift a 'e' character to a 'k', a 'w' will
          get shifted to a 'c', a 'E' character to a 'K', and a 'W' will get shifted to a 'C'
        iv.	All non alphabetic characters will not be shifted. They will remain the same.
 */
void shiftEncrypt(eNode* firstelement, int shift)
{
    char newName[100];
    encryptcurrent = firstelement;
    encryptfirst = NULL;
    eNode* prevNode = NULL;

    while (encryptcurrent != NULL)
    {
        if (encryptfirst == NULL)
        {
            encryptnew = malloc(sizeof(struct eNode));
            for (int i = 0; i < 100; i++) {
                newName[i] = encrypt(encryptcurrent->name[i], shift);
            }
            strcpy(encryptnew->name, newName);
            encryptnew->next = NULL;
            prevNode = encryptnew;
        }
        else {
            prevNode->next = malloc(sizeof(struct eNode));
            prevNode = prevNode->next;
            strcpy(prevNode->name, encryptcurrent->name);
            prevNode->next = NULL;
        }
        encryptcurrent = encryptcurrent->next;
        encryptfirst = encryptnew;
    }
}


/*  char shift(char, int). This function is a utility function used within
    shiftEncrypt, that takes in a character and the shift amount and returns the
    encrypted character based on the description in shiftEncrypt().
*/
char encrypt(char name, int shiftAmt) {
    char character = name;
    if (isalpha(character)) {
        if (islower(character)) {
            character = (character - 'a' + shiftAmt) % 26 + 'a';
        }
        else if (isupper(character)) {
            character = (character - 'A' + shiftAmt) % 26 + 'A';
        }
    }
    else {
        return character;
    }
    return character;
}

/*----------------------------------------------------------------------------*/

/* END OF PROGRAM */