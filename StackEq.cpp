#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    case '(':
        return 0;
    case ')':
        return 4;
    default:
        return -1;
    }
}

void removeBrackets(string &answer)
{
    answer.erase(remove(answer.begin(), answer.end(), '('), answer.end());
    answer.erase(remove(answer.begin(), answer.end(), ')'), answer.end());
}

void stackSolving(const string &equation, string &answer, stack<char> &operators)
{
    operators.push('(');
    int i = 0;
    while (i < equation.size())
    {
        char currentChar = equation[i];

        if (precedence(currentChar) == -1)
        {
            answer += currentChar; // Operand (number/variable)
        }
        else if (precedence(currentChar) == 0)
        {
            operators.push(currentChar); // Opening bracket '('
        }
        else if (precedence(currentChar) == 4)
        {
            // Closing bracket ')'
            while (operators.top() != '(')
            {
                answer += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop '('
        }
        else
        {
            // Handle operators
            while (!operators.empty() && precedence(operators.top()) >= precedence(currentChar))
            {
                answer += operators.top();
                operators.pop();
            }
            operators.push(currentChar);
        }
        ++i;
    }

    // Pop all remaining operators in the stack
    while (!operators.empty())
    {
        answer += operators.top();
        operators.pop();
    }

    removeBrackets(answer); // Remove brackets
}

int main()
{
    int choice = 1;
    string equation, answer;
    stack<char> operators;

    cout << "For Postfix PRESS 1.\nFor Prefix PRESS 2.\nChoose your option: ";
    cin >> choice;
    cin.ignore(); // Clear the input buffer

    cout << "Enter the equation without spaces.\nEnter: ";
    getline(cin, equation);

    switch (choice)
    {
    case 1:
        stackSolving(equation, answer, operators);
        cout << "\nThe Postfix equation of the above equation is: " << answer << endl;
        break;

    case 2:
    {
        // To handle prefix conversion, reverse the equation and treat '(' as ')', and vice versa
        reverse(equation.begin(), equation.end());
        for (char &ch : equation)
        {
            if (ch == ')')
            {
                ch = '1';
            }
            else if (ch == '(')
            {
                ch = ')';
            }
            else if (ch == '1')
            {
                ch = '(';
            }
        }
        stackSolving(equation, answer, operators);
        reverse(answer.begin(), answer.end());
        cout << "\nThe Prefix equation of the above equation is: " << answer << endl;
        break;
    }

    default:
        cout << "Invalid choice!" << endl;
        break;
    }

    return 0;
}
