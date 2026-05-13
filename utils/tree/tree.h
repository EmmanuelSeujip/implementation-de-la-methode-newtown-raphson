#ifndef TREE_H
#define TREE_H

#include "../type/fonction.h"

/* --- Constructeur générique --- */
Noeud* new_node(NodeType t, double v, Noeud* g, Noeud* d);

/* --- Libération mémoire --- */
void free_tree(Fonction a);

#endif // TREE_H
