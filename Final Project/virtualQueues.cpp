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
    
    if (curr == nullptr){
        cout << "There is no one in line for " << q.ride << endl;
        return;
    }
    
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

}

int main() {

    // Create virtual queue map and add rides with
    // the addRides function
    map<string, virtualQueue> rides;
    addRides(rides);

    // Test your addToQueue function by adding
    // at least 3 guests one queue
    printQueue(rides["MOON"]);
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
    
    
    // Test your printQueue function
    
    
    return 0;
}