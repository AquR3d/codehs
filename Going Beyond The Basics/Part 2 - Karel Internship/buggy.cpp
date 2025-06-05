#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct instruction
{
    string inst;
    int value;
    bool visited;
};

// prints all data from a type instruction
void printInstruction(instruction &order);

int main() {
    
    // get file, and read in file
    cout << "Enter input file name: ";
    string fileName;
    getline(cin, fileName); // process filename into a string
    
    ifstream in; // make a file input stream
    in.open(fileName);
    // make that file input stream open the file provided of the string filename
    
    // if the file input stream cannot find the file with the file name...
    if (in.fail()) { cout << "No file found." << endl; return 1; } // say smth went wrong
    
    // File is found at this point.
    
    // make a vector of instructions to store all the instructions from the file...
    vector<instruction> orders;
    instruction currentOrder;
    /* create an instruction buffer to take the input from the file stream,
     * and to be processed back into the vector
     */
    
    // process file
    while(true)
    {
        // get a line from the file stream to a string buffer variable
        string buffer;
        getline(in, buffer);
        if (in.fail()) break; // if there was no line, break out of processing
        
        // make buffer into string stream
        istringstream stream(buffer);
        string word; // new string to store in betweens ' ' from the buffer
        
        // process the individual file line/buffer variable
        while(getline(stream, word, ' ')) // while there is smth existent between spaces in
        {                                 // the file line/buffer/string stream, store in "word"
            // currentOrder.visited = false; // not necessary bc false is default value
                                             // so this code line is already done automatically
            try {
                // try to convert current word to an int into value
                currentOrder.value = stoi(word);
                // if successful, then the current word was indeed a value
            }
            catch (invalid_argument) // if stoi() fails, that means it's an instruction
            {
                currentOrder.inst = word; // store instruction into string in currentOrder
            }
        }
        // put processed intruction(currentOrder) into vector of instructions
        orders.push_back(currentOrder);
    }
    // store index of instruction in vector, and treat amt
    int treats = 0;
    int idx = 0;
    while(!orders[idx].visited) // while the current instruction has not been visited
    {
        // change current instruction to say it's been visited bc its being processed rn
        orders[idx].visited = true; 
        
        if (orders[idx].inst == "jmp") // if the instruction is to jump...
        {
            /* increment idx by current instruction value to get to current
             * instruction + step = new instruction in vector of instructions
             */
            idx += orders[idx].value;
        }
        else if (orders[idx].inst == "acc") // if the instruction is to accumlate treats...
        {
            /* increment treats by the value of the instruction read from
             * and increment idx by 1 to get to next instruction in the vector of insts...
             */
            treats += orders[idx].value;
            idx++;
        }
        else if (orders[idx].inst == "sit") // if the instruction is to sit...
        {
            /* increment idx by 1 to move on to the next instruction in the vector of
             * instruction when loop runs again...
             */
            idx++;
        }
    }
    // current instruction had been visited before, so break out of while loop
    
    // print treats accumlated from the loop
    cout << treats;

    return 0;
}

void printInstruction(instruction &order) // takes pointer of instruction to be printed
{
    // print the string, then its value, then if it has been visited or not (0-1) (false-true)
    cout << order.inst << " " << order.value << " " << order.visited << endl;
}