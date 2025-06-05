#include <map>
#include <fstream>
#include "util.h"

// Enter your code here

struct email_node{
    string email;
    email_node *next;
};

map<string, email_node*> _addresses; // name and their emails

void insertSorted(email_node * &head, email_node * &newEmail){
    // recursion crap
    if (head == NULL){
        newEmail->next = head;
        head = newEmail;
        return;
    }
    
    //cout << head->email << endl << head->next->email << endl;
    
    insertSorted(head->next, newEmail);
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
    insertSorted(_addresses[name], newEmail);
}

void removeEmail(string name, string email){
    removeSorted(_addresses[name], email);
}

pair<bool, email_node*> getForwardAddress(string name, string email){
    
    // if given a valid email for this name...
    if (findEmail(_addresses[name], email)){
        return pair<bool, email_node*> {true, _addresses[name]};
    }
    
    return pair<bool, email_node*> {false, NULL};
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
    
    // File input
    string line;
    vector<string> buffer;
    email_node *node = NULL;
    ifstream in;
    in.open("initial.txt");
    
    if (in.fail()) return 1;
    
    while (true){
        // receive line in .txt file
        getline(in, line);
        if (in.fail()) break;
        
        buffer = splitLine(line, ',');
        
        node = new email_node;
        node->email = buffer[1];
        node->next = NULL; // VERY IMPORTANT BC/ IT GENERATES GARBAGE VALUES IF NOT THERE
        // AND CRASHES PROGRAM ON ACCESS
        
        _addresses[buffer[0]] = node;
    }
    
    
    // console testings
    //printAddresses();
    string name, email;
    // prompting system
    while (true){
        
        cout << "Please select an option:" << endl;
        cout << "1 - Add a new email" << endl;
        cout << "2 - Remove an email" << endl;
        cout << "3 - Find a Forwarding email address" << endl;
        cout << "4 - Exit" << endl;
        int choice = readInt(1, 4, ">> ");
        
        if (choice == 4) break;
        
        name = readLine("Please enter the name: ");
        email = readLine("Please enter the email address: ");
        
        // prevent wrong names
        try{ _addresses.at(name); }
        catch (...){ cout << "\nThat is not a valid name\n\n"; continue; }
        
        // assumed name is valid at this point
        switch (choice){
            case 1: // add
                addEmail(name, email);
                
                cout << endl << email << " has been added.\n\n";
                break;
            
            case 2: // remove                
                removeEmail(name, email);
                break;
            case 3: // forward
            
                pair<bool, email_node*> rtn = getForwardAddress(name, email);
                if (rtn.first){
                    cout << "\nVerified - Send email to " << rtn.second->email << "\n\n";    
                } else {
                    cout << "\nThat email could not be verified\n\n";    
                }
                
                break;
        }
        

    }
    
    exit_prompt:; // this is so cool, use "goto exit_prompt;" and it works
    
  
    return 0;
}