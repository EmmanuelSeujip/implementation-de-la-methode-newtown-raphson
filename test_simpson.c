#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inclusion de vos structures et en-têtes
#include "utils/type/fonction.h"
#include "utils/type/intervalle.h"
#include "blackbox/methods/simpson/simpson.h"

// Déclaration des fonctions externes de votre analyseur (Lex/Yacc)
extern Fonction parse_expression(const char* expr);
extern void free_tree(Fonction f);

int main() {
    char expression[256];
    Intervalle I;
    int n;

    printf("=== TEST LOCAL : METHODE DE SIMPSON ===\n");
    
    // 1. Saisie de la fonction
    printf("Entrez la fonction f(x) (ex: x^2 + 2*x) : ");
    if (fgets(expression, sizeof(expression), stdin) != NULL) {
        // Nettoyage du saut de ligne
        expression[strcspn(expression, "\n")] = 0;
    }

    // 2. Saisie de l'intervalle
    printf("Entrez la borne inferieure (a) : ");
    scanf("%lf", &I.a); 

    printf("Entrez la borne superieure (b) : ");
    scanf("%lf", &I.b); 

    // 3. Saisie du nombre de subdivisions
    printf("Entrez le nombre de sous-intervalles (n) : ");
    scanf("%d", &n);  

    // 4. Génération de l'arbre syntaxique (AST)
    Fonction ma_fonction = parse_expression(expression);

    if (ma_fonction == NULL) {
        printf("Erreur : Impossible de parser la fonction.\n");
        return 1;
    }

    // 5. Appel de la méthode de Simpson
    double resultat = simpson_calcul(ma_fonction, I, n);
    
    // 6. Affichage du résultat
    printf("\n---> RESULTAT : L'integrale de %s sur [%.2f, %.2f] est : %f\n", 
           expression, I.a, I.b, resultat);

    // 7. Libération de la mémoire
    free_tree(ma_fonction);

    return 0;
}