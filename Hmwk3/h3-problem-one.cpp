// Author: CS1300 Fall 2018
// Recitation: 104 – Carter Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/niku4657/csci1300-niku4657
// Homework 3 - Problem 1

#include <iostream>
#include <math.h>
using namespace std;


/**
 * Algorithm: Find the next number in the Collatz sequence.
 * 1. Take the value of an integer, num.
 * 2. If num is negative then, return 0.
 * 3. If num is even then, num equals num divided by 2.
 * 4. If num is odd then, num equals num multiplied by 3 added to 1.
 * 5. Print the return value.
 * 6. Return num which now holds the value of the next number in the sequence.
*/

int collatzStep(int num)
{
     //If statement checks if the number is negative, before it checks for even or odd.
     if(num < 0) //Negative numbers are less than zero.
     {
          num = 0;
     }
     else if (num % 2 == 0) //If the remainder is zero when num is divided by 2, then it is even.
     {
          num /= 2;
     }
     else //If it's not negative and it's not even then it is odd.
     {
          num = 3 * num + 1;
     }
     
     //Print num to double check.
     cout << num << endl;
     
     //Return the value.
     return num;
}


int main()
{
     //The following three lines take an inputted integer.
    cout << "Enter an integer: " << endl;
    int number;
    cin >> number;
    
    //Call function.
    collatzStep(number);
    
    //Test Case 1: Should return 2.
    collatzStep(4);
    
    //Test Case 2: Should return 22.
    collatzStep(7);
    
    //Test Case 3: Should return 0.
    collatzStep(-5);
    
    //Return nothing for the main function.
    return 0;
}