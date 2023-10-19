#include <stdio.h>
#include <ctype.h>
#include <string.h>


int operator(char ch) 
{
    char operators[] = "+-*/=<>^";
    for (int i = 0; i < strlen(operators); i++) 
    {
        if (ch == operators[i]) {
            return 1;
        }
    }
    return 0;
}

int punctuation(char ch) 
{
    char punctuations[] = ",;:(){}[]?!|&`~'\"";
    for (int i = 0; i < strlen(punctuations); i++) 
    {
        if (ch == punctuations[i]) 
        {
            return 1;
        }
    }
    return 0;
}

int keyword(char* str) 
{
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default","do", "double", "else", "enum", "extern", "float", "for","goto", "if", "int", "long", "register", "return", "short",
                             "signed", "sizeof", "static", "struct", "switch", "typedef","union", "unsigned", "void", "volatile", "while"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return 1;
        }
    }
    return 0;
}

int identifier(char* str) 
{
    if (!isalpha(str[0])) 
    {
        return 0;
    }
    for (int i = 1; i < strlen(str); i++) 
    {
        if (!isalnum(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

int number(char* str) {
    for (int i = 0; i < strlen(str); i++) 
    {
        if (!isdigit(str[i])) 
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    FILE* file = fopen("filename", "r");
    char line[100];
    int lineNo = 1;

    printf("Token\t\tType\t\tLine No.\n");

    while (fgets(line, sizeof(line), file)) 
    {
        char* token = strtok(line, " \t\n");
        while (token != NULL) 
        {
            if (keyword(token)) 
            {
                printf("%s\t\tKeyword\t\t%d\n", token, lineNo);
            }
            else if (punctuation(token[0])) 
            {
                printf("%s\t\tPunctuation\t%d\n", token, lineNo);
            } 
            else if (operator(token[0])) 
            {
                printf("%s\t\tOperator\t%d\n", token, lineNo);
            } 
            else if (identifier(token)) 
            {
                printf("%s\t\tIdentifier\t%d\n", token, lineNo);
            } 
            else if (number(token)) 
            {
                printf("%s\t\tNumber\t\t%d\n", token, lineNo);
            } 
            else if(token[0]=='#'|token[0]=='.')
	    {
	    	printf("%s\t\tSpecial symbol\t%d\n", token, lineNo);
	    }

	    else
            {
                printf("%s\t\tInvalid\t\t%d\n", token, lineNo);
            }
            token = strtok(NULL, " \t\n");
        }
        lineNo++;
    }

    fclose(file);
}

