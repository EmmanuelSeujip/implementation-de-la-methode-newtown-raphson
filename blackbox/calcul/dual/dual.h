#include "../../../utils/type/simple.h"

#ifndef DUAL_H
#define DUAL_H
/* Constante pure */
HyperDual hd_const(double v);

/* Variable d'évaluation : x₀ + 1·ε₁ + 1·ε₂ + 0·ε₁ε₂ */
HyperDual hd_var(double x0);

/* ── Opérations de base ─────────────────────────────────────────────── */

HyperDual hd_add(HyperDual u, HyperDual v);
HyperDual hd_sub(HyperDual u, HyperDual v);
HyperDual hd_neg(HyperDual u);

/* (a + b·ε₁ + c·ε₂ + d·ε₁ε₂)(e + f·ε₁ + g·ε₂ + h·ε₁ε₂)
 *  = ae + (af+be)ε₁ + (ag+ce)ε₂ + (ah+de+bg+cf)ε₁ε₂     */
HyperDual hd_mul(HyperDual u, HyperDual v);

/* 1/v  via développement au premier ordre :
 *   1/(a + b·ε₁ + c·ε₂ + d·ε₁ε₂)
 *   = (1/a) - (b/a²)ε₁ - (c/a²)ε₂ + (-d/a² + 2bc/a³)ε₁ε₂  */
HyperDual hd_inv(HyperDual v);

HyperDual hd_div(HyperDual u, HyperDual v);

/* ── Fonctions élémentaires ─────────────────────────────────────────── */
/*
 * Principe : si u = a + b·ε₁ + c·ε₂ + d·ε₁ε₂
 *   g(u) = g(a) + g'(a)·(b·ε₁ + c·ε₂) + ½g''(a)·2bc·ε₁ε₂
 *         = g(a) + g'(a)·b·ε₁ + g'(a)·c·ε₂ + (g'(a)·d + g''(a)·bc)·ε₁ε₂
 */

HyperDual hd_sin(HyperDual u);
HyperDual hd_cos(HyperDual u);
HyperDual hd_exp(HyperDual u);
HyperDual hd_log(HyperDual u);
HyperDual hd_pow(HyperDual u, double n);
HyperDual hd_tan(HyperDual u);
HyperDual hd_asin(HyperDual u);
HyperDual hd_acos(HyperDual u);
HyperDual hd_atan(HyperDual u);
HyperDual hd_sqrt(HyperDual u);
HyperDual hd_abs(HyperDual u);
HyperDual hd_sinh(HyperDual u);
HyperDual hd_cosh(HyperDual u);
HyperDual hd_tanh(HyperDual u);

#endif // DUAL_H