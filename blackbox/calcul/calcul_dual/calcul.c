#include "calcul.h"

HyperDual calcul(const Fonction F, double x0) {
    if (!F) return hd_const(0);
    switch (F->type) {
        case NODE_CONST: return hd_const(F->valeur);
        case NODE_VAR:   return hd_var(x0);
        case NODE_ADD:   return hd_add(calcul(F->gauche, x0), calcul(F->droite, x0));
        case NODE_SUB:   return hd_sub(calcul(F->gauche, x0), calcul(F->droite, x0));
        case NODE_MUL:   return hd_mul(calcul(F->gauche, x0), calcul(F->droite, x0));
        case NODE_DIV:   return hd_div(calcul(F->gauche, x0), calcul(F->droite, x0));
        case NODE_NEG:   return hd_neg(calcul(F->gauche, x0));
        case NODE_SIN:   return hd_sin(calcul(F->gauche, x0));
        case NODE_COS:   return hd_cos(calcul(F->gauche, x0));
        case NODE_EXP:   return hd_exp(calcul(F->gauche, x0));
        case NODE_LOG:   return hd_log(calcul(F->gauche, x0));
        case NODE_PUIS:  return hd_pow(calcul(F->gauche, x0), calcul(F->droite, x0).r);
        case NODE_TAN:  return hd_tan (calcul(F->gauche, x0));
        case NODE_ASIN: return hd_asin(calcul(F->gauche, x0));
        case NODE_ACOS: return hd_acos(calcul(F->gauche, x0));
        case NODE_ATAN: return hd_atan(calcul(F->gauche, x0));
        case NODE_SQRT: return hd_sqrt(calcul(F->gauche, x0));
        case NODE_ABS:  return hd_abs (calcul(F->gauche, x0));
        case NODE_SINH: return hd_sinh(calcul(F->gauche, x0));
        case NODE_COSH: return hd_cosh(calcul(F->gauche, x0));
        case NODE_TANH: return hd_tanh(calcul(F->gauche, x0));
    }
    return hd_const(0);
}