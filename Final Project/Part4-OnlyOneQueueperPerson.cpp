/* This program will manage virtual queues for an
 * ammusement park. The user can add names, take names
 * from the queue, or print the queue out.
 */
#include "util.h"
#include <map>

struct virtualQueue;

struct guest {
    string name;
    virtualQueue *currentQueue = nullptr;
    guest *next = nullptr;
    guest *previous = nullptr;
};

struct virtualQueue {
    string ride;
    int length;
    guest *head = nullptr;
    guest *tail = nullptr;
};

bool emptyQueue(virtualQueue &q){
    if (q.tail == NULL) {
        cout << "There is no one in line for " << q.ride << endl;
        return true;
    }
    return false;
}

/*
 * @param queue - queue to add the guest to
 * @newGuest - Guest to be added
 * This takes a queue and a guest and adds the guest to the queue
 * It also updates the guest by attaching the queue to the guest record
 */
void addToQueue(virtualQueue &queue, guest *newGuest) {
    newGuest->currentQueue = &queue;
    newGuest->next = queue.head;
    newGuest->previous = NULL;
    if (queue.head != nullptr){
        queue.head->previous = newGuest;
    } else {
        queue.tail = newGuest;
    }
    queue.head = newGuest;
}

/*
 * @param - Non-empty queue to print
 * Prints out the current queue with a blank line at the end.
 */
void printQueue(virtualQueue &q) {
    
    guest* curr = q.tail;
    
    if (emptyQueue(q)) return;
    
    // simple print SKINIDI
    while(curr != nullptr){
        cout << curr->name << endl;
        curr = curr->previous;
    }
}

/*
 * @param virtualQueues - map to add rides to
 * This function is use to set up the program and adds a set of rides
 * to the queue. It uses pass by reference, so it does not need to return
 * a value. The rides can be added to or changed.
 */

void addRides(map<string, virtualQueue> &virtualQueues) {

    virtualQueue buffer;
    buffer.ride = "Rise of the Resistance";
    buffer.length = 0;
    virtualQueues["RISE"] = buffer;

    // Add additional rides to the available rides
    buffer.ride = "Goon Lagoon";
    buffer.length = 60; // 60 seconds
    virtualQueues["GOON"] = buffer;
    
    buffer.ride = "Vector's Moon Riding";
    buffer.length = 59; // 59 seconds
    virtualQueues["MOON"] = buffer;
    
    buffer.ride = "Peeing Pond";
    buffer.length = 20; // 20 seconds is the average aduult peeing time
    virtualQueues["PEEP"] = buffer;
    
    buffer.ride = "Streaming Stream";
    buffer.length = 3600; // 1 hour
    virtualQueues["STRE"] = buffer;
    
    buffer.ride = "Luanning Lane";
    buffer.length = 58; // 58 seconds
    virtualQueues["LUAN"] = buffer;
    

}

void nextGuest(virtualQueue &q){
    
    if (emptyQueue(q)) return;
    
    cout << "Next up on " << q.ride << ": " << q.tail->name << endl;
    
    // remove front of queue
    guest* front = q.tail;
    front->currentQueue = NULL;
    
    // if last guy
    if (front->previous == NULL){
        q.tail = NULL;
        q.head = NULL;
        return;
    }
    // change order in queue
    q.tail = front->previous;
    q.tail->next = NULL;
    
    // reset removed guy's order to be nothing
    front->previous = NULL;
    front->next = NULL;

}

string getQueueIndex(map<string, virtualQueue> &m){
    
    cout << "Please enter the code for the ride you wish to ride\n";
    cout << "Code\tRide Name\n";
    for (map<string, virtualQueue>::iterator itr = m.begin(); itr != m.end(); itr++){
        cout << itr->first << "\t" << itr->second.ride << endl;
    }
    
    string input;
    reprompt:;
    
    input = readLine(">> ");
    if (m.find(input) == m.end()){
        cout << "Please enter a valid choice.\n";
        goto reprompt;
    }
    
    return input;
}

int getMenuOption(){
    cout << "Select an Option from the Menu:\n";
    cout << "1 - Add name to queue\n";
    cout << "2 - Get the next rider\n";
    cout << "3 - Print entire queue for a ride\n";
    cout << "4 - Quit\n";
    return readInt(1, 4, ">> ", "Please enter a valid option.\n>> ");
}

void removeFromQueue(map<string, guest*> &m, string name){
    guest* person = m[name];
    virtualQueue* q = person->currentQueue;
    person->currentQueue = NULL;
    m.erase(name);
    
    // reorder line
    // if only bum in line
    if (person->previous == NULL && person->next == NULL) {
        // change head and tail
        q->head = NULL;
        q->tail = NULL;
        return;
    }
    // if you're the head aka back
    else if (person->previous == NULL){
        q->head = person->next;
        q->head->previous = NULL;
    }
    // if you're the tail aka front
    else if (person->next == NULL){
        q->tail = person->previous;
        q->tail->next = NULL;
    }
    // if you're in the middle of the line
    else {
        person->previous->next = person->next;
        person->next->previous = person->previous;
    }
    person->next = NULL;
    person->previous = NULL;
}

bool currentlyInLine(map<string, guest*> &m, string guestName){
    if (m.find(guestName) == m.end()) return false;
    
    if (m[guestName]->currentQueue == NULL) return false;
    
    // switch queues?
    cout << guestName << " is currently in line at " << m[guestName]->currentQueue->ride << endl;
    cout << "Would you like to change rides? (Y or N)?";
    string input = readLine(" ");
    
    if (input == "N") return true;
    
    removeFromQueue(m, guestName);
    return false;
}


int main() {

    // Create virtual queue map and add rides with
    // the addRides function
    map<string, virtualQueue> rides;
    addRides(rides);
    map<string, guest*> people;

    // Test your addToQueue function by adding
    // at least 3 guests one queue
    /*printQueue(rides["MOON"]);
    guest* buffer = new guest;
    buffer->name = "Vector";
    addToQueue(rides["MOON"], buffer);
    buffer = new guest;
    buffer->name = "Luan";
    addToQueue(rides["MOON"], buffer);
    buffer = new guest;
    buffer->name = "Daniel";
    addToQueue(rides["MOON"], buffer);
    printQueue(rides["MOON"]);
    
    nextGuest(rides["MOON"]);
    printQueue(rides["MOON"]);
    nextGuest(rides["MOON"]);
    printQueue(rides["MOON"]);
    nextGuest(rides["MOON"]);
    printQueue(rides["MOON"]);
    nextGuest(rides["MOON"]);
    printQueue(rides["MOON"]);*/
    
    int input = 0;
    string ride;
    string name;
    
    while(true){
        input = getMenuOption();
        
        if (input == 1){
            cout << "Please enter the name of the rider:";
            name = readLine(" ");
            
            // SKIBIDI CODE
            if (currentlyInLine(people, name)) continue;
            
            // make guest
            guest* newGuest = new guest;
            newGuest->name = name;
            people[name] = newGuest;
            
            ride = getQueueIndex(rides); // get desired ride queue
            addToQueue(rides[ride], newGuest);
        }
        
        else if (input == 2){
            ride = getQueueIndex(rides); // get desired ride queue
            nextGuest(rides[ride]);
        }
        
        else if (input == 3){
            ride = getQueueIndex(rides); // get desired ride queue
            cout << rides[ride].ride << endl;
            printQueue(rides[ride]);
        }
        
        else if (input == 4) {
            break;
        }
        
        cout << endl;
    }

    
    // Test your printQueue function
    
    
    return 0;
}