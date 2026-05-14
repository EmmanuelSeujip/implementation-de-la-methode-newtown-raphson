#ifndef INTERVALLE_H
#define INTERVALLE_H

typedef struct Intervalle {
    double a;
    double b;
} Intervalle;

// Retourne un pointeur vers l'intervalle si valide, NULL en cas d'erreur
Intervalle* parse_interval(const char* str);

#endif