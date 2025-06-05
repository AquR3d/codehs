#include "util.h"
#include <map>

struct stock {
    string name;
    double price;
};

stock* addStock(string name, double price) {
    stock* tmp = new stock;
    tmp->name = name;
    tmp->price = price;
    return tmp;
}

void printPortfolio(map<stock*, int> &portfolio) {
    
    double sum = 0;
    for (map<stock*, int>::iterator itr = portfolio.begin(); itr != portfolio.end(); itr++) {
        stock* tmp = itr->first;
        cout << tmp->name << ": $" << (itr->second*tmp->price) << endl;
        sum += (itr->second*tmp->price);
    }
    cout << "Total Value: $" << sum << endl;
}

int main()
{
    // Enter your code here
    stock* tesla = addStock("Tesla", 700.32);
    stock* apple = addStock("Apple", 1007.52);
    stock* roblox = addStock("Roblox", 229.35);
    
    map<stock*, int> karel, tracy;
    
    karel[tesla] = 5;
    karel[roblox] = 1;
    
    tracy[tesla] = 3;
    tracy[apple] = 1;
    
    cout << "**Karel's Portfolio**\n";
    printPortfolio(karel);
    
    cout << endl;
    
    cout << "**Tracy's Portfolio**\n";
    printPortfolio(tracy);
    
    cout << endl;
    
    cout << "Updating Tesla\n";
    tesla->price = 100.32;
    
    cout << "**Karel's Portfolio**\n";
    printPortfolio(karel);
    
    cout << endl;
    
    cout << "**Tracy's Portfolio**\n";
    printPortfolio(tracy);
    
    cout << endl;
    
    return 0;
}