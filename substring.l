%{
    #include <stdio.h>
    #include <stdlib.h>

%}
//substring conversion abc to ABC
%%

"abc" {printf("ABC");}
.   {printf("%s", yytext);}

%%
int main() {
    printf("Enter text: ");
    yylex();
    return 0;
}
int yywrap() {
    return 1;
}