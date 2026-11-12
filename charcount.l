%{
    #include <stdio.h>
    #include <stdlib.h>

    int characters=0;
    int words=0;
    int lines=0;
    int spaces=0;
%}
%%
[a-zA-Z0-9]+ { words++; characters += yyleng; }
[ \t] { spaces++; characters += yyleng; }
\n { lines++; characters++; }
.   { characters++; }

%%

int main(){
    printf("Enter a string: ");
    yylex();
    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);
    printf("Spaces: %d\n", spaces);

    return 0;
}

int yywrap() {
    return 1;
}