// CSCI1300 Fall 2018
// Author: Niharika Kunapuli
// Recitation: 104 – Carter Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/niku4657/csci1300-niku4657
// Project 1

/**
 * Algorithm: Simulate a Jeopardy Dice game.
 * 1. It is first the user's turn.
 * 2. User gets to choose if they want to roll the dice or hold.
 * 3. If the user wants to roll the dice, the dice is rolled. Otherwise it 
 * is the computer's turn.
 * 4. If the dice is rolled: 1 or 6 result in the turn's total equaling zero
 * and the turn switching to the other player. 3 will result in the turn's total
 * equaling fifteen, and the turn switching to the other player. If 2, 4, or 5
 * are rolled, then the turn total is accumulated and the dice is rolled again.
 * 5. The game continues switching between the user and computer until one of
 * their accumulated turn total's is greater than 100.
 * 6. Whichever player reaches 100 or more first wins!
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <string>
using namespace std; 

//turnTotal is the accumalated score per turn based on r.
int turnTotal;

//humanTotal is the score of the user/human.
int humanTotal = 0;

//computerTotal is the score of the computer.
int computerTotal = 0;

//acceptTurn is the string value that determines if the user hold or rolls.
string acceptTurn;

/**
 * rollDice 
 * Returns a random integer between 1 and 6, works as rolling a dice.
 * Returns value, int number (1-6).
 */
int rollDice()
{
	return random() % 6 + 1; //Random from 1 to 6 is returned.
}

/**
 * turnOut
 * Takes in some integer determined by rollDice.
 * Switch case statements determine the turnTotal.
 * Returns turnTotal.
 */
int turnOut(int roll)
{
    switch(roll)
     {
          //turnTotal is 0 when rollDice returns 1.
          case 1: turnTotal = 0; break;
          
          //turnTotal is 15 when rollDice returns 3.
          case 3: turnTotal = 15; break;
          
          //turnTotal is 0 when rollDice returns 6.
          case 6: turnTotal = 0; break;
          
          //turnTotal is accumulated when rollDice returns 3, 4, or 5.
          default: turnTotal += roll; break;
     }
     
     //turnTotal is returned.
     return turnTotal;
}

/**
 * human
 * Function representing the user's turn.
 * No parameters.
 * Indicates user's turn.
 * turnTotal starts from zero.
 * Asks if the user wants to roll dice.
 * If the answer is yes, the dice is rolled, and this continues until answer is no.
 * The outcomes of each roll determine whether to roll again or to end turn.
 * When answer is no, then the totals of the user and computer are printed.
 */
void human()
{
    //Indicate that it is the user's turn.
    cout << "It is now human's turn" << endl << endl;
    
    //turnTotal must equal zero before the turn.
    turnTotal = 0;
    
    //User is prompted to input if they want to roll the dice or hold.
    cout << "Do you want to roll a dice (Y/N)?:" << endl;
    cin >> acceptTurn;
    
    //The user is continuously prompted until they say no, if they say yes.
    while(acceptTurn == "y" || acceptTurn == "Y")
    {
        //Variable holds the value of the number rolled.
        int r = rollDice();
        
        //Print statement to let the user know what number was rolled.
        cout << "You rolled a " << r << endl;
        
        //If statements determine whether to end turn or prompt the user again.
        if(r == 2 || r == 4 || r == 5) //Prompt user again.
        {
            cout << "Your turn total is " << turnOut(r) << endl;
            
            cout << "Do you want to roll again (Y/N)?:" << endl;
            cin >> acceptTurn;
        }
        else if(r == 1 || r == 6) //End turn.
        {
            cout << "Your turn total is " << turnOut(r) << endl;
            
            acceptTurn = "n";
        }
        else if(r == 3) //End turn.
        {
            cout << "Your turn total is " << turnOut(r) << endl;
            
            acceptTurn = "n";
        }
    }
    
    //Add the total from this turn to the user's total score.
    humanTotal += turnTotal;
    
    //If user says no then the turn ends.
    if(acceptTurn == "n" || acceptTurn == "N")
    {
        cout << "computer: " << computerTotal << endl;
        cout << "human: " << humanTotal << endl << endl;
    }
}

/**
 * computer
 * Function representing the computer's turn.
 * No parameters.
 * Indicates computer's turn.
 * turnTotal starts from zero.
 * As long as the turnTotal is less than 10, the computer rolls the dice.
 * The outcomes of each roll determine whether to roll again or to end turn.
 * The totals of the user and computer are printed after while loop.
 */
void computer()
{
    //Indicate that it is the computer's turn.
    cout << "It is now computer's turn" << endl << endl;
    
    //turnTotal must equal zero before the turn.
    turnTotal = 0;
    
    //Until the turnTotal accumulates to 10, the computer keeps rolling.
    while(turnTotal < 10)
    {
        //Variable holds the value of the number rolled.
        int r = rollDice();
        
        //Print statement to let the user know what number was rolled.
        cout << "Computer rolled a " << r << endl;
        
        //If statements determine whether to end turn or continue rolling.
        if(r == 2 || r == 4 || r == 5) //Continue rolling.
        {
            cout << "Computer turn total is " << turnOut(r) << endl;
        }
        else if(r == 1 || r == 6) //End turn.
        {
            cout << "Computer turn total is " << turnOut(r) << endl;
            break;
        }
        else if(r == 3) //End turn.
        {
            cout << "Computer turn total is " << turnOut(r) << endl;
        }
    }
    
    //Add the total from this turn to the computer's total score.
    computerTotal += turnTotal;
    
    //Print the total scores for each player at the end of the turn.
    cout << "computer: " << computerTotal << endl;
    cout << "human: " << humanTotal << endl << endl;
}

/**
 * game 
 * Driver function to play the game.
 * Prints out welcome message.
 * As long as the humanTotal and the computerTotal are less than 100,
 * the function runs human() and then game(), if the condition of humanTotal
 * is less than 100 is true.
 * Once either humanTotal or computerTotal are greater than 100, if statements
 * determine and print out winner.
 */
void game()
{
    //Print welcome statement.
    cout << "Welcome to Jeopardy Dice!" << endl << endl;
	
	//The game continues until either one of the players' scores is
	//greater than 100.
	while(humanTotal < 100 && computerTotal < 100)
	{
	    //Call the human function.
	    human();
	    
	    //As long as the user's total score is less than 100,
	    //call the computer function.
	    if(humanTotal < 100)
	    {
	        computer();
	    }
	}
	
	//If statements determine winner and print accordingly.
	if(humanTotal >= 100)
	{
	    cout << "Congratulations! human won this round of jeopardy dice!" << endl;
	}
	else if (computerTotal >= 100)
	{
        cout << "Congratulations! computer won this round of jeopardy dice!" << endl;
	}
}


int main()
{
	//Start the game! 
	game();
	
	//Return nothing for the main function.
	return 0;
}