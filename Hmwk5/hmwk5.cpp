// CSCI1300 Fall 2018
// Author: Niharika Kunapuli
// Recitation: 104 – Carter Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/niku4657/csci1300-niku4657
// Homework 5
#include <iostream>
#include <string>
using namespace std;

/**
 * Algorithm: Find hamming distance by counting the number of mismatches.
 * 1. Take the values of two strings.
 * 2. In a for loop:
 * 3. Compare each character of the strings, one by one.
 * 4. Every time there is a mismatch, add one to your count.
 * 5. Return the count of mismatches.
*/
int hammingDistance(string first, string second)
{
    int count = 0; //Number of mismatches.
    
    //For loop goes through both strings character by character and compares them.
    for(int i = 0; i < first.length(); i++)
    {
        if(first[i] != second[i]) //When there's a mismatch occurs.
        {
            count++; //Increase number of mismatches by one.
        }
    }
    
    //Return number of mismatches.
    return count;
}

/**
 * Algorithm: Find similarity score.
 * 1. Take the values of two strings.
 * 2. If either one of the strings are empty, then similarity score is zero.
 * 3. If the lengths of the two strings are not equal, then similarity score is zero.
 * 4. Otherwise calculate similarity score using formula.
 * 5. Return the similarity score.
*/
double simScore(string f, string s)
{
    double similarityScore; //Declare similarity score.
    
    if(f == "" || s == "") //If either of the strings are empty.
    {
        similarityScore = 0; //Return 0.
    }
    else if(f.length() != s.length()) //If the strings are not equal in length.
    {
        similarityScore = 0; //Return 0.
    }
    else //Otherwise.
    {
        /*Similarity score is equal to the length minus hammingdistance
          all divided by the length.*/
        similarityScore = f.length() - hammingDistance(f,s);
        similarityScore /= f.length();
    }
    
    //Return similarity score.
    return similarityScore;
}

/**
 * Algorithm: Find the largest similarity score.
 * 1. Take the values of the three genomes and the unknown sequence.
 * 2. In a for loop:
 * 3. Set a temporary string equal to a substring of genome 1 that is equal to unknown length.
 * 4. Set a temporary double equal to the similarity score for the substring and unknown.
 * 5. Repeatedly check if the similarity score from one substring is greater than another.
 * 6. Repeat steps 3-4 for genomes 2 and 3, inside same for loop.
 * 7. Outside of for loop:
 * 8. Compare the largest similarity scores of each genome.
 * 9. Print the largest similarity scores out of all three genomes.
 * 5. Return nothing.
*/
void compare(string g1, string g2, string g3, string bact)
{
    /*Declare the variables to hold largest similarity scores across all three
      genomes*/
    double a, b, c;
    
    //Loop through the length of the genomes to determine a, b, and c.
    for(int i = 0; i <= g1.length(); i++)
    {
        /*Create temporary string to hold substring values for genome 1 that are
          equal to the length of the unknown sequence.*/
        string temp = g1.substr(i, bact.length());
        
        /*Create a temporary double to hold the value of the similarity score of
          the substring and the unknown.*/
        double t = simScore(temp, bact);
        
        if(t > a) //If the temporary double is greater than a.
        {
            a = t; //a equals the temporary double.
        }
        
        /*Temporary string now holds substring values for genome 2 that are
          equal to the length of the unknown sequence.*/
        temp = g2.substr(i, bact.length());
        
        /*Temporary double now holds the value of the similarity score of
          the substring and the unknown.*/
        t = simScore(temp, bact);
        
        if(t > b) //If the temporary double is greater than b.
        {
            b = t; //b equals the temporary double.
        }
        
        /*Temporary string now holds substring values for genome 3 that are
          equal to the length of the unknown sequence.*/
        temp = g3.substr(i, bact.length());
        
        /*Temporary double now holds the value of the similarity score of
          the substring and the unknown.*/
        t = simScore(temp, bact);
        
        if(t > c) //If the temporary double is greater than c.
        {
            c = t; //c equals the temporary double.
        }
    }
    
    /*The following if else statements compare the similarity scores of all
      three genomes.*/
    if(a > b) //When a is greater than b.
    {
         if(a > c) //When a is also greater than c.
         {
             cout << "Genome 1 is the best match." << endl;
         }
         else if(a < c) //When a is also less than c.
         {
             cout << "Genome 3 is the best match." << endl;
         }
         else if(a == c) //When is also equal to c.
         {
             cout << "Genome 1 is the best match." << endl;
             cout << "Genome 3 is the best match." << endl;
         }
    }
    else if(a < b) //When a is less than b.
    {
        if(b == c) //When b is also equal to c.
        {
            cout << "Genome 2 is the best match." << endl;
            cout << "Genome 3 is the best match." << endl;
        }
        else if(b > c) //When b is also greater than c.
        {
            cout << "Genome 2 is the best match." << endl;
        }
        else if(b < c) //When b is also less than c.
        {
            cout << "Genome 3 is the best match." << endl;
        }
    }
    else if(a == b) //When a is equal to b.
    {
        if(a > c) //When a is also greater than c.
        {
            cout << "Genome 1 is the best match." << endl;
            cout << "Genome 2 is the best match." << endl;
        }
        else if(a < c) //When a is also less than c.
        {
            cout << "Genome 3 is the best match." << endl;
        }
        else if(a == c) //When a is also equal to c.
        {
            cout << "Genome 1 is the best match." << endl;
            cout << "Genome 2 is the best match." << endl;
            cout << "Genome 3 is the best match." << endl;
        }
    }
}

/**
 * Algorithm: Find the best match to the unknown sequence.
 * 1. Take the values of the three genomes and the unknown sequence.
 * 2. If any of the strings are empty print out appropriate statement.
 * 3. If any of the genome lengths are unequal print out appropriate statement.
 * 4. If the unknown sequence's length is greater than the genomes' lengths,
 *    then print out appropriate statement.
 * 5. Otherwise call the compare function using the three genomes and the unknown sequence.
 * 6. Return nothing.
*/
void analyzer(string genOne, string genTwo, string genThree, string bacteria)
{
    //Test for empty strings.
    if(genOne == "" || genTwo == "" || genThree == "" || bacteria == "")
    {
        cout << "Genome and sequence cannot be empty." << endl;
    }
    //Test for unequal genome lengths.
    else if(genOne.length() != genTwo.length() || genOne.length() != genThree.length() || genTwo.length() != genThree.length())
    {
        cout << "Genome length does not match." << endl;
    }
    //Test for an unknown length greater than the genome length.
    else if(bacteria.length() > genOne.length())
    {
        cout << "Sequence length must be smaller than genome length." << endl;
    }
    else //Otherwise.
    {
        //Call the compare function.
        compare(genOne, genTwo, genThree, bacteria);
    }
}

int main()
{
	//simScore test cases
	cout << simScore("ACCT","ACCG") << endl; //Should return 0.75
	cout << simScore("GGGG", "AAAA") << endl; //Should return 0
	cout << simScore("TTTT", "TTTT") << endl; //Should return 1
	cout << simScore("AGCT", "AGTC") << endl; //Should return 0.5
	cout << simScore("TCT", "GCAT") << endl; //Should return 0
	cout << simScore("", "") << endl; //Should return 0
    
    //analyzer test cases
    
    //Should return "Genome 1 is the best match."
    analyzer("TAAGGCA","TCTGGGC","CTAATAT","AAG");
    
    //Should return "Genome 2 is the best match."
    analyzer("TAAGGCA","TACCTAC","AGCCAGA","TCT");
    
    //Should return that all 3 genomes are the best match.
    analyzer("AC","AC","AC","AC");
    
    //Should return "Genome and sequence cannot be empty."
    analyzer("", "AC","AC","AC");
    
    //Should return "Genome length does not match."
    analyzer("ACTG","ACT","ACTG","AGTC");
    
    //Should return "Sequence length must be smaller than genome length."
    analyzer("ATC","ACT","TAC","TACG")
	
	//Return nothing for the main function.
	return 0;
}