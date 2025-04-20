#include <iostream>
#include <string>

using namespace std;

bool currentChar(int i, const string &str);
bool check011(int i, const string &str);

bool currentChar(int i, const string &str)
{
    if (i >= str.length())
    {
        return false;
    }
    else if (str[i] == '1')
    {
        return currentChar(i + 1, str);
    }
    else if (str[i] == '0')
    {
        return check011(i, str);
    }
    else
    {
        return false;
    }
}

bool check011(int i, const string &str)
{
    if (i + 3 == str.length() &&
        str[i] == '0' && str[i + 1] == '1' && str[i + 2] == '1')
    {
        return true;
    }
    else
    {
        return currentChar(i + 1, str);
    }
}

int main()
{
    string str;
    cout << "Enter the string: ";
    getline(cin, str); // Safe input

    if (currentChar(0, str))
    {
        cout << "The string matches the regular expression (1+0)*011." << endl;
    }
    else
    {
        cout << "The string does not match the regular expression (1+0)*011." << endl;
    }

    return 0;
}
