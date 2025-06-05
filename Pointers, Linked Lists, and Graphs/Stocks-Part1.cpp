#include "util.h"

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

int main()
{
    // Enter your code here
    stock* tesla = addStock("Tesla", 700.32);
    
    cout << tesla->name << " shares sell for " << tesla->price << endl;
    
    return 0;
}