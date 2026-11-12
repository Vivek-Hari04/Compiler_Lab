%{
    #include <stdio.h>
    #include <stdlib.h>
%}

%%

"int"|"float"|"char"|"double"|"void"|"if"|"else"|"do"|"while"|"for"|"return"|"break"|"continue"|"switch"|"case"|"default"|"struct"|"union"|"enum"|"typedef"|"sizeof" {printf("%s : KEYWORD\n",yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {printf("%s : IDENTIFIER\n",yytext);}
[0-9]+\.[0-9]+ {printf("%s : FLOAT_CONSTANT\n",yytext);}
[0-9]+ {printf("%s : INTEGER_CONSTANT\n",yytext);}

"++"|"--"|"=="|"!="|"<="|">="|"&&"|"||"|"+="|"-="|"*="|"/="|"%=" {printf("%s : OPERATOR\n",yytext);}
[+\-*/%=<>!] {printf("%s : OPERATOR\n",yytext);}

[;\(\)\{\}\[\]] {printf("%s : SPECIAL SYMBOL\n",yytext);}
[ \t\n]+ ; // Ignore whitespace
. {printf("%s : UNKNOWN SYMBOL\n",yytext);}

%%

int main() {
    printf("Enter C code (Ctrl+D to end):\n");
    yylex();
    return 0;
}
int yywrap()
{
    return 1;
}