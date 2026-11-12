%{
    #include <stdio.h>
    #include <stdlib.h>

    int vowels = 0;
    int consonants = 0;
    int digits = 0;
    int spaces = 0;
%}

%%
[aeiouAEIOU] { vowels++; }
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z] { consonants++; }
[0-9] { digits++; }
[] { spaces++; }
\n {/*ignore newline*/}
. {}

%%

int main(){
    printf("Enter a string: ");
    yylex();
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n", spaces);

    return 0;
}

int yywrap() {
    return 1;
}