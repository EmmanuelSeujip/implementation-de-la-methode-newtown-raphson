%{
#include "../../utils/type/intervalle.h"
#include "parser_interval.tab.h"
#include <stdlib.h>
%}

/* Règle primordiale pour ne pas faire crasher les autres parseurs */
%option prefix="interval_"
/* Évite d'avoir à définir yywrap manuellement */
%option noyywrap 

%%
"[" { return OPEN; }
"]" { return CLOSE; }
"," { return COMA; }
"-" { return MINUS; }

[0-9]+(\.[0-9]+)? {
    // Utilisation du préfixe interval_ pour l'union sémantique
    interval_lval.doubleval = atof(yytext); 
    return NUMBER;
}

[ \t\n\r]+ ; // Ignorer les espaces et retours à la ligne

. { return yytext[0]; } // Sécurité : renvoyer tout caractère inconnu
%%