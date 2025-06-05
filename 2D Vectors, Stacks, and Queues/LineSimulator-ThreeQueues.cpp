#include "util.h"
#include <vector>
#include <queue>

int main()
{
    
    int totalCustomers = readInt("How many customers do you want to simulate? ");
    int time = 1;
    
    /* Sim  2:
     * New customer every 5 ticks
     * separate queues
     * cashier 1 - every 12 ticks
     * cashier 2 - every 19 ticks
     * cashier 3 - every 25 ticks
     *
     * How long does it take to check out
     * all customers?
     */
     
    vector<queue<int> > customers {queue<int>{}, queue<int>{}, queue<int>{}}; // weirdest syntax in the west
    
    while (totalCustomers > 0)
    {
        // Add customer to shortest queue
        if (time % 5 == 0)
        {
            if (customers[0].size() <= customers[1].size() && customers[0].size() <= customers[2].size()) // if 1 small
            {
                customers[0].push(time / 5);
            }
            else if (customers[1].size() <= customers[2].size()) // if 2 small
            {
                customers[1].push(time / 5);
            }
            else // if 3 small
            {
                customers[2].push(time / 5);
            }
        }
        
        // cashier 1
        if (!customers[0].empty() && time % 12 == 0)
        {
            cout << "Cashier 1 served customer " << customers[0].front() << endl;
            customers[0].pop();
            totalCustomers--;
        }
        
        // cashier 2
        if (!customers[1].empty() && time % 19 == 0)
        {
            cout << "Cashier 2 served customer " << customers[1].front() << endl;
            customers[1].pop();
            totalCustomers--;
        }
        
        // cashier 3
        if (!customers[2].empty() && time % 25 == 0)
        {
            cout << "Cashier 3 served customer " << customers[2].front() << endl;
            customers[2].pop();
            totalCustomers--;
        }
        
        time++;
    }
    
    cout << "It took a total of " << time << " ticks to serve all customers.";
    
    return 0;
}