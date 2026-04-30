#ifndef FONCTION_H
#define FONCTION_H
typedef enum {
    NODE_CONST,
    NODE_VAR,
    NODE_ADD,
    NODE_SUB,
    NODE_MUL,
    NODE_DIV,
    NODE_NEG,
    NODE_SIN,
    NODE_COS,
    NODE_EXP,
    NODE_LOG,
    NODE_PUIS,
    NODE_TAN,
    NODE_ASIN,
    NODE_ACOS,
    NODE_ATAN,
    NODE_SQRT,
    NODE_ABS,
    NODE_SINH,
    NODE_COSH,
    NODE_TANH,
} NodeType;

typedef struct Noeud {
    NodeType      type;
    double        valeur;       /* Utilisé si type == NODE_CONST       */
    struct Noeud *gauche;       /* Opérande gauche (ou argument unique) */
    struct Noeud *droite;       /* Opérande droite (NULL pour fonctions)*/
} Noeud, *Fonction;

// Fonctions à implémenter dans votre code mère (ou un ast.c)
Noeud* new_node(NodeType t, double v, Noeud* g, Noeud* d);
double evaluer(const Fonction a, double x);
void free_tree(Fonction a);

// La fonction clé que Bison va exposer à votre code mère
Fonction parse_expression(const char* expr_str);
#endif 