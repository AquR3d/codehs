#include "util.h"
#include <vector>
#include <queue>

int main()
{
    
    int totalCustomers = readInt("How many customers do you want to simulate? ");
    int time = 1;
    
    /* Sim  1:
     * New customer every 5 ticks
     * Central queue
     * cashier 1 - every 12 ticks
     * cashier 2 - every 19 ticks
     * cashier 3 - every 25 ticks
     *
     * How long does it take to check out
     * all customers?
     */
     
    queue<int> customers;
     
    while (totalCustomers > 0)
    {
        if (time % 5 == 0) customers.push(time / 5);
        
        // cashier 1
        if (time % 12 == 0)
        {
            cout << "Cashier 1 served customer " << customers.front() << endl;
            customers.pop();
            totalCustomers--;
        }
        
        // cashier 2
        if (time % 19 == 0)
        {
            cout << "Cashier 2 served customer " << customers.front() << endl;
            customers.pop();
            totalCustomers--;
        }
        
        // cashier 3
        if (time % 25 == 0)
        {
            cout << "Cashier 3 served customer " << customers.front() << endl;
            customers.pop();
            totalCustomers--;
        }
        
        time++;
    }
    
    cout << "It took a total of " << time << " ticks to serve all customers.";
    
    return 0;
}