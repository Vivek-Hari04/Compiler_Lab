#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAC 100
#define MAX_LEN 100

int main()
{
    int n, i;
    char line[MAX_LEN];
    char tac[MAX_TAC][MAX_LEN];

    char result[20], op1[20], op2[20], op;  

    printf("Enter number of three-address instructions: ");
    scanf("%d", &n);
    getchar();

    printf("Enter three-address code:\n");

    for (i = 0; i < n; i++)
    {
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';
        strcpy(tac[i], line);
    }

    printf("\n8086 Assembly Code:\n\n");

    for (i = 0; i < n; i++)
    {
        strcpy(line, tac[i]);

        /* Arithmetic operation */
        if (sscanf(line, "%s = %s %c %s",
                   result, op1, &op, op2) == 4)
        {
            printf("MOV AX, %s\n", op1);

            switch (op)
            {
                case '+':
                    printf("ADD AX, %s\n", op2);
                    break;

                case '-':
                    printf("SUB AX, %s\n", op2);
                    break;

                case '*':
                    printf("MOV BX, %s\n", op2);
                    printf("MUL BX\n");
                    break;

                case '/':
                    printf("MOV DX, 0\n");
                    printf("MOV BX, %s\n", op2);
                    printf("DIV BX\n");
                    break;

                default:
                    printf("; Invalid operator\n");
                    continue;
            }

            printf("MOV %s, AX\n", result);
            continue;
        }

        /* Simple assignment */
        if (sscanf(line, "%s = %s", result, op1) == 2)
        {
            printf("MOV AX, %s\n", op1);
            printf("MOV %s, AX\n", result);
            continue;
        }

        printf("; Invalid TAC: %s\n", line);
    }

    return 0;
}