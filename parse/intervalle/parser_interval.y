%{
    #include "../../utils/type/intervalle.h"
    #include <stdio.h>
    #include <stdlib.h>

    // Utilisation du nouveau préfixe
    int interval_lex(void);
    void interval_error(const char *s);

    // Variable temporaire pour stocker le résultat avant de le retourner
    Intervalle* resultat_intervalle = NULL;

    // Fonctions Flex pour lire depuis une chaîne de caractères
    typedef struct yy_buffer_state *YY_BUFFER_STATE;
    extern YY_BUFFER_STATE interval__scan_string(const char *str);
    extern void interval__delete_buffer(YY_BUFFER_STATE buffer);
%}

/* Règle primordiale pour Bison */
%define api.prefix {interval_}

%union {
    double doubleval;
}

%token <doubleval> NUMBER
%token OPEN CLOSE COMA MINUS
%type  <doubleval> nombre     /* ← C'est ça qui manque */

%%

entree: S ;



/* Nouvelle règle intermédiaire */
nombre
    : NUMBER          { $$ = $1; }
    | MINUS NUMBER    { $$ = -$2; }
    ;

S: OPEN nombre COMA nombre CLOSE
    { 
        resultat_intervalle = (Intervalle*)malloc(sizeof(Intervalle));
        if (resultat_intervalle != NULL) {
            resultat_intervalle->a = $2;
            resultat_intervalle->b = $4;
        }
    }
 ;
%%

void interval_error(const char *s) {
    // Affichage optionnel de l'erreur (peut être supprimé pour un mode silencieux)
    fprintf(stderr, "Erreur de syntaxe intervalle : %s\n", s);
}

/* =========================================================
 * La fonction appelée par ton code mère
 * ========================================================= */
Intervalle* parse_interval(const char* expr_str) {
    resultat_intervalle = NULL; // Sécurité : réinitialiser
    
    // Demande à Flex de lire la chaîne
    YY_BUFFER_STATE buffer = interval__scan_string(expr_str);
    
    // Lancer le parsing (retourne 0 si succès)
    int status = interval_parse();
    
    // Nettoyer la mémoire tampon Flex
    interval__delete_buffer(buffer);
    
    if (status == 0 && resultat_intervalle != NULL) {
        // Optionnel : Vérifier sémantiquement que a <= b
        if (resultat_intervalle->a > resultat_intervalle->b) {
            fprintf(stderr, "Erreur sémantique : La borne min est supérieure à la borne max.\n");
            free(resultat_intervalle);
            return NULL;
        }
        return resultat_intervalle;
    } else {
        return NULL; // Retourne NULL en cas d'erreur de syntaxe
    }
}