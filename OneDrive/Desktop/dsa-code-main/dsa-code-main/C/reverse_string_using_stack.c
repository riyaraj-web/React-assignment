#include <stdio.h>
#include <string.h>
#define MAX_SIZE 50
char stack[MAX_SIZE];
int top = -1; 
void push(char item) 
{
    if (top >= MAX_SIZE - 1) 
	{
        printf("Stack Overflow!\n");
    }
	else 
	{
        stack[++top] = item;
    }
}
char pop() 
{
    if (top == -1) 
	{
        printf("Stack Underflow!\n");
    	return '\0';
    }
	else 
	{
        return stack[top--];
    }
}
int main() 
{
    char str[MAX_SIZE];
    int i;
    printf("Enter a string: ");
    gets(str);
    str[strlen(str)] ='\0';
    for (i = 0; i < strlen(str); i++)
	{
        push(str[i]);
    }
    printf("Reversed string: ");
    while (top != -1)
	{
        printf("%c", pop());
    }
    printf("\n");
    return 0;
}