// Importations nécessaires
#include "../dual/dual.h"
#include "../../../utils/type/simple.h"
#include "../../../utils/type/fonction.h"

#ifndef CALCUL_H
#define CALCUL_H
/**
 * Calcule la valeur d'une fonction , sa dérivée et sa dérivée seconde en un point donné.
 * @param F La fonction à évaluer.
 * @param x0 Le point d'évaluation.
 * @return La valeur de la fonction en x0.
 */
HyperDual calcul(const Fonction F, double x0) ;
#endif // CALCUL_H