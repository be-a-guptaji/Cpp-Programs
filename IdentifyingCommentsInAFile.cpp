#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to check for comments
void checkForComments(const string &line, int &isCommentStarted, int lineNumber)
{
    for (size_t i = 0; i < line.length(); i++)
    {
        if (line[i] == '/' && i + 1 < line.length() && line[i + 1] == '/' && isCommentStarted == 0)
        {
            isCommentStarted = 1;
            cout << "\nSingle line comment at line number: " << lineNumber << "\n";
        }

        if (line[i] == '/' && i + 1 < line.length() && line[i + 1] == '*' && isCommentStarted == 0)
        {
            isCommentStarted = 2;
            cout << "\nMulti line comment started at line number: " << lineNumber << "\n";
        }

        if (line[i] == '*' && i + 1 < line.length() && line[i + 1] == '/' && isCommentStarted == 2)
        {
            cout << "*/\n";
            cout << "Multi line comment ended at line number: " << lineNumber << "\n";
            isCommentStarted = 0;
        }

        if (isCommentStarted != 0)
        {
            cout << line[i];
        }
    }

    if (isCommentStarted == 1)
    {
        isCommentStarted = 0; // reset after single-line comment
    }
}

int main()
{
    ifstream file("comments.txt");
    string line;
    int isCommentStarted = 0;
    int lineNumber = 1;

    if (!file.is_open())
    {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    while (getline(file, line))
    {
        checkForComments(line, isCommentStarted, lineNumber);
        lineNumber++;
    }

    file.close();
    return 0;
}
