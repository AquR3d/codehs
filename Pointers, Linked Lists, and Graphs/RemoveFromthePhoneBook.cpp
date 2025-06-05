#include "util.h"

struct record {
    string name, number;
    record *next;
};

/* We need to use both the * and the & since
 * we are passing a pointer and want to pass
 * by reference so that the pointer in the 
 * original method updates.
 */
void insertSorted(record *newRec, record * &head) {
    /* Recursively walk through the list until we either
     * get to the end or the new name is before the
     * current name.
     */
    if (head == NULL || newRec->name < head->name) {
        // Found the place, now add it in
        newRec->next = head;
        head = newRec;
    } else {
        // continue down the list
        insertSorted(newRec, head->next);
    }
}

// Phone Book is in order with the smallest values first
void printRecords(record *head){
    if (head != NULL){
        cout << head->name << ": " << head->number << endl;
        printRecords(head->next);
    }
}

// Gathers information and then passes to the insert function
void addEntry(record * & listHead){
    record *newRec = new record;
    newRec->name = readLine("Please enter the name: ");
    newRec->number = readLine("Please enter the phone number: ");
    insertSorted(newRec, listHead);
}

void removeSorted(string name, record * &head){
    // seearch for name
    
    if (head == NULL){
        cout << name << " was not found.\n";
        return;
    }
    
    // if name is not this... keep searching
    if (head->name != name){
        removeSorted(name, head->next);
    }
    
    // if name is here... remove
    if (head->name == name){
        //remove
        cout << head->name << " was removed." << endl;
        head = head->next;
        return;
    }
}

void removeEntry(record * & listHead){
    string name = readLine("Please enter the name to remove: ");
    
    // search for name & remove
    removeSorted(name, listHead);
}


int main()
{
    record *listHead = NULL;
    while (true) {
        string option = readLine("(A)dd, (P)rint, (R)emove, or (Q)uit: ");
        if (option == "A"){
            addEntry(listHead);
        }
        else if (option == "P"){
            printRecords(listHead);
        }
        else if (option == "R"){
            removeEntry(listHead);    
        }
        else {
            break;
        }
    }

    return 0;
}