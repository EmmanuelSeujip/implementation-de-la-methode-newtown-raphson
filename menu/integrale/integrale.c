#include "integrale.h"
#include "../../../utils/type/fonction.h"
#include "../../../utils/type/intervalle.h"
#include "../../../utils/tree/tree.h"
#include "../../../calcul/eval/evaluer.h"
#include "../../../calcul/Parser/parser.h"
#include <string.h>

void menu_integrale(){
    Fonction f;
    Intervalle* interval;
    char input[256];
    char interval_input[256];
    double epsilon = 1e-6; // Précision par défaut
    int n;
    double result;
    int choice;
    do{
        printf("1. Simpson\n");
        printf("2. Trapeze\n");
        printf("3. Quitter\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Entrez la fonction\n");
                scanf("%s", input);
                f = parse_expression(input);
                if (f == NULL) {
                    printf("Erreur : expression invalide\n");
                    break;
                }
                printf("Entrez l'intervalle\n");
                interval = parse_interval(interval_input)
                printf("Entrez le nombre de subdivisions\n");
                scanf("%d", &n);
                result = simpson(f, interval, n);
                printf("Le resultat est : %lf\n", result);
                break;
            case 2:
                printf("Entrez la fonction\n");
                scanf("%s", input);
                f = parse_expression(input);
                if (f == NULL) {
                    printf("Erreur : expression invalide\n");
                    break;
                }
                printf("Entrez l'intervalle\n");
                interval = parse_interval(interval_input)
                printf("Entrez le nombre de subdivisions\n");
                scanf("%d", &n);
                result = trapeze(f, interval, n);
                printf("Le resultat est : %lf\n", result);
                break;
            case 3:
                break;
            default:
                printf("Choix invalide\n");
                break;
        }
    }while(choice != 3);
}
