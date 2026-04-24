#include "../common/type.h"
#include <stdlib.h>

void free_polynome(Polynome p) {
    Polynome temp;
    while (p != NULL) {
        temp = p;
        p = p->suiv;
        free(temp);
    }
}