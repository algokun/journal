#include <iostream>
#include <fstream>

using namespace std;

// string createLogItem(string date, string title, string desc)
// {
//     return "<div class='log-item'><div class='log-date'>" + date + "</div><div><div class='date'>" + date + "</div><h1 class='title'>" + title + "</h1><p>" + desc + "</p></div></div>";
// }

string wrapData(string content)
{
    string start = "<html lang='en'><head><meta charset='UTF-8' /><meta name='viewport' content='width=device-width, initial-scale=1.0' /><title>Journal</title><link rel='stylesheet' href='../assets/style.css' /></head><body><header>Journal shows recent updates</header><div class='container'><main><div class='log-list'>";
    string end = "</div></main></div></body></html>";
    return start + content + end;
}

string parseCSV(string line)
{
    int a, b, n = line.size();
    for (int i = 0; i < n; i++)
        if (line[i] == ',')
        {
            a = b;
            b = i;
        }

    string date(line.substr(0, a)), title(line.substr(a + 1, b - a - 1)), desc(line.substr(b + 1, n));
    return "<div class='log-item'><div class='log-date'>" + date + "</div><div><div class='date'>" + date + "</div><h1 class='title'>" + title + "</h1><p>" + desc + "</p></div></div>";
}

void build(){
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
    cout << "Site build successfully\n";
}