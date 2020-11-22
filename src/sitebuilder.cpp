#include <iostream>

using namespace std;

// string createLogItem(string date, string title, string desc)
// {
//     return "<div class='log-item'><div class='log-date'>" + date + "</div><div><div class='date'>" + date + "</div><h1 class='title'>" + title + "</h1><p>" + desc + "</p></div></div>";
// }

string parseCSV(string line)
{
    int a, b, n = line.size();
    for (int i = 0; i < n; i++)
        if (line[i] == ',')
        {
            a = b;
            b = i;
        }

    string date(line.substr(0, a - 1)), title(line.substr(a + 1, b - 1)), desc(line.substr(b + 1, n - 1));
    return "<div class='log-item'><div class='log-date'>" + date + "</div><div><div class='date'>" + date + "</div><h1 class='title'>" + title + "</h1><p>" + desc + "</p></div></div>";
}