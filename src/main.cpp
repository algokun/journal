#include <iostream>
#include <fstream>
#include <vector>
#include "sitebuilder.cpp"
#include "journal.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        string arg(argv[i]);
        if (arg == "add")
        {
            if (argc < i + 2)
            {
                cout << "Error: Title is empty \n";
                return 0;
            }

            add(argv[i+1]);
        }

        if(arg == "build"){
            build();
        }
    }

    return 0;
}