#include <iostream>

using namespace std;

struct instruction
{
    string inst;
    int value;
    bool visited;
};

void printInstruction(instruction order);

int main() {
    
    instruction order1 {"acc", 1, false};
    instruction order2 {"jmp", -1, true};

    printInstruction(order1);
    printInstruction(order2);

    return 0;
}

void printInstruction(instruction order)
{    
    cout << order.inst << endl << order.value << endl << order.visited << endl;
}