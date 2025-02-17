%{
#include <stdio.h>
%}

%%
charusat   { printf("university"); } 
.|\n       { printf("%s", yytext); }
%%

int yywrap() { return 1; }

int main() {
    yylex();
    return 0;
}
