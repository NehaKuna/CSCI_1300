// Author: CS1300 Fall 2018
// Recitation: 104 – Carter Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/niku4657/csci1300-niku4657
// Homework 2 - Problem 2

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


/**
 * Algorithm: Convert degrees from celsius to fahrenheit.
 * 1. Take the value of the degrees in celsius.
 * 2. Use formula to convert to degrees in fahrenheit.
 * 3. Print the degrees in fahrenheit to two decimal places.
 * 4. Return nothing.
*/

int celsiusToFahrenheit(int degreesCelsius)
{
     //Convert from celsius to fahrenheit using formula.
     float degreesFahrenheit = degreesCelsius * (9.0/5.0) + 32;
     
     //Print results.
     cout << "The temperature of " << degreesCelsius << " in fahrenheit is ";
     std::cout << std::fixed << std::setprecision(2) << degreesFahrenheit;
     
     return 0;
}


int main()
{
    //The following three lines take an inputted number of degrees in celsius.
    cout << "What is the temperature in degrees Celsius?" << endl;
    int degreesCelsius;
    cin >> degreesCelsius;
    
    //Call function.
    celsiusToFahrenheit(degreesCelsius);
    
    //Call test method:
    test();
    
    return 0;
}

void test()
{
    //Test Case One:
    celsiusToFahrenheit(38);
    
    //Test Case Two:
    celsiusToFahrenheit(0);
}