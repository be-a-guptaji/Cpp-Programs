#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std; // Enables use of standard library components without std:: prefix

string replaceword(const string &str, const string &oldword, const string &newword)
{
    string resultstring = str;
    size_t pos = 0;

    while ((pos = resultstring.find(oldword, pos)) != string::npos)
    {
        resultstring.replace(pos, oldword.length(), newword);
        pos += newword.length(); // Move past the new word
    }

    return resultstring;
}

int main()
{
    string name, item, outlet, str;
    ifstream bill("bill.txt");
    ofstream generated("generated.txt");

    if (!bill.is_open())
    {
        cerr << "Error opening bill.txt for reading." << endl;
        return 1;
    }

    if (!generated.is_open())
    {
        cerr << "Error opening generated.txt for writing." << endl;
        return 1;
    }

    // Read content of the bill file
    getline(bill, str, '\0'); // Read entire file content
    cout << "\nThe old format was : \n\n"
         << str << "\n\n";

    cout << "Enter Payer's name: ";
    getline(cin, name);

    cout << "Enter item purchased: ";
    getline(cin, item);

    cout << "Enter outlet name: ";
    getline(cin, outlet);

    // Replace placeholders with actual values
    string generatedbill = replaceword(str, "{{name}}", name);
    generatedbill = replaceword(generatedbill, "{{item}}", item);
    generatedbill = replaceword(generatedbill, "{{outlet}}", outlet);

    cout << "\nThe actual bill generated is : \n\n"
         << generatedbill << "\n\n";

    // Write the generated bill to the file
    generated << generatedbill;

    // Close files
    bill.close();
    generated.close();

    return 0;
}
