#include <map>
#include <fstream>
#include "util.h"

// Enter your code here

struct email_node{
    string email;
    email_node *next;
};

map<string, email_node*> addresses; // name and their emails

void insertSorted(string name, email_node * &head, email_node * &newEmail){
    
    if (head == NULL){
        newEmail->next = head;
        head = newEmail;
        return;
    }
    
    insertSorted(name, head->next, newEmail);
}

void addEmail(string name, string email){
    
    email_node *newEmail = new email_node;
    newEmail->email = email;
    
    insertSorted(name, addresses[name], newEmail);
}

void printEmails(email_node * &emails){
    if (emails == NULL) return;
    
    cout << emails->email << " ";
    printEmails(emails->next);
}

void printAddresses(){
    for (map<string, email_node*>::iterator itr = addresses.begin(); itr != addresses.end(); itr++) {
        cout << itr->first << ": ";
        //printEmails(itr->second);
        cout << itr->second->email;
        cout << endl;
    }  
}
    
int main(){
    
    //addresses["Daniel"] = NULL;
    addEmail("Daniel", "sussy@email.com");
    addEmail("Daniel", "amongus@baka.com");
    addEmail("Daniel", "aqua@sus.com");
    
    addEmail("Anna", "boi@gfd.com");
    addEmail("Anna", "dood@baka.com");
    addEmail("Anna", "bananaa@sus.com");
    
    printAddresses();

    return 0;
}