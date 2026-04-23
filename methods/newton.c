// Importation des fichiers d'en-tête nécessaires
#include "newton.h"

// Importation des bibliothèques standard
#include <math.h>

//Importation des fichiers commun
#include "../common/calcul/calcul.c"

// Nous allons faire la méthode de Newton en supposant que l'intervalle I contient une unique racine
Resultat newton(Polynome p, Intervalle I, double epsilon){
    Resultat res={.val=0, .error=0};
    float x_i, x_i_1;
    x_i=x_i_1=0;
    if (p_de_x(p, I.a).val * p_de_x(derivee_seconde(p), I.a).val > 0) {
        x_i_1 = I.a;
    }
    else if (p_de_x(p, I.b).val * p_de_x(derivee_seconde(p), I.b).val > 0){
        x_i_1 = I.b;
    }
    else{
        printf("L'intervalle ne contient pas de racine ou en contient plusieurs.\n");
        res.error=1; // L'intervalle ne contient pas de racine ou en contient plusieurs
        return res;
    }
    while (fabs(x_i_1-x_i)>epsilon && p_de_x(p, x_i_1).val != 0){
        x_i = x_i_1;
        x_i_1 = x_i - (p_de_x(p, x_i).val / p_de_x(derivee(p), x_i).val);
    }
    res.val=x_i_1;
    return res;

}