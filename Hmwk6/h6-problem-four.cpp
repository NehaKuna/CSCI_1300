#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

int split(string str, char c, string array[], int size)
{
    if(str.length() == 0)
    {
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
        }
        else
        {
            word = word + str[i];
        }
    }
    
    return count;
}

int readBooks(string fileName, string titles[], string authors[], int numBooks, int capacity)
{
    ifstream myfilestream;
    myfilestream.open(fileName);
    
    if(myfilestream.fail())
    {
        numBooks = -1;
    }
    else if(myfilestream.is_open())
    {
        string s = "";
        int i = 0;
        int count = 0;
        string a[2];
        
        while(getline(myfilestream, s))
        {
            if(s != "")
            {
                split(s, ',', a, 2);
                
                authors[i] = a[0];
                titles[i] = a[1];
            }
            
            i++;
            count++;
        }
        
        numBooks = count;
    }
    
    return numBooks;
}

int readRatings(string fileName, string usernames[], int userRatings[100][50], int numUsers, int rowCapacity, int columnCapacity)
{
    ifstream myfilestream;
    myfilestream.open(fileName);
    
    if(myfilestream.is_open())
    {
        string s = "";
        string x = "";
        int count = 0;
        int i = 0;
        string a[2];
        string b[columnCapacity];
        
        while(getline(myfilestream, s))
        {
            if(s != "")
            {
                split(s, ',', a, 2);
                
                usernames[i] = a[0];
                cout << usernames[i] << "..." << endl;
                
                x = a[1];
                split(x, ' ', b, columnCapacity);
                
                for(int j = 0; j < columnCapacity; j++)
                {
                    userRatings[count][j] = stoi(b[j]);
                }
            }
            
            i++;
            count++;
        }
        
        numUsers = count;
    }
    else if(myfilestream.fail())
    {
        numUsers = -1;
    }
    
    return numUsers;
}

void printAllBooks(string titles[], string authors[], int numBooks)
{
    if(numBooks == 0)
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

int findUser(string username, string usernames[], int numUsers)
{
    int index = -1;
    
    for(int i = 0; i < numUsers; i++)
    {
        if(usernames[i] == username)
        {
            index = i;
        }
    }
    
    if(index == -1)
    {
        cout << username << " does not exist in the database" << endl;
    }
    
    return index;
}

int getUserReadCount(string username, string usernames[], int userRatings[100][50], int numUsers, int numBooks)
{
    int booksRead = 0;
    
    int index = findUser(username, usernames, numUsers);
    
    if(index != -1)
    {
        for(int j = 0; j < numBooks; j++)
        {
            if(userRatings[index][j] >= 0)
            {
                booksRead++;
            }
        }
    }
    
    return booksRead;
}

int main()
{
    string fileName;
    string titles[50];
    string authors[50];
    int numBooks = 0;
    
    cout << "Enter a book file name:" << endl;
    getline(cin, fileName);
    
    
    numBooks = readBooks(fileName, titles, authors, numBooks, 50);
    
    cout << endl;
    
    string usernames[100];
    int userRatings[100][50];
    int numUsers = 0;
    
    cout << "Enter a rating file name:" << endl;
    getline(cin, fileName);

    numUsers = readRatings(fileName, usernames, userRatings, numUsers, 100, 50);

    cout << endl;
    
    string username;
    
    cout << "Enter username:" << endl;
    getline(cin, username);
    
    getUserReadCount(username, usernames, userRatings, numUsers, numBooks);
    
    cout << username << " rated " << numBooks << " books" << endl;
    
    cout << endl;
}