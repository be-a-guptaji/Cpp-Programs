#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string input;
    cout << "Enter HTML parser input: ";
    getline(cin, input);

    string result;
    bool insideTag = false;

    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] == '<')
        {
            insideTag = true;
        }
        else if (input[i] == '>')
        {
            insideTag = false;
        }
        else if (!insideTag)
        {
            result += input[i];
        }
    }

    // Trim leading spaces
    size_t start = result.find_first_not_of(" ");
    if (start != string::npos)
    {
        result = result.substr(start);
    }

    // Trim trailing spaces
    size_t end = result.find_last_not_of(" ");
    if (end != string::npos)
    {
        result = result.substr(0, end + 1);
    }

    cout << "The HTML parser result is:\n";
    cout << result << endl;

    return 0;
}
