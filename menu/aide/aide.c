#include "aide.h"
#include <stdio.h>
void menu_aide() {
    printf("Aide:\n");
    printf("1. Résoudre une équation : Permet de trouver les racines de f(x)=0 en utilisant la méthode de Newton-Raphson.\n");
    printf("2. Déterminer l'intégrale d'une fonction de la forme f(x) : Permet de trouver l'intégrale d'une fonction de la forme f(x) en utilisant la méthode de Simpson.\n");
    printf("3. Aide : Affiche ce message d'aide.\n");
    printf("4. Quitter : Termine le programme.\n");
    printf("Vous pouvez entrer une équation sous la forme f(x)=0, et le programme vous guidera à travers les étapes de la méthode de Newton-Raphson pour trouver les solutions.\n");
    printf("Les fonctions valides sont les polynomes, les fonctions cosinus et sinus, exponentielles, logarithmiques, etc. Assurez-vous d'utiliser une syntaxe correcte pour les fonctions et les opérateurs.\n");
}
