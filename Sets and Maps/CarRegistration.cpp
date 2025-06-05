#include "util.h"
#include <map>

struct car
{
    string make, model, color;
    int year;
};

void registerCar(map<string, car> &cars)
{
    string plate = readLine("Enter the new license plate number: ");
    
    if (cars.find(plate) != cars.end()) {
        cout << "A car with that license plate is already registered." << endl;
        return;
    }
    
    car tmp;
    tmp.make = readLine("Enter the make of the car: ");
    tmp.model = readLine("Enter the model of the car: ");
    tmp.color = readLine("Enter the color of the car: ");
    tmp.year = readInt("Enter the year of the car(YYYY): ");
    
    cars[plate] = tmp;
}

void searchCar(map<string, car> &cars)
{
    string plate = readLine("Enter the license plate number to search: ");
    
    try
    {
        car tmp = cars.at(plate);
        
        cout << "Year: " << tmp.year << endl;
        cout << "Make: " << tmp.make << endl;
        cout << "Model: " << tmp.model << endl;
        cout << "Color: " << tmp.color << endl;
    }
    catch (exception)
    {
        cout << "No car with that plate found." << endl;
    }
}

int main(){

    // Enter your code here
    map<string, car> cars;
    while(true)
    {
        cout << "Please select an option:" << endl;
        cout << "1. Register Car" << endl;
        cout << "2. Search for a car" << endl;
        cout << "3. Exit" << endl;
        
        int choice = readInt(">> ");
        
        if (choice == 3) break;
        
        if (choice == 1) registerCar(cars);
        
        if (choice == 2) searchCar(cars);    
    }
    
    return 0;
}