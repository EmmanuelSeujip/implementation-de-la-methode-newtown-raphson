#include "fonction.h"
#include "intervalle.h"
#include "simple.h"

#ifndef RESULTAT_H
#define RESULTAT_H

typedef enum {
    TYPE_NUM,
    TYPE_INTERVALLE,
    TYPE_HYPERDUAL,
    TYPE_FONCTION
} ResultatType;

typedef struct Resultat{
    union {
        double num;
        Intervalle i;
        HyperDual hd;
        Fonction f;
    }val;
    int error;
    ResultatType type;
}Resultat;

typedef char* Erreur;
typedef Erreur ListeErreur[20];

static const ListeErreur initListeErreur={
    "Aucune erreur",
    "Erreur de syntaxe",
    "Division par zéro",
    "Domaine de définition invalide",
    "Dérivée nulle (point critique)",
    "Convergence non atteinte",
    "Intervalle non valide (a >= b)",
    "Type de résultat incompatible",
    "Mémoire insuffisante",
    "Erreur inconnue"
};


#endif
