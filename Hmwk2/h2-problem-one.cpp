// Author: CS1300 Fall 2018
// Recitation: 104 – Carter Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/niku4657/csci1300-niku4657
// Homework 2 - Problem 1

#include <iostream>
#include <math.h>
using namespace std;


/**
 * Algorithm: Convert a number of seconds into hours, minutes, and seconds.
 * 1. Take the value of the number of seconds.
 * 2. Divide the number of seconds by 3600 (60*60) for number of hours.
 * 3. Take the remaining hours and divide by 60 for number of minutes.
 * 4. Subtract hours and minutes from the total seconds to get remaining seconds.
 * 5. Print the number of hours, minutes, and seconds.
 * 6. Return nothing.
*/

int convertSeconds(int numOfSeconds)
{
     //Declare the variables for hours, minutes, and seconds.
     int hours, minutes, seconds;
     
     //Divide given number of seconds by 3600 to get hours.
     hours = numOfSeconds / 3600;
     
     //Divide the remainder of the hours by 60 to get minutes.
     minutes = (numOfSeconds % 3600) / 60;
     
     //Divide the remainder of the minutes by 60 to get seconds.
     seconds = numOfSeconds - (hours * 3600) - (minutes * 60);
     
     //Print results.
     cout << hours << " hour(s) " << minutes << " minute(s) " << seconds << " second(s)";
     
     return 0;
}


int main()
{
    //The following three lines take an inputted number of seconds.
    cout << "Enter the number of seconds you want converted: " << endl;
    int numOfSeconds;
    cin >> numOfSeconds;
    
    //Call function.
    convertSeconds(numOfSeconds);
    
    //Call test method:
    test();
    
    return 0;
}

void test()
{
    //Test Case One:
    convertSeconds(5);
    
    //Test Case Two:
    convertSeconds(1000000);
}