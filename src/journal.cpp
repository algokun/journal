#include <iostream>
#include <fstream>
using namespace std;

void add(string title)
{
    string desc;
    ofstream logStore;
    logStore.open("logs.csv", ios_base::app);
    
    cout << "Enter description (markdown allowed): \n";
    getline(cin, desc);

    logStore << "23-11-20, " << title << ", " << desc << "\n";
    cout << title << " added successfully \n";
}