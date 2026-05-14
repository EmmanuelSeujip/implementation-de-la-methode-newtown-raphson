#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils/type/fonction.h"
#include "utils/type/intervalle.h"
#include "utils/tree/tree.h"
#include "blackbox/methods/newton/newton.h"

int main() {
    int finished = 0;
    char input[256];
    char interval_input[256];
    double epsilon = 1e-6; // Précision par défaut
    while (!finished) {
        printf("================= Calcul de f(x)=0 par la méthode de Newton-Raphson =================\n");
        printf("Faire un choix :\n");
        printf("1. Résoudre une équation\n");
        printf("2. Aide\n");
        printf("3. Quitter\n");
        printf("\nVotre choix : ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            // Appeler la fonction pour résoudre une équation
            printf("Résolution d'une équation...\n");
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
        } else if (choice == 2) {
            // Afficher l'aide
            printf("Aide :\n");
            printf("1. Résoudre une équation : Permet de trouver les racines de f(x)=0 en utilisant la méthode de Newton-Raphson.\n");
            printf("2. Aide : Affiche ce message d'aide.\n");
            printf("3. Quitter : Termine le programme.\n");
            printf("Vous pouvez entrer une équation sous la forme f(x)=0, et le programme vous guidera à travers les étapes de la méthode de Newton-Raphson pour trouver les solutions.\n");
            printf("Les fonctions valides sont les polynomes, les fonctions cosinus et sinus, exponentielles, logarithmiques, etc. Assurez-vous d'utiliser une syntaxe correcte pour les fonctions et les opérateurs.\n");
        } else if (choice == 3) {
            finished = 1; // Terminer le programme
        } else {
            printf("Choix invalide, veuillez réessayer.\n");
        }
        printf("\n");
    }
    return 0;
}