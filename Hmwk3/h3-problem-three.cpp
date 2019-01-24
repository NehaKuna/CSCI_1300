// Author: CS1300 Fall 2018
// Recitation: 104 – Carter Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/niku4657/csci1300-niku4657
// Homework 3 - Problem 3

#include <iostream>
#include <string>
using namespace std;


/**
 * Algorithm: Find the next number in the Collatz sequence.
 * 1. Take the value of a number from 1 to 12 to represent a month.
 * 2. Print the number of days in the month using switch case.
*/
void daysOfMonth(int theMonth)
{
     //Declare variable to store the value of the number of days.
     string numOfDays;
     
     switch(theMonth)
     {
          case 1: numOfDays = "Month 1 has 31 days"; break; //January
          case 2: numOfDays = "Month 2 has 28 or 29 days"; break; //February
          case 3: numOfDays = "Month 3 has 31 days"; break; //March
          case 4: numOfDays = "Month 4 has 30 days"; break; //April
          case 5: numOfDays = "Month 5 has 31 days"; break; //May
          case 6: numOfDays = "Month 6 has 30 days"; break; //June
          case 7: numOfDays = "Month 7 has 31 days"; break; //July
          case 8: numOfDays = "Month 8 has 31 days"; break; //August
          case 9: numOfDays = "Month 9 has 30 days"; break; //September
          case 10: numOfDays = "Month 10 has 31 days"; break; //October
          case 11: numOfDays = "Month 11 has 30 days"; break; //November
          case 12: numOfDays = "Month 12 has 31 days"; break; //December
          default: numOfDays = "Invalid month number"; break; //If not a number from 1 to 12.
     }
     
     //Print the number of days in the the month.
     cout << numOfDays << endl;
}


int main()
{
     //The following three lines take an inputted number from 1 to 12 to represent a month.
    cout << "Enter a number from 1 to 12 to represent a month:" << endl;
    int month;
    cin >> month;
    
    //Call function.
    daysOfMonth(month);
    
    //Test Case 1: Should print "Month 4 has 30 days".
    daysOfMonth(4);
    
    //Test Case 2: Should print "Month 3 has 31 days".
    daysOfMonth(3);
    
    //Test Case 3: Should print "Month 2 has 28 or 29 days".
    daysOfMonth(2);
    
    //Test Case 4: Should print "Invalid month number".
    daysOfMonth(14);
    
    //Return nothing for the main function.
    return 0;
}