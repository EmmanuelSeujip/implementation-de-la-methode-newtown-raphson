#include "trapeze.h"
#include "../../../utils/type/fonction.h"
#include "../../../utils/type/intervalle.h"
#include "../../../utils/tree/tree.h"
#include "../../../calcul/eval/evaluer.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double trapeze(Fonction f, Intervalle interval, int n){
    double a = interval.min;
    double b = interval.max;
    double h = (b - a) / n;
    double sum = (evaluer(f,a) + evaluer(f,b)) / 2.0;
    for(int i = 1; i < n; i++){
        sum += evaluer(f,a + i * h);
    }
    return h * sum;
}