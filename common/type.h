#ifndef TYPE_H
#define TYPE_H

typedef struct Resultat{
    double val;
    int error;
}Resultat;

typedef struct NoedPolynome{
    float coeff;
    float exp;
    struct NoedPolynome* suiv;
}NoedPolynome, *Polynome;


#endif // TYPE_H