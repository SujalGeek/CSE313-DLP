%{
#include <stdio.h>
%}

%%
[0-9]+    { printf("%s\n", yytext); }
.         { /* Ignore non-numeric characters */ }
\n        { return 0; }
%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
