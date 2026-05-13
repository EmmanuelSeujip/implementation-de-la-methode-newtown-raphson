#include <math.h>
#include <stdio.h>
#include "../../utils/type/simple.h"
#include "../calcul_dual/calcul.h"

double newton(Fonction f, Intervalle I, double epsilon) {
    HyperDual p_a = calcul(f, I.a);
    HyperDual p_b = calcul(f, I.b);

    // Verification rapide des bornes : Si l'une des bornes est déjà une racine, on peut retourner immédiatement
    if (fabs(p_a.r) < epsilon) return I.a;
    if (fabs(p_b.r) < epsilon) return I.b;
    
    // 1. Vérification fondamentale (Bolzano)
    if (p_a.r * p_b.r > 0) {
        printf("Erreur : f(a) et f(b) sont de même signe. Pas de racine garantie.\n");
        return NAN; // Not a Number
    }

    // 2. Initialisation : On cherche le point qui respecte Fourier
    double x_curr;
    if (p_a.r * p_a.e_1_2 > 0) x_curr = I.a;
    else if (p_b.r * p_b.e_1_2 > 0) x_curr = I.b;
    else x_curr = (I.a + I.b) / 2.0; // Milieu par défaut

    double x_prev = x_curr + 10.0 * epsilon; 


    while (fabs(x_curr - x_prev) > epsilon) {
        x_prev = x_curr;
        HyperDual p_x = calcul(f, x_curr);

        // 3. Sécurité : Si la dérivée est trop faible (tangente horizontale)
        if (fabs(p_x.e_1) < 1e-12) {
            printf("Dérivée nulle. Basculement sur un pas de bissection.\n");
            x_curr = (I.a + I.b) / 2.0; 
        } else {
            // Newton-Raphson classique
            x_curr = x_prev - (p_x.r / p_x.e_1);
        }

        // 4. Sécurité "Out of Bounds"
        // Si Newton nous sort de l'intervalle, on recadre avec une bissection
        if (x_curr < I.a || x_curr > I.b) {
            x_curr = (I.a + I.b) / 2.0;
        }

        // Mise à jour de l'intervalle pour la bissection si nécessaire
        HyperDual p_mid = calcul(f, x_curr);
        if (p_a.r * p_mid.r < 0) {
            I.b = x_curr;
            p_b = p_mid;
        } else {
            I.a = x_curr;
            p_a = p_mid;
        }

        if (fabs(p_mid.r) < epsilon) return x_curr;
    }

    return x_curr;
}

