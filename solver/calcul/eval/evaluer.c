#include "evaluer.h"
#include <math.h>

double evaluer(const Fonction a, double x) {
    if (!a) return 0.0; 
    
    switch (a->type) {
        case NODE_CONST: return a->valeur;
        case NODE_VAR:   return x;
        case NODE_ADD:   return evaluer(a->gauche, x) + evaluer(a->droite, x);
        case NODE_SUB:   return evaluer(a->gauche, x) - evaluer(a->droite, x);
        case NODE_MUL:   return evaluer(a->gauche, x) * evaluer(a->droite, x);
        case NODE_DIV:   return evaluer(a->gauche, x) / evaluer(a->droite, x);
        case NODE_NEG:   return -evaluer(a->gauche, x);
        case NODE_SIN:   return sin(evaluer(a->gauche, x));
        case NODE_COS:   return cos(evaluer(a->gauche, x));
        case NODE_EXP:   return exp(evaluer(a->gauche, x));
        case NODE_LOG:   return log(evaluer(a->gauche, x));
        case NODE_PUIS:  return pow(evaluer(a->gauche, x), evaluer(a->droite, x));
        case NODE_TAN:  return tan(evaluer(a->gauche, x));
        case NODE_ASIN: return asin(evaluer(a->gauche, x));
        case NODE_ACOS: return acos(evaluer(a->gauche, x));
        case NODE_ATAN: return atan(evaluer(a->gauche, x));
        case NODE_SQRT: return sqrt(evaluer(a->gauche, x));
        case NODE_ABS:  return fabs(evaluer(a->gauche, x));
        case NODE_SINH: return sinh(evaluer(a->gauche, x));
        case NODE_COSH: return cosh(evaluer(a->gauche, x));
        case NODE_TANH: return tanh(evaluer(a->gauche, x));
        default: return 0.0;

    }
}