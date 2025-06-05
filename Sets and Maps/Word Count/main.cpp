#include "util.h"
#include <vector>
#include <map>
#include <fstream>


int main(){
    
    // Enter your code here
    string file_name = readLine("Enter file name: ");
    
    ifstream in;
    in.open(file_name);
    
    if (in.fail()) return 1;
    
    map<string, int> words;
    
    string line;
    string buffer;
    // for every line in the file...
    while (getline(in, line))
    {
        vector<string> wrds = splitLine(line, ' ');
        
        for (string word : wrds)
            words[toLowerCase(word)]++;
    }
    
    for (map<string, int>::iterator it = words.begin(); it != words.end(); it++)
    {
        if (it->second > 100)
            cout << it->first << ": " << it->second << endl;
    }

    return 0;
}