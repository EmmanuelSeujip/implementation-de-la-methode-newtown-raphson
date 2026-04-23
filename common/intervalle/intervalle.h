#ifndef INTERVALLE_H
#define INTERVALLE_H

typedef struct Intervalle{
    double a;
    double b;
}Intervalle;

typedef struct NoedIntervalle{
    Intervalle intervalle;
    struct NoedIntervalle* suiv;
}NoedIntervalle, *ListeIntervalle;

#endif // INTERVALLE_H