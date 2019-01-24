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

/*Highly recommend: Write a helper function that searches the titles array for a
particular book and returns its index.*/
int findTitle(string title, string titles[], int numBooks)
{
    int index = -1;
    
    for(int i = 0; i < numBooks; i++)
    {
        if(titles[i] == title)
        {
            index = i;
        }
    }
    
    if(index == -1)
    {
        cout << title << " does not exist in the database" << endl;
    }
    
    return index;
}

double calcAvgRating(string title, string titles[], int userRatings[100][50], int numUsers, int numBooks)
{
    double avgRating = 0;
    double count = 0;
    int index = findTitle(title, titles, numBooks);
    
    if(index != -1)
    {
        for(int j = 0; j < numUsers; j++)
        {
            if(userRatings[j][index] > 0)
            {
                avgRating += userRatings[j][index];
                count++;
            }
        }
        
        avgRating /= count;
    }
    
    if(count == 0)
    {
        avgRating == -1;
    }
    
    return avgRating;
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
    
    string title;
    double b = 0;
    
    cout << "Enter book title:" << endl;
    getline(cin, title);

    b = calcAvgRating(title, titles, userRatings, numUsers, numBooks);
    
    cout << "The average rating for " << title << " is ";
    std::cout << std::fixed << std::setprecision(2) << b << endl;
    
    cout << endl;
}