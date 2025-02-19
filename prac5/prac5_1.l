%{
#include <stdio.h>
#include <string.h>
%}

%%
"int"|"char"|"float"|"double"|"return"|"if"|"else"|"for"|"while"|"do"|"switch"|"case"|"break"|"continue" {
    printf("Keyword: %s\n", yytext);
}

[a-zA-Z_][a-zA-Z0-9_]* {
    printf("Identifier: %s\n", yytext);
}

[0-9]+ {
    printf("Constant: %s\n", yytext);
}

"'"[^']"'" {
    printf("String: %s\n", yytext);
}

\"[^\"]*\" {
    printf("String: %s\n", yytext);
}

[+\-*/=<>!&|] {
    printf("Operator: %s\n", yytext);
}

[{}()\[\],;] {
    printf("Punctuation: %s\n", yytext);
}

\/\/.* {
    printf("Comment: %s\n", yytext);
}

\/\*([^*]|\*+[^*/])*\*+\/ {
    printf("Comment: %s\n", yytext);
}

[ \t\n] ;  // Ignore whitespaces

. {
    printf("Lexical Error: %s\n", yytext);
}
%%

// Add this function to fix the error
int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}
