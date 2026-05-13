#include "../../utils/type/simple.h"

#ifndef DUAL_H
#define DUAL_H
/* Constante pure */
static HyperDual hd_const(double v);

/* Variable d'évaluation : x₀ + 1·ε₁ + 1·ε₂ + 0·ε₁ε₂ */
static HyperDual hd_var(double x0);

/* ── Opérations de base ─────────────────────────────────────────────── */

static HyperDual hd_add(HyperDual u, HyperDual v);
static HyperDual hd_sub(HyperDual u, HyperDual v);
static HyperDual hd_neg(HyperDual u);

/* (a + b·ε₁ + c·ε₂ + d·ε₁ε₂)(e + f·ε₁ + g·ε₂ + h·ε₁ε₂)
 *  = ae + (af+be)ε₁ + (ag+ce)ε₂ + (ah+de+bg+cf)ε₁ε₂     */
static HyperDual hd_mul(HyperDual u, HyperDual v);

/* 1/v  via développement au premier ordre :
 *   1/(a + b·ε₁ + c·ε₂ + d·ε₁ε₂)
 *   = (1/a) - (b/a²)ε₁ - (c/a²)ε₂ + (-d/a² + 2bc/a³)ε₁ε₂  */
static HyperDual hd_inv(HyperDual v);

static HyperDual hd_div(HyperDual u, HyperDual v);

/* ── Fonctions élémentaires ─────────────────────────────────────────── */
/*
 * Principe : si u = a + b·ε₁ + c·ε₂ + d·ε₁ε₂
 *   g(u) = g(a) + g'(a)·(b·ε₁ + c·ε₂) + ½g''(a)·2bc·ε₁ε₂
 *         = g(a) + g'(a)·b·ε₁ + g'(a)·c·ε₂ + (g'(a)·d + g''(a)·bc)·ε₁ε₂
 */

static HyperDual hd_sin(HyperDual u);
static HyperDual hd_cos(HyperDual u);
static HyperDual hd_exp(HyperDual u);
static HyperDual hd_log(HyperDual u);
static HyperDual hd_pow(HyperDual u, double n);
static HyperDual hd_tan(HyperDual u);
static HyperDual hd_asin(HyperDual u);
static HyperDual hd_acos(HyperDual u);
static HyperDual hd_atan(HyperDual u);
static HyperDual hd_sqrt(HyperDual u);
static HyperDual hd_abs(HyperDual u);
static HyperDual hd_sinh(HyperDual u);
static HyperDual hd_cosh(HyperDual u);
static HyperDual hd_tanh(HyperDual u);

#endif // DUAL_H