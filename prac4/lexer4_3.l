%{
#include <stdio.h>
#include <stdlib.h>
int wcount = 0;
int lcount = 0;
int ccount = 0;
%}

%%
([a-zA-Z0-9])* { wcount++; ccount+=yyleng;}
\n             {lcount++;}
%%


int main() {
    FILE *file;
    file = fopen("sample.txt","r");
    if(!file){
              printf("Error");
    }
    yyin = file;
    yylex();
    printf("Word count: %d\n", wcount);
    printf("line count: %d\n", lcount);
    printf("Character count: %d\n", ccount);
    fclose(yyin);
    return 0;
}

int yywrap() {}