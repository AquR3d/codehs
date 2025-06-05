#include "util.h"
#include <stack>
#include <fstream>

bool ifSyntaxPresent(string line)
{
    return line.find('(') != string::npos || line.find('[') != string::npos || line.find('{') != string::npos || line.find(')') != string::npos || line.find(']') != string::npos || line.find('}') != string::npos;
}

int main()
{
    // Enter your code here
    // A DDCOMPILerS!!!! nah its not rly but like it finds if code actually has enough brackets and stuff
    
    string fileName = readLine("Please enter a file to check: ");
    
    ifstream file;
    file.open(fileName);
    
    if (file.fail()) Error("No file found with name: \"" + fileName + "\""); // WAIT I DIDINT KNOW U CAN CONCATONATE IN C++
    
                
    stack<char> syntax;
    int lineIdx = 0; 
    string line;
    while(getline(file, line))
    {
        lineIdx++;
        // search for syntax in line
        if (ifSyntaxPresent(line)) // if found syntax in line
        {
            // if opening bracket
            for (int i = 0; i < line.length(); i++) // EWW I HAVE SO MANY INDENTATIONS WTF THATS 5 YIKES
            {
                char code = line.at(i); // character at index i in line
                
                switch (code)
                {
                    // if open bracket
                    case '(': case '[': case '{': syntax.push(code); break;
                    //if close bracket
                    case ')': case ']': case '}': 
                        if (syntax.top() + 1 == code || syntax.top() + 2 == code) syntax.pop();
                        else
                        {
                            char expectedSyntax;
                            if (syntax.top() == '(') expectedSyntax = ')';
                            else expectedSyntax = syntax.top() + 2;
                            
                            string errorMsg = "Line: " + to_string(lineIdx) + " Expecting " + expectedSyntax + " but found " + code;
                            Error(errorMsg);
                        }
                        break;
                    // if not a syntax, go on to next char
                }
            }
            
        }
        
    }
    
    cout << "Your code looks good!";
    
    return 0;
}