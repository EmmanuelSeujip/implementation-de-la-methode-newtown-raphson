#ifndef TYPE_H
#define TYPE_H

typedef struct Resultat{
    double val;
    int error;
}Resultat;

typedef struct NoedPolynome{
    float coeff;
    int exp;
    struct NoedPolynome* suiv;
}NoedPolynome, *Polynome;

typedef struct Intervalle{
    double a;
    double b;
}Intervalle;

#endif // TYPE_H