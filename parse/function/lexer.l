%{
#include "utils/type/fonction.h"
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>
%}

%%
"+"   { return ADD; }
"-"   { return SUB; }
"*"   { return MUL; }
"\\"  { return DIV; }
"^"   { return PUIS; }
"exp" { return EXP; }
"ln"  { return LN; }
"sin" { return SIN; }
"cos" { return COS; }
"x"   { return X; }
"("   { return '('; }
")"   { return ')'; }
"tan"  { return TAN;  }
"asin" { return ASIN; }
"acos" { return ACOS; }
"atan" { return ATAN; }
"sqrt" { return SQRT; }
"abs"  { return ABS;  }
"sinh" { return SINH; }
"cosh" { return COSH; }
"tanh" { return TANH; }
"pi"   { yylval.doubleval = 3.14159265358979323846; return NUMBER; }
"e"    { yylval.doubleval = 2.71828182845904523536; return NUMBER; }
[0-9]+(\.[0-9]+)? {
    yylval.doubleval = atof(yytext); // Ou atof pour gérer les décimales directement !
    return NUMBER;
}

[0-9]+"/"[0-9]+ {
    int num, den;
    sscanf(yytext, "%d/%d", &num, &den);
    if (den != 0) {
        yylval.doubleval = (double)num / (double)den;
        return FRACTION;
    } else {
        fprintf(stderr, "Erreur: dénominateur nul dans %s\n", yytext);
        // Gérer l'erreur proprement selon vos besoins
    }
}

[ \t\n\r]+ ; /* Ignorer tous les espaces et retours à la ligne */

%%
int yywrap() { return 1; }