%{
    #include "../../utils/tree/tree.h"
    #include <stdio.h>
    #include <stdlib.h>

    int yylex(void);
    void yyerror(const char *s);
    
    // Pointeur global temporaire pour récupérer le résultat du parseur
    Fonction fonction_resultat = NULL;

    // Déclarations des fonctions Flex pour lire depuis une chaîne
    typedef struct yy_buffer_state *YY_BUFFER_STATE;
    extern YY_BUFFER_STATE yy_scan_string(const char *str);
    extern void yy_delete_buffer(YY_BUFFER_STATE buffer);
%}

%union {
    double doubleval;
    double val;
    struct Noeud *noeud;
}

%token <doubleval> NUMBER
%token <val>    FRACTION
%token ADD SUB MUL DIV PUIS LN SIN COS EXP X
%token TAN ASIN ACOS ATAN SQRT ABS SINH COSH TANH 

%type <noeud> expression function

%left  ADD SUB
%left  MUL DIV
%right PUIS


/* La racine de notre grammaire attrape l'expression et la stocke */
%%
calc
    : expression { fonction_resultat = $1; }
    ;

expression
    : NUMBER                  { $$ = new_node(NODE_CONST, (double)$1, NULL, NULL); }
    | FRACTION                { $$ = new_node(NODE_CONST, $1, NULL, NULL); }
    | X                       { $$ = new_node(NODE_VAR, 0, NULL, NULL); }
    | '(' expression ')'      { $$ = $2; }
    | expression ADD expression { $$ = new_node(NODE_ADD, 0, $1, $3); }
    | expression SUB expression { $$ = new_node(NODE_SUB, 0, $1, $3); }
    | expression MUL expression { $$ = new_node(NODE_MUL, 0, $1, $3); }
    | expression DIV expression { $$ = new_node(NODE_DIV, 0, $1, $3); }
    | expression PUIS expression{ $$ = new_node(NODE_PUIS, 0, $1, $3); }
    | function '(' expression ')' { $1->gauche = $3; $$ = $1; }
    ;

function
    : SIN  { $$ = new_node(NODE_SIN,  0, NULL, NULL); }
    | COS  { $$ = new_node(NODE_COS,  0, NULL, NULL); }
    | LN   { $$ = new_node(NODE_LOG,  0, NULL, NULL); }
    | EXP  { $$ = new_node(NODE_EXP,  0, NULL, NULL); }
    | TAN  { $$ = new_node(NODE_TAN,  0, NULL, NULL); }
    | ASIN { $$ = new_node(NODE_ASIN, 0, NULL, NULL); }
    | ACOS { $$ = new_node(NODE_ACOS, 0, NULL, NULL); }
    | ATAN { $$ = new_node(NODE_ATAN, 0, NULL, NULL); }
    | SQRT { $$ = new_node(NODE_SQRT, 0, NULL, NULL); }
    | ABS  { $$ = new_node(NODE_ABS,  0, NULL, NULL); }
    | SINH { $$ = new_node(NODE_SINH, 0, NULL, NULL); }
    | COSH { $$ = new_node(NODE_COSH, 0, NULL, NULL); }
    | TANH { $$ = new_node(NODE_TANH, 0, NULL, NULL); }
    ;

%%

void yyerror(const char *s) {
    // Peut être rendu silencieux si vous gérez l'erreur en amont
    fprintf(stderr, "Erreur de syntaxe : %s\n", s);
}


Fonction parse_expression(const char* expr_str) {
    fonction_resultat = NULL; // Réinitialisation par sécurité
    
    // Demande à Flex de lire la chaîne passée en paramètre
    YY_BUFFER_STATE buffer = yy_scan_string(expr_str);
    
    // Lancer le parsing
    int status = yyparse();
    
    // Nettoyer le buffer Flex
    yy_delete_buffer(buffer);
    
    // yyparse retourne 0 si succès, 1 si erreur syntaxique
    if (status == 0) {
        return fonction_resultat;
    } else {
        return NULL; // Ce n'est pas une fonction mathématique valide
    }
}