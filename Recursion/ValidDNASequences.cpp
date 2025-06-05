#include "util.h"

// Write your recursive function here
int validDNA(string nt1, string nt2)
{
    if (0 >= nt1.size() || 0 >= nt2.size()) return 0;
    
    return (int)((nt1.substr(0, 1) == "A" && nt2.substr(0, 1) == "T")
    ||(nt1.substr(0, 1) == "T" && nt2.substr(0, 1) == "A")
    ||(nt1.substr(0, 1) == "C" && nt2.substr(0, 1) == "G")
    ||(nt1.substr(0, 1) == "G" && nt2.substr(0, 1) == "C"))
        + validDNA(nt1.substr(1), nt2.substr(1));
    
    //return validDNA(nt1.substr(1), nt2.substr(1));
}

int main()
{
    string seq1 = readLine("Please enter the first sequence: ");
    string seq2 = readLine("Please enter the second sequence: ");
    // Enter your code here
    cout << "Valid pairs: " << validDNA(seq1, seq2) << endl;
    
    return 0;
}