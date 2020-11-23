#include <iostream>
#include <fstream>
#include <vector>
#include "sitebuilder.cpp"

using namespace std;

// string parseCSV(string line);
// string createLogItem(string date, string title, string desc)
// {
//     return "<div class='log-item'><div class='log-date'>" + date + "</div><div><div class='date'>" + date + "</div><h1 class='title'>" + title + "</h1><p>" + desc + "</p></div></div>";
// }

int main(int argc, char const *argv[])
{
    string line, content;
    ofstream output;
    ifstream logStore;

    logStore.open("logs.csv");
    output.open("../site/content.html");

    while (getline(logStore, line))
    {
        content += parseCSV(line);
    }

    output << wrapData(content);
    return 0;
}

// string parseCSV(string line)
// {
//     vector<int> indices;

//     for (int i = 0; i < line.size(); i++)
//         if (line[i] == ',')
//             indices.push_back(i);

//     int a = indices[0];
//     int b = indices[1];

//     return createLogItem(line.substr(0, a - 1), line.substr(a + 1, b - 1), line.substr(b + 1, line.size() - 1));
// }