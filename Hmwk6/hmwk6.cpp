// CSCI1300 Fall 2018
// Author: Niharika KUnapuli
// Recitation: 104 – Tillquist
// Cloud9 Workspace Editor Link: <https://ide.c9.io/niku4657/csci1300-niku4657>
// hmwk6 


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;


/* split function
 * the function to split the given string into array of string with respect to a delimiter
 *
 * @param : string , the string we are going to split
 * @param : char, the delimiter
 * @param : string array, the array of string we save after spliting
 * @param : int, size of the  indicates the maximum number of split-apart string pieces
*/
 int split (string str, char c, string array[], int size)
 {
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return count ;
 }

/* readBooks function
 * the function reads a book file from the text into book and author arrays
 *
 * @param: string, the name of the file to be read
 * @param: string array, titles
 * @param: string array, authors
 * @param: int, the number of books currently stored in the arrays
 * @param: int, capacity of the authors/titles arrays [assume to be 50]
 * @return: the total number of books in total
 */
int readBooks(string fileName, string titles[], string authors[], int numBooks, int capacity)
{
    ifstream myfilestream;
    myfilestream.open(fileName);
    
    int count = 0;
    
    if(myfilestream.is_open())
    {
        string s = "";
        string a[2];
        
        while(getline(myfilestream, s))
        {
           split(s, ',', a, 2);
           
           if(count < capacity)
           {     
                authors[count] = a[0];
                titles[count] = a[1];
                
                count++;
           }
           else
           {
               break;
           }
        }
    }
    else if(myfilestream.fail())
    {
        count = -1;
    }
    
    return count;
}


/* readRatings function
 * Read the user ratings from the file and store them
 * into users array and ratings array
 *
 * @param: string, the name of the file to be read
 * @param: string array, usernames
 * @param: 2D int array, list of ratings for each user (first index specifies user)
 * @param: int, the number of users currently stored in the array
 * @param: int, row capacity of the 2D array (convention: array[row][column]) [assume to be 100]
 * @param: int, column capacity of the 2D array [assume to be 50]
 * @return: the number of users in total
 */
int readRatings(string fileName, string usernames[], int userRatings[100][50], int numUsers, int rowCapacity, int columnCapacity)
{
    ifstream myfilestream;
    myfilestream.open(fileName);
    
    int count = 0;
    
    if(myfilestream.is_open())
    {
        string s = "";
        string a[2];
        string b[rowCapacity];
        string x = "";
        string numArray[columnCapacity];
        
        for(int i = 0; i < 86; i++)
        {
            getline(myfilestream, s);
            split(s, ',', a, 2);
            
            usernames[i] = a[0];
            cout << usernames[i] << "..." << endl;
            
            count++;
            
            x = a[1];
            
            split(x, ' ', numArray, columnCapacity);
            
            for(int j = 0; j < columnCapacity; j++)
            {
                userRatings[i][j] = stoi(numArray[j]);
            }
        }
    }
    
    if(count == 0)
    {
        count = -1;
    }
    
    return count;
}

/* printAllBooks function
 * the function to print all books listed in given file
 *
 * @param : string array, the array of strings containing titles
 * @param : string array, the array of strings containing authors
 * @param : int, the number of books there are in the database
*/
void printAllBooks(string titles[], string authors[], int numBooks)
{
    if(numBooks <= 0)
    {
        cout << "No books are stored" << endl;
    }
    else
    {
        cout << "Here is a list of books" << endl;
        
        for(int i = 0; i < numBooks; i++)
        {
            cout << titles[i] << " by " << authors[i] << endl;
        }
    }
}

/*Helper function that searches the user array for a
particular username and returns its index.*/
int findUser(string username, string usernames[], int numUsers)
{
    for(int i = 0; i < numUsers; i++)
    {
        if(usernames[i] == username)
        {
            return i;
        }
    }
    
    return -1;
}

/* getUserReadCount function
 * the function to find the number of books the user has read
 *
 * @param : string , the user we are trying to find
 * @param : string array, the array of strings containing all the users
 * @param : int 2D array, the 2D array of integers containing all the user's ratings
 * @param : int, the total number of users in the database
 * @param : int, the total number of books in the database
*/
int getUserReadCount(string username, string usernames[], int userRatings[100][50], int numUsers, int numBooks)
{
    int booksRead = 0;
    
    int index = findUser(username, usernames, numUsers);
    
    if(numUsers == 0 || index == -1)
    {
        cout << username << " does not exist in the database" << endl;
        return -1;
    }
    
    for(int i = 0; i < numBooks; i++)
    {
        if(userRatings[index][i] != 0)
        {
            ++booksRead;
        }
    }
    
    return booksRead;
}

/*Helper function that searches the titles array for a
particular book and returns its index.*/
int findTitle(string title, string titles[], int numBooks)
{
   for(int i = 0; i < numBooks; i++)
    {
        if(titles[i] == title)
        {
            return i;
        }
    }
    
    return -1;
}

/* calcAvgRating function
 * the function to calculate the average rating per book
 *
 * @param : string, the title we are trying to find
 * @param : string array, the array of strings containing all the titles in the database
 * @param : int 2D array, the 2D array of integers containing all the user's ratings
 * @param : int, the total number of users in the database
 * @param : int, the total number of books in the database
*/
double calcAvgRating(string title, string titles[], int userRatings[100][50], int numUsers, int numBooks)
{
    double avgRating = 0;
    double count = 0;
    int index = findTitle(title, titles, numBooks);
    
    if(index == -1)
    {
        cout << title << " does not exist in our database" << endl;
        return -1;
    }
    
    if(numUsers <= 0)
    {
        cout << "The database is empty" << endl;
    }
    
    for(int i = 0; i < numUsers; i++)
    {
        if(userRatings[i][index] > 0 && userRatings[i][index] <= 5)
        {
            avgRating += userRatings[i][index];
            count++;
        }
    }
    
    if(count > 0)
    {
        return avgRating /= count;
    }
    
    return avgRating;
}



/* displayMenu:
 * displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */
void displayMenu(){
  cout << "Select a numerical option:" << endl;
  cout << "======Main Menu=====" << endl;
  cout << "1. Read book file" << endl;
  cout << "2. Read user file" << endl;
  cout << "3. Print book list" << endl;
  cout << "4. Find number of books user rated" << endl;
  cout << "5. Get average rating" << endl;
  cout << "6. Quit" << endl;
}


int main(int argc, char const *argv[]) {
    string choice;
    string fileName;
    int numBooks = 0;
    int numUsers = 0;
    string titles[50];
    string authors[50];
    string usernames[100];
    int userRatings[100][50];
    string username;
    string title;
    double b = 0;
    int n = 0;
    int count;

    while (choice != "6")
    {
            displayMenu();
            getline(cin, choice);
            
            switch (stoi(choice))
            {
                case 1:
                    // read book file
                    cout << "Enter a book file name:" << endl;
                    getline(cin, fileName);
                    
                    
                    numBooks = readBooks(fileName, titles, authors, 0, 50);
                    
                    
                    if(numBooks == -1)
                    {
                        cout << "No books saved to the database" << endl;
                    }
                    else
                    {
                        cout << "Total books in the database: " << numBooks << endl;
                    }
                    
                    cout << endl;
                    
                    break;

                case 2:
                    // read user file
                    cout << "Enter a rating file name:" << endl;
                    getline(cin, fileName);
                
                    numUsers = readRatings(fileName, usernames, userRatings, 0, 100, 50);
                    
                    if(numUsers == -1)
                    {
                        cout << "No users saved to database " << endl;
                    }
                    else
                    {
                        cout << "Total users in the database: " << numUsers << endl;
                    }
                    
                    cout << endl;
                    
                    break;

                case 3:
                    // print the list of the books
                    for(int i = 0; i < 50; i++)
                    {
                        if(titles[i] != "")
                        {
                            count++;
                        }
                    }
                    
                    if(count == 0)
                    {
                        cout << "No books are stored" << endl;
                    }
                    else
                    {
                        printAllBooks(titles, authors, numBooks);
                    }
                    
                    cout << endl;
                    
                    break;

                case 4:
                    // find the number of books user read
                    cout << "Enter username:" << endl;
                    getline(cin, username);
                    
                    n = getUserReadCount(username, usernames, userRatings, numUsers, numBooks);
                    
                    if(n != -1)
                    {
                        cout << username << " rated " << n << " books" << endl;
                    }
                    
                    cout << endl;
                    
                    break;

                case 5:
                    // get the average rating of the book
                    cout << "Enter book title:" << endl;
                    getline(cin, title);

                    b = calcAvgRating(title, titles, userRatings, numUsers, numBooks);
                    
                    if(b != -1)
                    {
                        cout << "The average rating for " << title << " is ";
                        cout << fixed << std::setprecision(2) << b << endl;
                    }
                    cout << endl;
                    
                    break;
                    
                case 6:
                    // quit
                    cout << "good bye!" << endl;
                    
                    break;

                default:
                    cout << "invalid input" << endl << endl;
            }
    }

    return 0;
}