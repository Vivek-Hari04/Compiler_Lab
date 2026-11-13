#include <stdio.h>
#include <string.h>
#include <ctype.h>

char expr[100];
char op1[20], op2[20], result[20];
char temp[10];
int t = 1;

void generate()
{
    int i, j = 0;
    char op;

    for (i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] == '*' || expr[i] == '/')
        {
            op = expr[i];

            op1[0] = expr[i - 1];
            op1[1] = '\0';

            op2[0] = expr[i + 1];
            op2[1] = '\0';

            sprintf(temp, "t%d", t);

            printf("%s = %s %c %s\n", temp, op1, op, op2);

            expr[i - 1] = temp[0];
            expr[i] = '\0';

            for (j = i + 1; expr[j] != '\0'; j++)
                expr[j - 1] = expr[j];

            t++;
            i--;
        }
    }

    for (i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] == '+' || expr[i] == '-')
        {
            op = expr[i];

            op1[0] = expr[i - 1];
            op1[1] = '\0';

            op2[0] = expr[i + 1];
            op2[1] = '\0';

            sprintf(temp, "t%d", t);

            printf("%s = %s %c %s\n", temp, op1, op, op2);

            t++;
        }
    }
}

int main()
{
    printf("Enter an arithmetic expression: ");
    scanf("%99s", expr);

    generate();

    return 0;
}