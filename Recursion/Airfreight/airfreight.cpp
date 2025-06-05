#include <fstream>
#include <vector>
#include "util.h"

const int BEST_VALUE = 700;
const int MAX_WEIGHT = 50;

struct item {
    string name;
    int value, weight;
    bool included;
};

vector<item> readContents() {

    vector<item> output;
    ifstream in;
    in.open("contents.txt");
    if(in.fail())
        cout << "File didn't open"<<endl;

    string line;
    while (true) {
        getline(in, line);
        if (in.fail()) break; //will fail at end of file

        vector<string> split = splitLine(line);
        item newItem;
        newItem.name = split[0];
        newItem.value = stoi(split[1]);
        newItem.weight = stoi(split[2]);
        newItem.included = false;
        output.push_back(newItem);
    }
    return output;
}

void printItem(item i){
    cout << i.name << endl;
    cout << "Value: " << i.value << endl;
    cout << "Weight: " << i.weight << endl;
    cout << endl;
}

// Enter your recursive function here
bool airFreightRec(vector<item> &items, int weight, int value, int next) {
    // base case
    // check >=$700 and no more lbs can be added without exceeding 50 lbs
    // success: print all included items
    // fail...
    if (value >= BEST_VALUE && weight <= MAX_WEIGHT) return true; // if this is a successful combo.. return true
    
    if (weight > MAX_WEIGHT) return false; // end combo early if exceeded weight limit
    
    // find new combo
    for (int elem = next; elem < items.size(); elem++) {
        
        item obj = items[elem]; // for convenience, assign new variable to current element...
        if (airFreightRec(items, weight+obj.weight, value+obj.value, elem+1)) { // if theres a combo with this...
            items[elem].included = true; // include it
            return true; // return true to cause inclusion train to all items of this combo...
        }
    }
    return false; // return false if no items after with this item worked...
}

// Use this function to kick off your recursive call
void airFreight(vector<item> &items) {
    // Call your recursive function from here
    airFreightRec(items, 0, 0, 0);
}

int main() {

    vector<item> items = readContents();

    // Call your recursive function
    airFreight(items);
    
    // Print out the results
    int value = 0, weight = 0;
    for (item obj : items) {
        if (obj.included) {
            cout << obj.name << "\nValue: " << obj.value << "\nWeight: " << obj.weight << "\n\n";
            value += obj.value;
            weight += obj.weight;
        }
    }
    cout << "Total Value: " << value << endl;
    cout << "Total Weight: " << weight << endl;
    
    return 0;
}