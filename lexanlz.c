#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    char token[50];

    char keywords[10][10] = {
        "int", "float", "char", "if", "else",
        "while", "for", "return", "void", "double"
    };

    int i = 0, j, k;

    printf("Enter an expression: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0')
    {
        // Ignore spaces
        if (isspace(str[i]))
        {
            i++;
            continue;
        }

        // Identify identifiers and keywords
        if (isalpha(str[i]) || str[i] == '_')
        {
            j = 0;

            while (isalnum(str[i]) || str[i] == '_')
            {
                token[j++] = str[i++];
            }

            token[j] = '\0';

            int flag = 0;

            for (k = 0; k < 10; k++)
            {
                if (strcmp(token, keywords[k]) == 0)
                {
                    flag = 1;
                    break;
                }
            }

            if (flag)
                printf("%s : KEYWORD\n", token);
            else
                printf("%s : IDENTIFIER\n", token);
        }

        // Identify numbers
        else if (isdigit(str[i]))
        {
            j = 0;

            while (isdigit(str[i]))
            {
                token[j++] = str[i++];
            }

            token[j] = '\0';

            printf("%s : NUMBER\n", token);
        }

        // Identify operators
        else if (strchr("+-*/=%<>!", str[i]))
        {
            printf("%c : OPERATOR\n", str[i]);
            i++;
        }

        // Identify special symbols
        else
        {
            printf("%c : SPECIAL SYMBOL\n", str[i]);
            i++;
        }
    }

    return 0;
}