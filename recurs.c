#include <stdio.h>
#include <stdlib.h>

char input[100];
int pos = 0;

void E();
void Eprime();
void T();
void Tprime();
void F();

void error()
{
    printf("String is rejected!\n");
    exit(0);
}

// E -> T E'
void E()
{
    T();
    Eprime();
}

// E' -> + T E' | epsilon
void Eprime()
{
    if (input[pos] == '+')
    {
        pos++;
        T();
        Eprime();
    }
}

// T -> F T'
void T()
{
    F();
    Tprime();
}

// T' -> * F T' | epsilon
void Tprime()
{
    if (input[pos] == '*')
    {
        pos++;
        F();
        Tprime();
    }
}

// F -> ( E ) | a | b | c
void F()
{
    if (input[pos] == 'a' ||
        input[pos] == 'b' ||
        input[pos] == 'c')
    {
        pos++;
    }
    else if (input[pos] == '(')
    {
        pos++;
        E();

        if (input[pos] == ')')
            pos++;
        else
            error();
    }
    else
    {
        error();
    }
}

int main()
{
    printf("Enter the input string: ");
    scanf("%99s", input);

    E();

    if (input[pos] == '\0')
        printf("String is accepted!\n");
    else
        printf("String is rejected!\n");

    return 0;
}

/*For grammer :
    E  → T E'
    E' → + T E' | ε
    T  → F T'
    T' → * F T' | ε
    F  → ( E ) | a | b | c    

*/