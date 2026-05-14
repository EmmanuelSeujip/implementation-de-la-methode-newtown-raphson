#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Noeud* new_node(NodeType t, double v, Noeud* g, Noeud* d) {
    Noeud* n = (Noeud*)malloc(sizeof(Noeud));
    if (!n) { 
        fprintf(stderr, "Erreur : Mémoire insuffisante\n"); 
        exit(EXIT_FAILURE); 
    }
    n->type   = t;
    n->valeur = v;
    n->gauche = g;
    n->droite = d;
    return n;
}

void free_tree(Fonction a) {
    if (!a) return;
    free_tree(a->gauche); // Appels récursifs pour libérer les enfants
    free_tree(a->droite);
    free(a);              // Libération du nœud parent
}