#include <iostream>
#include <fstream>

using namespace std;

string parseMarkdown(string line);

string wrapData(string content)
{
    string start = "<html lang='en'><head><meta charset='UTF-8' /><meta name='viewport' content='width=device-width, initial-scale=1.0' /><title>Journal</title><link rel='stylesheet' href='../site-data/style.css' /></head><body><header>Journal shows recent updates</header><div class='container'><main><div class='log-list'>";
    string end = "</div></main></div></body></html>";
    return start + content + end;
}

string parseCSV(string line)
{
    int a, b, n = line.size();
    for (int i = 0; i < n; i++)
        if (line[i] == '|')
        {
            a = b;
            b = i;
        }

    string date(line.substr(0, a)), title(line.substr(a + 1, b - a - 1)), desc(line.substr(b + 1, n));
    desc = parseMarkdown(desc);
    return "<div class='log-item'><div class='log-date'>" + date + "</div><div><div class='date'>" + date + "</div><h1 class='title'>" + title + "</h1><p>" + desc + "</p></div></div>";
}

void build()
{
    string line, content;
    ofstream output;
    ifstream logStore;

    logStore.open("../site-data/logs.csv");
    output.open("../site/journal.html");

    while (getline(logStore, line))
        content.insert(0, parseCSV(line));

    output << wrapData(content);
    cout << "Site build successfully\n";
}

// the only allowed markdown is images and links
// [hello](link) -> <a href = "link">hello</a>
// ![alt](img-link) -> <img src = "img-link" alt="alt" />

string parseMarkdown(string line) {
    
    int size = line.size();
    int i = 0;
    
    // find if there's markdown link or image
    for (; i < size; i++){
        if(line[i] == '[') break;
    }
    
    // return the line as it is if there's no markdown
    if(i == size) return line;
    
    bool isImg = line[i-1] == '!'; // sanity check for img

    string link = "",alias = "";
    int start = i;

    while(line[++i] != ']') link += line[i]; // storing link
    i+=2;
    
    while(line[i] != ')') alias += line[i++]; // storing alias

    string text = isImg ? line.substr(0, start-1) : line.substr(0, start);
    string html = isImg ? "<img src = '" + link + "' alt = '" + alias + "'/>" : "<a href = '" + link + "'>" + alias + "</a>";
    return text + html + line.substr(i+1, size);
}