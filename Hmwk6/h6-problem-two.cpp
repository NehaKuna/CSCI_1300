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

int main()
{
    string fileName;
    string usernames[100];
    int userRatings[100][50];
    int numUsers = 0;
    
    cout << "Enter a rating file name:" << endl;
    getline(cin, fileName);

    numUsers = readRatings(fileName, usernames, userRatings, numUsers, 100, 50);
    
    if(numUsers != -1)
    {
        cout << "Total users in the database: " << numUsers << endl;
    }
    else
    {
        cout << "No users saved to the database " << endl;
    }
    
    cout << endl;
}