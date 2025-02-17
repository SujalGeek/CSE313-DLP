%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculate_power(int base, int exponent) {
    long long result = pow(base, exponent);
    printf("%d *** %d = %lld\n", base, exponent, result);
}
%}

%%
charusat            { printf("university"); }
[0-9]+[ ]*\*\*\*[ ]*[0-9]+ {
                        int base, exponent;
                        sscanf(yytext, "%d *** %d", &base, &exponent);
                        calculate_power(base, exponent);
                    }
.|\n               { printf("%s", yytext); }
%%

int yywrap() { return 1; }

int main() {
    yylex();
    return 0;
}
