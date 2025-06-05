#include "util.h"
#include <limits.h>

struct digit{
    long num;
    digit *next;
};

void createDigits(string &str, digit * &head){
    
    if (str.size() <= 0) return; // iterate thru string till no more
    
    digit *newDgt = new digit;
    newDgt->num = atoi(new char(str.back())); // regards any letters as 0s, including the negative sign.
    str.pop_back();
    newDgt->next = head;
    head = newDgt;
    
    createDigits(str, head);
}

void printDigits(digit * &head){
    
    if (head == NULL) {
        cout << endl;
        return;
    }
    
    cout << head->num;
    printDigits(head->next);
}

void insertDigit(digit * &newDgt, digit * &head){
    
    if (head == NULL){
        newDgt->next = head;
        head = newDgt;
        return;
    }
    
    insertDigit(newDgt, head->next);
}

void removeZeros(digit * &head){
    
    if (head == NULL || head->num != 0) return;
    
    head = head->next; // advances
    removeZeros(head);
}

void longDivisionRec(int &divisor, digit * &dividend, digit * &result, long remainder){
    
    // if nothing left to divide
    if (dividend == NULL) return;
    digit *resultDgt = new digit;
    
    // do division
    long num = dividend->num + remainder * 10; // replace all longs with int to save memory
    resultDgt->num = num / divisor;
    
    // add to result digits
    insertDigit(resultDgt, result);
    
    // call next
    longDivisionRec(divisor, dividend->next, result, num % divisor);
}

void longDivision(int &divisor, digit * &dividend, digit * &result){
    // recursion solve
    longDivisionRec(divisor, dividend, result, 0);    
    
    // remove unnecessary 0s from result
    removeZeros(result);
}
int main(){
    // NEGATIVES DO NOT WORK ON THIS
    
    // data structs to represent the big numbers
    digit *head = NULL;
    digit *result = NULL;
    
    // will only take positive whole numbers
    string dividend_str = readLine("Please enter a large number dividend: ");
    int divisor = readInt("Please enter an integer divisor: ", "That's not an integer! Try again: ");
    
    //divisor = INT_MAX;
    
    // setup for division
    createDigits(dividend_str, head);
    
    // do division
    longDivision(divisor, head, result);
    // print result
    printDigits(result);
    
    return 0;
}