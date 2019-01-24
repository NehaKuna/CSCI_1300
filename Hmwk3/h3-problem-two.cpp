// Author: CS1300 Fall 2018
// Recitation: 104 – Carter Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/niku4657/csci1300-niku4657
// Homework 3 - Problem 2

#include <iostream>
#include <math.h>
using namespace std;


/**
 * Algorithm: Find the next number in the Collatz sequence.
 * 1. Take the value of a number between -1000 and 1000, num.
 * 2. If num is negative then, multiply by -1. Then:
 * 3. If num is greater than 99, it has three digits.
 * 4. If num is greater than 9 but less than 99, it has two digits.
 * 5. If num is 9 or less it has one digit.
 * 6. Print the number of digits to double check.
 * 7. Return the number of digits.
*/
int countDigits(int num)
{
     //Declare variable to store the value of the number of digits.
     int numOfDigits;
     
     //If num is negative, multiply by -1.
     if(num < 0)
     {
          num *= -1;
     }
     
     //Check if the number is between certain values.
     if(num > 99) //Only numbers from 100 to 999 will have 3 digits.
     {
          numOfDigits = 3;
     }
     else if(num > 9 && num <= 99) //Only numbers from 10 to 99 will have 2 digits.
     {
          numOfDigits = 2;
     }
     else //Only numbers from 1 to 9 will have 1 digit.
     {
          numOfDigits = 1;
     }
     
     //Print to double-check.
     cout << numOfDigits << endl;
     
     //Return the value.
     return numOfDigits;
}


int main()
{
     //The following three lines take an inputted number greater than -1000 and less than 1000.
    cout << "Enter a number between -1000 and 1000: " << endl;
    int number;
    cin >> number;
    
    //Call function.
    countDigits(number);
    
    //Test Case 1: Should return 3.
    countDigits(123);
    
    //Test Case 2: Should return 2.
    countDigits(-75);
    
    //Return nothing for the main function.
    return 0;
}