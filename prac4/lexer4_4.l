%{
#include <stdio.h>

int upper = 0;
int lower = 0;
int digit = 0;
int special = 0;
int length = 0;
%}

%%

[A-Z]       { upper = 1; length++; }
[a-z]       { lower = 1; length++; }
[0-9]       { digit = 1; length++; }
[!@#$%^&*]  { special = 1; length++; }
.           { length++; }
\n          {return 0;}
%%

int main() {
    printf("Enter a password: ");
    yylex();

    if (length < 9 || length >15) {
        printf("Invalid password: length should be in 9 to 15 .\n");
    } else if (!upper) {
        printf("Invalid password: Password must contain at least one uppercase letter.\n");
    } else if (!lower) {
        printf("Invalid password: Password must contain at least one lowercase letter.\n");
    } else if (!digit) {
        printf("Invalid password: Password must contain at least one digit.\n");
    } else if (!special) {
        printf("Invalid password: Password must contain at least one special character.\n");
    } else {
        printf("Valid password!\n");
    }
    return 0;
}

int yywrap() {}