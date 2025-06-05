#include "util.h"

// Write your recursive function here
bool findSubseq(string s, string seqNow, string target)
{
    if (seqNow == target) return true;
    if (s.size() == 0) return false;
    
    return findSubseq(s.substr(1), seqNow+s.substr(0, 1), target) || findSubseq(s.substr(1), seqNow, target);
}

bool makeSubseq(string s, string target)
{
    return findSubseq(s, "", target);   
}

int main()
{
    // Enter your code here
    string phrase = readLine("Please enter a string: ");
    string subSeq = readLine("Please enter a subsequence to search for: ");
    
    if (makeSubseq(phrase, subSeq))
        cout << "Subsequence found!";
    else
        cout << "Subsequence not found.";
    
    return 0;
}