#ifndef TRAPEZE_H
#define TRAPEZE_H

#include "../../../utils/type/fonction.h"
#include "../../../utils/type/intervalle.h"
#include "../../../utils/tree/tree.h"
#include "../../../calcul/eval/evaluer.h"

double trapeze(Fonction f, Intervalle interval, int n);

#endif