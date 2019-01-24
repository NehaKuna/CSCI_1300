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

int main()
{
    string fileName;
    string titles[50];
    string authors[50];
    int numBooks = 0;
    
    cout << "Enter a book file name:" << endl;
    getline(cin, fileName);
    
    
    numBooks = readBooks(fileName, titles, authors, numBooks, 50);
    
    
    if(numBooks != -1)
    {
        cout << "Total books in the database: " << numBooks << endl;
    }
    else
    {
        cout << "No books saved to the database" << endl;
    }
    
    cout << endl;
    
    
    printAllBooks(titles, authors, numBooks);
}