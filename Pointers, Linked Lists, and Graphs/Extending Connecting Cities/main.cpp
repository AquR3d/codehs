#include "util.h"
#include <vector>
#include <queue>
#include <map>
#include <fstream>

struct city {
    string name;
    vector<city*> connections;
    bool visited;
    city *prev;
    int distance;
};

map<string, city*> loadGraph();

/* Similar to the previous example, this calculates
 * a path from the starting city to all other cities
 */
void shortestPath(city* start){
    // breadth-first seearch
    queue<city*> q; 
    start->visited = true;
    start->distance = 0;
    start->prev = NULL;
    q.push(start); // add the beginning to the q
    
    while (!q.empty()){
        city *currNode = q.front(); // set the first as current
        q.pop(); // remove from q since it's being processed
        
        // get the vector of pointer connections of the current location
        vector<city*> currConn = currNode->connections;
        
        // for each connection in the currConn vector...
        for (city* conn : currConn){
            if (!conn->visited){ // if it hasn't been visited by a before breadth-first search...
                //cout << "found " << currNode->name << " to " << conn->name << endl;
                conn->visited = true; // now say it's been visited
                conn->distance =  currNode->distance + 1; // increment distance from current
                conn->prev = currNode; // ? for printPath()
                
                // add the new connection from the vector onto the q to be processed in breadth-first search
                q.push(conn); 
            }
        }
    }
}

/* This takes a ending point twice. The first
 * is used in the recursive call and the second
 * is used purely for formatting the output.
 */
void printPath(city *n, city *end){
    if (n != NULL){
        printPath(n->prev, end);
        if (n->name != end->name){
            cout << n->name  << " to " << endl; 
        }
        else {
            cout << n->name << endl; 
        }
    }
}

/* This function is used to kick off the recursive
 * print path method
 */
void findRoute(city *start, city *end){
    shortestPath(start);
    cout << "Trip from " << start->name;
    cout << " to " << end->name << endl;
    printPath(end, end);
}

void printCities(map<string, city*> &cities){
    for (map<string, city*>::iterator itr = cities.begin(); itr != cities.end(); itr++){
        cout << itr->first << endl;    
    }
}

void resetValues(map<string, city*> &cities){
    city *curr = NULL;
    
    for (map<string, city*>::iterator itr = cities.begin(); itr != cities.end(); itr++){
        curr = itr->second;
        curr->visited = false;
        curr->prev = NULL;
        curr->distance = 0;
    }
}

int main(){
    map<string, city*> cities = loadGraph();
    //findRoute(cities["San Fransisco"], cities["Miami"]);
    
    while (true){
        cout << "Please select an option:\n";
        cout << "1 - Calculate Route\n";
        cout << "2 - Add City to the Graph\n";
        cout << "3 - Exit\n";
        int choice = readInt(1, 3, ">> ");
        
        if (choice == 1){ // Calc
            
            start:; // reprompt
            
            string start = readLine("Enter a starting city name ('list' to list all): ");
            
            if (start == "list"){
                printCities(cities);
                goto start;
            }
            
            try { cities.at(start); } catch (...) { cout << "That city was not found.\n"; goto start; }
            
            // second question
            
            end:; // reprompt
            
            string end = readLine("Enter an ending city name ('list' to list all): ");
            
            if (end == "list"){
                printCities(cities);
                goto end;
            }
            
            try { cities.at(end); } catch (...) { cout << "That city was not found.\n"; goto end; }
            
            findRoute(cities.at(start), cities.at(end));
            
            // implement resetting values
            resetValues(cities);
            
            cout << endl;
            
        } else if (choice == 2){ // Add
            
            string name = readLine("Please enter the new city name: ");
            
            // create the city pointer
            city *newCity = new city;
            newCity->name = name;
            newCity->visited = false;
            newCity->prev = NULL;
            newCity->distance = 0;
            cities[name] = newCity;
            
            vector<city*> conns {}; // make vector of connections
            
            // prompt for vector of connections
            while (true){
                
                cout << "Please enter a city that is connected\n";
                string conn = readLine("'list' to list all; 'exit' when finished): ");
                
                if (conn == "exit") { break; }
                if (conn == "list") { printCities(cities); continue; }
                
                try { cities.at(conn); } catch (...) { cout << "That city was not found.\n"; continue; }
                
                cout << endl;
                
                // add to vector of connections for new city
                conns.push_back(cities.at(conn));
                // add this city to the existing cities connections
                cities.at(conn)->connections.push_back(newCity);
            }
            
            newCity->connections = conns;
            
            
        } else if (choice == 3) { break; } // Exit
    }

    
    return 0;
}

/* This function loads cities from the text input
 * file and returns each city in a map with the
 * citie name as a key. The city connections are
 * stored in the struct.
 */
map<string, city*> loadGraph(){
    /* We will use these vectors as intermediate
     * steps as we read from the input file
     */
    vector<city*> cities;
    vector<vector<string> > allConn;

    map<string, city*> cityNodes;
    
    ifstream in;
    in.open("cities.txt");
    string line;

    while (true) {
        getline(in, line);
        if (in.fail()) break;
        vector<string> input = splitLine(line, ':');
        string cityName = input[0];
        vector<string> cityConn = splitLine(input[1],',');
        
        // Create the node and add to map
        city *newCity = new city;
        newCity->name = cityName;
        newCity->visited = false;
        cityNodes[cityName] = newCity;
        
        // Put city name and connections for next step
        cities.push_back(newCity);
        allConn.push_back(cityConn);
    }
    
    /* Iterate through all cities and add 
     * cities connections into the nodes
     */
    
    // Loop through all cities
    for (int i = 0; i < cities.size(); i++){
        // Loop through all city connection
        for (int j = 0; j < allConn[i].size(); j++){
            cities[i]->connections.push_back(cityNodes[allConn[i][j]]);
        }
    }
    
    return cityNodes;
}