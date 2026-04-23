// Importation des fichiers d'en-tête nécessaires
#include "calcul.h"
#include "../type.h"

// Importation des bibliothèques standard
#include <math.h>
#include <stdlib.h>

//Importation des fichiers utilitaires
#include "../../utils/free_polynome.c"

Resultat p_de_x(Polynome p, float x) {
    Resultat res = {0.0, 0};
    Polynome courant = p;

    if (p == NULL) {
        res.error = 1; // Liste vide
        return res;
    }

    while (courant != NULL) {
        // Calcul : coeff * x^exp
        res.val += courant->coeff * pow(x, courant->exp);
        courant = courant->suiv;
    }

    return res;
}

Polynome derivee(Polynome p) {
    if (p == NULL) return NULL;

    Polynome res = NULL;
    Polynome dernier = NULL;
    Polynome courant = p;

    while (courant != NULL) {
        // La dérivée d'une constante (exp == 0) est 0, on l'ignore
        if (courant->exp != 0) {
            // Création du nouveau nœud
            Polynome nouveau = malloc(sizeof(NoedPolynome));
            if (nouveau == NULL) return res; // Gestion d'erreur mémoire

            nouveau->coeff = courant->coeff * courant->exp; // a * n
            nouveau->exp = courant->exp - 1;               // n - 1
            nouveau->suiv = NULL;

            // Chaînage
            if (res == NULL) {
                res = nouveau; // Premier élément de la nouvelle liste
            } else {
                dernier->suiv = nouveau;
            }
            dernier = nouveau;
        }
        courant = courant->suiv;
    }
    return res;
}

Polynome derivee_seconde(Polynome p) {
    // On calcule la première dérivée
    Polynome p_prime = derivee(p);
    
    // On calcule la dérivée de p_prime
    Polynome p_seconde = derivee(p_prime);

    // Libération de la mémoire de p_prime
    free_polynome(p_prime);
    
    return p_seconde;
}