#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
    char infix[100], postfix[100];
    int top = -1, i, j = 0;
    char stack[100];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            top--;
        }
        else
        {
            while (top != -1 && stack[top] != '(' && stack[top] != ')')
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    while (top != -1)
    {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';

    printf("The postfix expression is: %s", postfix);

    return 0;
}