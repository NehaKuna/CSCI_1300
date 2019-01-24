// Author: CS1300 Fall 2018
// Recitation: 104 – Carter Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/niku4657/csci1300-niku4657
// Homework 2 - Problem 3

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


/**
 * Algorithm: Predict the population in one year.
 * 1. Take the value of the current population.
 * 2. Use the number of seconds in a year to get number of births, deaths, and immigrants.
 * 3. Add or subtract these variables to get population in one year.
 * 4. Return population in one year.
*/

int population(int currentPopulation)
{
     //Total number of seconds in a year: 60 * 60 * 24 * 365
     int secondsInAYear = 31536000;
     
     //There is a birth every 8 seconds.
     int birthsPerYear = secondsInAYear / 8;
     
     //There is an immigrant every 27 seconds.
     int immigrantsPerYear = secondsInAYear / 27;
     
     //There is a death every 12 seconds.
     int deathsPerYear = secondsInAYear / 12;
     
     //Add births and immigrants and subtract deaths from current population.
     int populationInOneYear = currentPopulation + birthsPerYear + immigrantsPerYear
      - deathsPerYear;
     
     return populationInOneYear;
}


int main()
{
    //The following three lines take an inputted number of the current population.
    cout << "What is the current population?" << endl;
    int currentPopulation;
    cin >> currentPopulation;
    
    //Call and print function.
    cout << population(currentPopulation);
    
    //Call test method:
    test();
    
    return 0;
}

void test()
{
    //Test Case One:
    population(5000);
    
    //Test Case Two:
    population(7000000000);
}