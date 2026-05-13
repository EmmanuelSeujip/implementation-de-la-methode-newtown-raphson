#ifndef SIMPLE_H
#define SIMPLE_H

typedef struct {
    double r;    /* partie réelle          → f(x)   */
    double e_1;   /* coefficient de ε₁      → f'(x)  */
    double e_2;   /* coefficient de ε₂      → (Il sert juste pour les calculs afin d'arriver à la dérivé seconde) */ 
    double e_1_2;  /* coefficient de ε₁ε₂   → f''(x) */
} HyperDual;
#endif // SIMPLE_H