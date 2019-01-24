// Author: CS1300 Fall 2018
// Recitation: 104 – Carter Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/niku4657/csci1300-niku4657
// Homework 2 - Problem 4

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


/**
 * Algorithm: Calculate luminosity.
 * 1. Take the values of the brightness and the distance.
 * 2. Use luminosity formula to calculate.
 * 3. Return luminosity.
*/

double luminosity(double brightness, double distance)
{
     //In this function we use make pi equal to 3.14159.
     float pi = 3.14159;
     
     //Formula for luminosity.
     double luminosity = 4 * brightness * pi * pow(distance,2);
     
     //Return with luminosity casted into an integer.
     return (int)luminosity;
}


int main()
{
    //The following three lines take an inputted number of the brightness.
    cout << "What is the brightness?" << endl;
    double brightness;
    cin >> brightness;
    
    //The following three lines take an inputted number of the distance.
    cout << "What is the distance?" << endl;
    double distance;
    cin >> distance;
    
    //Call and print function.
    cout << luminosity(brightness,distance);
    
    //Call test method:
    test();
    
    return 0;
}

void test()
{
    //Test Case One:
    luminosity(1.0,20);
    
    //Test Case Two:
    luminosity(3.52,26.9);
}