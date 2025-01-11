#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

// Function to get the precedence of operators
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

// Function to remove parentheses from the answer
void removeBrackets(string &answer)
{
    answer.erase(remove(answer.begin(), answer.end(), '('), answer.end());
    answer.erase(remove(answer.begin(), answer.end(), ')'), answer.end());
}

// Function to perform the infix to postfix/prefix conversion
void stackSolving(const string &equation, string &answer)
{
    stack<char> opStack;
    opStack.push('('); // Adding an opening bracket to handle the end of the equation.

    for (size_t i = 0; i < equation.size(); ++i)
    {
        char currentChar = equation[i];

        // If the current character is an operand (i.e., number or variable), add it to the answer
        if (precedence(currentChar) == -1)
        {
            answer += currentChar;
        }
        // If the current character is '(', push it to the operator stack
        else if (precedence(currentChar) == 0)
        {
            opStack.push(currentChar);
        }
        // If the current character is ')', pop from the stack until '(' is encountered
        else if (precedence(currentChar) == 4)
        {
            while (!opStack.empty() && opStack.top() != '(')
            {
                answer += opStack.top();
                opStack.pop();
            }
            if (!opStack.empty())
                opStack.pop(); // Remove '(' from the stack
        }
        // If the current character is an operator, pop operators from the stack based on precedence
        else
        {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(currentChar))
            {
                answer += opStack.top();
                opStack.pop();
            }
            opStack.push(currentChar);
        }
    }

    // Pop all remaining operators from the stack
    while (!opStack.empty())
    {
        answer += opStack.top();
        opStack.pop();
    }

    // Remove any parentheses from the final answer
    removeBrackets(answer);
}

int main()
{
    int choice = 1;
    string equation, answer;

    cout << "For Postfix PRESS 1.\nFor Prefix PRESS 2.\nChoose your option: ";
    cin >> choice;
    cin.ignore(); // To consume the newline character after entering the choice

    cout << "Enter the equation without spaces:\n";
    getline(cin, equation); // Safe input handling with getline

    switch (choice)
    {
    case 1:
        // Perform infix to postfix conversion
        stackSolving(equation, answer);
        cout << "\nThe Postfix equation is: " << answer << endl;
        break;

    default:
        // For Prefix, reverse the equation, swap parentheses, and then reverse the result
        for (size_t i = 0; i < equation.size(); ++i)
        {
            if (equation[i] == ')')
                equation[i] = '(';
            else if (equation[i] == '(')
                equation[i] = ')';
        }

        reverse(equation.begin(), equation.end()); // Reverse the equation

        stackSolving(equation, answer);

        reverse(answer.begin(), answer.end()); // Reverse the output to get the prefix notation

        cout << "\nThe Prefix equation is: " << answer << endl;
        break;
    }

    return 0;
}
