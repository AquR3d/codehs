#include <iostream>
#include <map>
#include <fstream>
#include <queue>
#include "util.h"

struct student {
    string name; // title
    vector<student*> connections; // pointer connections
    bool visited; // for breadth searching
    student *prev; // i have no idea OH to prevent going backwards
    int distance; // uhhh idk how im supposed to use this i js know it's to calc distances
};

void printNetwork(map<string, student*> &m){
    for(map<string, student*>::iterator itr = m.begin(); itr != m.end(); itr++){
        cout << itr->first << endl;
    }
}

// this traverse through the whole graph which i think is inefficient no cap
void shortestPath(student *start, student *end){
    
    // BREADTH-SEARCH graph
    queue<student*> q;
    // reset parameters
    start->visited = true;
    start->prev = NULL;
    start->distance = 0;
    // add to q to start
    q.push(start);
    
    while(!q.empty()){
        // get first student in q of search
        student *curr = q.front();
        q.pop();
        
        // get connections
        vector<student*> conns = curr->connections;
        
        // i forget that array loops exist
        // for every connection of curr student...
        for (student *conn : conns){
            // prevent going backwards in breadth search
            if (!conn->visited){
                conn->visited = true;
                conn->distance = curr->distance+1;
                conn->prev = curr;
                
                // check if we don't need to search anymore bc/ we found end
                if (conn == end){ // POINTERS CAN USE THE EQUALITY OPERATOR LUCKILY which makes sense
                    break;
                }
                
                // add to q to continue searching after
                q.push(conn);
            }
        }
    }
    // now the distance has been set as well as the prev nodes to backtrack
    
}

// recursive printing method using prev
void printPath(student* n, student* end){
    if (n != NULL){
        // print the people before
        printPath(n->prev, end);
        if (n->prev == NULL){
            cout << n->name << " knows" << endl;
        } else if (n != end){
            cout << n->name << " who knows" << endl;
        } else {
            // print last guy
            cout << end->name << endl;    
        }    
    }
}

void resetValues(map<string, student*> &m){
    student* buffer = NULL;
    for(map<string, student*>::iterator itr = m.begin(); itr != m.end(); itr++){
        buffer = itr->second;
        buffer->visited = false;
        buffer->distance = 0;
        buffer->prev = NULL;
    }
}

void findPath(map<string, student*> &m, student* start, student* end){
    if (start != end){
        shortestPath(start, end);
        cout << start->name << " is " << end->distance << " degree of separation to " << end->name << endl;
        printPath(end, end);
        
        // reset values
        resetValues(m);
    } else {
        cout << start->name << " knows themself!" << endl;    
    }
}

// prompting to add student to network
void addStudent(map<string, student*> &m){
    
    start:;

    string name = readLine("Please enter the new person's name: ");
    
    // if name already exists within network...
    if (m.find(name) != m.end()) {
        cout << "There is already a student under this name!" << endl;
        goto start;
    }
    
    // uh i should account if they have same names uhhhhh
    
    student* newStudent = new student;
    newStudent->name = name;
    newStudent->visited = false;
    newStudent->prev = NULL;
    newStudent->distance = 0;
    
    string connName;
    // aballsuh
    while(true){
        
        cout << "Please enter a person that they know\n('list' to list all; 'exit' when finished):";
        connName = readLine(" ");
        cout << endl;
        
        // omg i forgot c++ is weird and u can compare strings straight up with the comparison operator
        if (connName == "exit") break;
        
        if (connName == "list") {
            printNetwork(m);
            continue;
        }
        
        // if name doesn't exist
        if (m.find(connName) == m.end()){
            cout << "This person does not exist within the network!" << endl;
            continue;
        }
        
        // add connection to new student
        newStudent->connections.push_back(m[connName]);
        // add connection to adam from connection
        m[connName]->connections.push_back(newStudent);
    }
    
    // add new student to network
    m[name] = newStudent;
}
    
int main(){
    
    // pre load graph with initial.txt
    
    ifstream in; // input file stream to open initial.txt
    in.open("initial.txt");
    string line; // buffer variable to getline
    
    if (in.fail()) return 1; // error if the file could not be opened
    
    // graph stuff
    map<string, student*> network;
    vector<student*> allStudentNodes;
    vector< vector<string> > allStudentConns;
    
    while(!in.fail() && !in.eof()){ // if there's still lines in the file
        
        getline(in, line); // SHOULD work bc/ in.fail() == false, so there is text
        
        vector<string> studentInfo = splitLine(line, ':');
        vector<string> studentConns = splitLine(studentInfo.at(1), ',');
        
        //cout << studentInfo.at(0) << " - ";
        //for (int i = 0; i < studentConns.size(); i++) { cout << "|" << studentConns.at(i) << "|"; }
        //cout << endl;
        
        //cout << "\"" << line << "\"" << endl;
        
        // make new student in graph
        student *buffer = new student;
        buffer->name = studentInfo.at(0);
        buffer->visited = false;
        buffer->prev = NULL;
        buffer->distance = 0;
        network[studentInfo.at(0)] = buffer; // retain pointer to grab during connecting of graph
        
        // keep student pointers and connections in vectors in their respective order
        allStudentNodes.push_back(buffer); // pointer to student
        allStudentConns.push_back(studentConns); // names of this student's connetions
        
    }
    
    // connect the graph GYATTTTTTTTT!!!!!!!
    int networkSize = allStudentNodes.size();
    int connsAmt = 0;
    // for every student
    for (int i = 0; i < networkSize; i++){
        // for every connection of this student
        connsAmt = allStudentConns[i].size();
        for (int j = 0; j < connsAmt; j++){
            // connect them
            // for this student... on their pointer -> add each connection
            string connectionName = allStudentConns[i][j]; // get j-th connection's student name of i-th student
            student *connection = network[connectionName]; // get pointer to connection from network by name
            allStudentNodes[i]->connections.push_back(network[connectionName]); // connect the graph
        }
    }
    
    // now i highkey have to check if i connected the graph correctly
    /*for(map<string, student*>::iterator itr = network.begin(); itr != network.end(); itr++){
        cout << itr->first << " - ";
        vector<student*> conns = itr->second->connections;
        int friendSize = conns.size();
        for (int i = 0; i < friendSize; i++){ cout << "\"" << conns[i]->name << "\" "; }
        cout << endl;
    }*/
    // looks right
    
    // GRAPH DONE
    
    /*findPath(network, network["Juan"], network["Juan"]);
    findPath(network, network["Wesley"], network["Juan"]);
    findPath(network, network["Angelica"], network["Juan"]);
    findPath(network, network["Wesley"], network["Angelica"]);
    findPath(network, network["Wanda"], network["Juan"]);
    findPath(network, network["Darrin"], network["Juan"]);*/
    
    //printNetwork(network);
    
    /*findPath(network, network["Wesley"], network["Juan"]);
    addStudent(network);
    printNetwork(network);
    findPath(network, network["Wesley"], network["Juan"]);*/
    
    string input;
    
    while(true){
        cout << "Please select an option:\n1 - Calculate Degree of Separation\n2 - Add Person to the Graph\n3 - Exit\n";
        input = readLine(">> ");
        
        // OPTION 1
        if (input == "1"){
            
            restart:;
            
            cout << "Enter the starting person's name ('list') to list all):";
            input = readLine(" ");
            
            if (input == "list") {
                printNetwork(network);
                goto restart;
            }
            
            // if person is not within the network
            if (network.find(input) == network.end()) {
                cout << "This person does not exist within the network!" << endl;
                goto restart;
            }
            student* start = network[input];
            
            // ENDING PERSON  
            reend:;
            
            cout << "Enter the ending person's name ('list') to list all):";
            input = readLine(" ");
            
            if (input == "list") {
                printNetwork(network);
                goto reend;
            }
            
            // if person is not within the network
            if (network.find(input) == network.end()) {
                cout << "This person does not exist within the network!" << endl;
                goto reend;
            }
            student* end = network[input];
            
            findPath(network, start, end);
        }
        
        // OPTION 2
        else if (input == "2") {
            addStudent(network);
        }
        
        else if (input == "3") break;
        
        cout << endl;
    }
    
    
    cout << "skinidi" << endl;
    
    
    return 0;
}
