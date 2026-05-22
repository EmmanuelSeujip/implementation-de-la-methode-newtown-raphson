#include "equation.h"
#include "../../utils/tree/tree.h"
#include "../../utils/type/fonction.h"
#include "../../utils/type/intervalle.h"
#include "../../blackbox/methods/newton/newton.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void menu_equation() {
    printf("Résolution de l'équation f(x)=0...\n");
    printf("Entrez une fonction f(x) (ex: sin(x) + 2*x^2 - 5) : ");
    char input[256];
    scanf(" %[^\n]", input); // Lire une ligne complète
    Fonction f = parse_expression(input); 
    char interval_input[256];
    double epsilon = 1e-6; // Précision par défaut
    if (f) {                         
        printf("Entrez un intervalle pour la recherche de racines (ex: [0, 10]) : ");
        scanf(" %[^\n]", interval_input); // Lire une ligne complète pour l'intervalle
        Intervalle* interval = parse_interval(interval_input);
        if (interval) {
            printf("Entrez la précision souhaitée (ex: 1e-6 ou juste en décimal) : ");
            scanf("%lf", &epsilon);
            double root = newton(f, *interval, epsilon);
            if (root!=NAN){
                printf("La racine trouvée est : %lf\n", root);
            }
            free(interval); // N'oubliez pas de libérer la mémoire allouée pour l'intervalle
        } else {
            printf("Erreur : Intervalle invalide. Veuillez réessayer.\n");
        }
        free_tree(f); // N'oubliez pas de libérer la mémoire allouée pour l'AST
    } else {
        printf("Erreur : Fonction invalide. Veuillez réessayer.\n");
    }   
}
