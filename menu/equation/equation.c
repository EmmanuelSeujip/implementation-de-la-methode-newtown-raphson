#include "equation.h"

void equation() {
    printf("Résolution de l'équation f(x)=0...\n");
    printf("Entrez une fonction f(x) (ex: sin(x) + 2*x^2 - 5) : ");
    scanf(" %[^\n]", input); // Lire une ligne complète
    Fonction f = parse_expression(input);
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
