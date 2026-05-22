#include "simpson.h"
#include "../../../utils/type/fonction.h"
#include "../../../utils/type/intervalle.h"
#include "../../../utils/tree/tree.h"
#include "../../calcul/eval/evaluer.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simpson(Fonction f, Intervalle interval, int n) {
    if (n % 2 != 0) {
        printf("Error: n must be even for Simpson's rule\n");
        return NAN;
    }
    double a = interval.a;
    double b = interval.b;
    double h = (b - a) / n;
    double sum = evaluer(f,a) + evaluer(f,b);
    for (int i = 1; i < n; i += 2) {
        sum += 4 * evaluer(f,a + i * h);
    }
    for (int i = 2; i < n - 1; i += 2) {
        sum += 2 * evaluer(f,a + i * h);
    }

    return (h / 3) * sum;
}