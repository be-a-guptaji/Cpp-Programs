#include <stdio.h>
#include <conio.h>
#include <string.h>

int i = 0, first = 0, second = 0, last = 0;

void characterinanswer(char *answer, char *equation)
{
    answer[first++] = equation[i];
}

void push(char *equation, char *operators)
{
    operators[second++] = equation[i];
}

void pop(char *answer, char *operators)
{
    answer[first++] = operators[--second];
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
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

void removebrackets(char *answer)
{
    for (int i = 0; answer[i] != '\0'; i++)
    {
        if (answer[i] == '(')
        {
            int j = i;
            while (answer[j] != '\0')
            {
                answer[j] = answer[++j];
            }
        }
    }
}

void stacksolving(char *equation, char *answer, char *operators)
{
    operators[second++] = '(';

    for (i = 0; equation[i] != '\0'; ++i)
    {
        if (precedence(equation[i]) == -1)
        {
            characterinanswer(answer, equation);
        }
        else if (precedence(equation[i]) == 0)
        {
            push(equation, operators);
        }
        else if (precedence(equation[i]) == 4)
        {
            while (operators[second] != '(')
            {
                pop(answer, operators);
            }
        }
        else
        {
        checkagain:
            if (precedence(equation[i]) == 3)
            {
                push(equation, operators);
                last = 0;
            }
            else if (precedence(operators[second - 1]) < precedence(equation[i]))
            {
                push(equation, operators);
                last = 0;
            }
            else if (precedence(operators[second - 1]) >= precedence(equation[i]))
            {
                pop(answer, operators);
                last = 1;
            }
            if (last == 1)
            {
                goto checkagain;
            }
        }
    }

    operators[second] = '\0';

    while (second != 0)
    {
        if (operators[second - 1] == '(')
        {
            second--;
            continue;
        }
        pop(answer, operators);
    }

    answer[first] = '\0';
    first = second = 0;
    removebrackets(answer);
}

int main()
{
    int choice = 1;

    char equation[25], answer[25], operators[12];

    printf("For Postfix PRESS 1.\nFor Prefix PRESS 2.\nChose your option : \t");
    scanf("%d", &choice);
    getchar();

    printf("Enter the equation without spaces.\nEnter : \t");
    gets(equation);

    switch (choice)
    {
    case 1:
    {
        stacksolving(equation, answer, operators);
        printf("\nThe Postfix equation of above equation is : \t");
        puts(answer);
        break;
    }
    default:
    {
        for (i = 0; '\0' != equation[i]; i++)
        {
            if (equation[i] == ')')
            {
                equation[i] = '1';
            }
            if (equation[i] == '(')
            {
                equation[i] = '0';
            }
            if (equation[i] == '0')
            {
                equation[i] = ')';
            }
            if (equation[i] == '1')
            {
                equation[i] = '(';
            }
        }
        strrev(equation);
        stacksolving(equation, answer, operators);
        strrev(answer);
        printf("\nThe Prefix equation of above equation is : ");
        puts(answer);
    }
    }

    return 0;
}