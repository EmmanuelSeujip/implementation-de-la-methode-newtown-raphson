#include <stdio.h>
#include <stdlib.h>
#include "../common/type.h"
#include "../common/intervalle/intervalle.h"
#include "../methods/newton.c"
Polynome creer_polynome_test() {
    // Création des monômes : -2 (exp=0), -x (exp=1), x^3 (exp=3)
    
    // Monôme : -2 (terme constant)
    Polynome mono0 = malloc(sizeof(NoedPolynome));
    mono0->coeff = -2.0;
    mono0->exp = 0.0;
    mono0->suiv = NULL;
    
    // Monôme : -x
    Polynome mono1 = malloc(sizeof(NoedPolynome));
    mono1->coeff = -1.0;
    mono1->exp = 1.0;
    mono1->suiv = mono0;  // chaînage
    
    // Monôme : x^3
    Polynome mono3 = malloc(sizeof(NoedPolynome));
    mono3->coeff = 1.0;
    mono3->exp = 3.0;
    mono3->suiv = mono1;  // tête de liste
    
    return mono3;  // x^3 - x - 2
}

int main() {
    Polynome p = creer_polynome_test();
    Intervalle I = {1.0, 2.0};
    double epsilon = 1e-5;
    
    Resultat res = newton(p, I, epsilon);
    
    if (res.error == 0) {
        printf("Racine trouvée : %.6f\n", res.val);
        // Attendu : 1.521380
    } else {
        printf("Erreur dans la recherche de racine\n");
    }
    free_polynome(p); // Libération mémoire du polynôme
    // Libération mémoire
    // (à faire selon ta fonction de libération)
    return 0;
}