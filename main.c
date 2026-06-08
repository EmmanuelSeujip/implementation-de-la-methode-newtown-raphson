#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils/type/fonction.h"
#include "utils/type/intervalle.h"
#include "utils/tree/tree.h"
#include "blackbox/methods/newton/newton.h"
#include "menu/equation/equation.h"
#include "menu/aide/aide.h"
#include "menu/integrale/integrale.h"
int main() {
    int finished = 0;
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
            menu_equation();
        } else if (choice == 2) {
            // Afficher l'aide
            menu_integrale();
        } else if (choice == 3) {
            menu_aide();
        } else if (choice == 4) {
            finished = 1; // Terminer le programme
        } else {
            printf("Choix invalide, veuillez réessayer.\n");
        }
        printf("\n");
    }
    return 0;
}