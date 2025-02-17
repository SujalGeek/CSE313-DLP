%{
#include <stdio.h>

int char_count = 0, word_count = 0, line_count = 0;
%}

%%
.           { char_count++; }       // Count all characters including spaces
[^\n ]+     { word_count++; }       // Count words (separated by whitespace)
\n          { line_count++; }       // Count lines
%%

int yywrap() { return 1; }

int main() {
    yylex();
    printf("Characters : %d\n", char_count);
    printf("Words : %d\n", word_count);
    printf("Lines : %d\n", line_count);
    return 0;
}
