#include "simpson.h"

double simpson_calcul(Fonction f, Intervalle I, int n) {
    
    double a = I.a;
    double b = I.b;

    // La méthode de Simpson exige un nombre pair de sous-intervalles (n = 2p)
    if (n % 2 != 0) {
        n++; 
    }

    // Calcul du pas (h)
    double h = (b - a) / n;
    
    // Évaluation des extrémités de l'intervalle
    double somme_bords = evaluer(f, a) + evaluer(f, b);
    double somme_impairs = 0.0;
    double somme_pairs = 0.0;

    // Boucle de calcul des sommes internes
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            somme_pairs += evaluer(f, x);
        } else {
            somme_impairs += evaluer(f, x);
        }
    }

    // Application de la formule finale de Simpson
    return (h / 3.0) * (somme_bords + 4.0 * somme_impairs + 2.0 * somme_pairs);
}