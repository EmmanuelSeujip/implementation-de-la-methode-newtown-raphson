#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils/type/fonction.h"
#include "utils/type/intervalle.h"
#include "utils/tree/tree.h"
#include "blackbox/methods/newton/newton.h"
#include "menu/equation/equation.h"
int main() {
    int finished = 0;
    char input[256];
    char interval_input[256];
    double epsilon = 1e-6; // Précision par défaut
    while (!finished) {
        printf("================= Calcul de f(x)=0 par la méthode de Newton-Raphson =================\n");
        printf("Faire un choix :\n");
        printf("1. Résolution des équations de la forme f(x)=0\n");
        printf("2. Déterminer l'intégrale d'une fonction de la forme f(x)\n");
        printf("3. Aide\n");
        printf("4. Quitter\n");
        printf("\nVotre choix : ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            // Appeler la fonction pour résoudre une équation
            equation();
        } else if (choice == 2) {
            // Afficher l'aide
            printf("Aide :\n");
            printf("1. Résoudre une équation : Permet de trouver les racines de f(x)=0 en utilisant la méthode de Newton-Raphson.\n");
            printf("2. Déterminer l'intégrale d'une fonction de la forme f(x) : Permet de trouver l'intégrale d'une fonction de la forme f(x) en utilisant la méthode de Simpson.\n");
            printf("3. Aide : Affiche ce message d'aide.\n");
            printf("4. Quitter : Termine le programme.\n");
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