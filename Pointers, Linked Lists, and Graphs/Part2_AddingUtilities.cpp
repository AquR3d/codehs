#include <map>
#include <fstream>
#include "util.h"

// Enter your code here

struct email_node{
    string email;
    email_node *next;
};

map<string, email_node*> _addresses; // name and their emails

void insertSorted(string name, email_node * &head, email_node * &newEmail){
    // recursion crap
    if (head == NULL){
        newEmail->next = head;
        head = newEmail;
        return;
    }
    
    insertSorted(name, head->next, newEmail);
}

void removeSorted(email_node * &head, string email){
    
    if (head == NULL) {
        cout << "No Valid Email" << endl;
        return;
    }
    
    if (head->email == email){
        head = head->next;
        cout << email << " has been removed." << endl;
        return;
    }
    
    removeSorted(head->next, email);
}

bool findEmail(email_node * &head, string email){
    
    if (head == NULL) return false;
    
    if (head->email == email) return true;
    
    return findEmail(head->next, email);
}

void addEmail(string name, string email){
    // create email node
    email_node *newEmail = new email_node;
    newEmail->email = email;
    // add to their list
    insertSorted(name, _addresses[name], newEmail);
}

void removeEmail(string name, string email){
    removeSorted(_addresses[name], email);
}

void getForwardAddress(string name, string email){
    
    cout << "Forward " << email << " to : ";
    // if given a valid email for this name...
    if (findEmail(_addresses[name], email)){
        cout << _addresses[name]->email << endl;
        return;
    }
    
    cout << "No Valid Email" << endl;
}

void printEmails(email_node * &emails){
    if (emails == NULL) return;
    
    cout << emails->email << " ";
    printEmails(emails->next);
}

void printAddresses(){
    for (map<string, email_node*>::iterator itr = _addresses.begin(); itr != _addresses.end(); itr++) {
        
        cout << itr->first << ": ";
        //printEmails(itr->second);
        if (itr->second != NULL) cout << itr->second->email;
        cout << endl;
    }  
}
    
int main(){
    
    addEmail("Daniel", "sussy@email.com");
    addEmail("Daniel", "amongus@baka.com");
    addEmail("Daniel", "aqua@sus.com");
    
    addEmail("Anna", "boi@gfd.com");
    addEmail("Anna", "dood@baka.com");
    addEmail("Anna", "bananaa@sus.com");
    
    printAddresses();
    getForwardAddress("Daniel", "amongus@baka.com");
    getForwardAddress("Victoria", "vic@baka.com");
    
    
    removeEmail("Victoria", "cum@gummy.com");
    removeEmail("Daniel", "amongus@baka.com");
    
    
    printAddresses();
    

    getForwardAddress("Victoria", "vic@baka.com");
    getForwardAddress("Daniel", "amongus@baka.com");

    return 0;
}