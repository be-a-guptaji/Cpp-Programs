#include <iostream>
#include <cctype>
#include <string>

using namespace std;

// Function to check if a string is a valid C identifier
bool isValidIdentifier(const string &str)
{
    if (str.empty())
        return false;

    // First character must be a letter or underscore
    if (!isalpha(str[0]) && str[0] != '_')
        return false;

    // Remaining characters must be alphanumeric or underscore
    for (size_t i = 1; i < str.length(); ++i)
    {
        if (!isalnum(str[i]) && str[i] != '_')
            return false;
    }

    return true;
}

int main()
{
    string identifier;

    cout << "Enter an identifier: ";
    getline(cin, identifier); // safer than gets()

    if (isValidIdentifier(identifier))
    {
        cout << "'" << identifier << "' is a valid identifier in C." << endl;
    }
    else
    {
        cout << "'" << identifier << "' is NOT a valid identifier in C." << endl;
    }

    return 0;
}
