#include <stdlib.h>
#include <stdio.h>
#include "erreurs.h"

void afficherErreur(TypeErreur erreur, char *expression, int position)
{
    printf("%s\n", expression);
    int j;
    for (j = 0; j < position; j++)
        printf(" ");
    printf("^\n");

    /* afficher le message d'erreur */
    switch (erreur)
    {
        case DIVISION_ZERO:
            printf("Erreur (position %d) : Division par zero !\n", position);
            break;
        case PARENTHESE_ERREUR:
            printf("Erreur (position %d) : Parentheses mal formees !\n", position);
            break;
        case CARACTERE_INVALIDE:
            printf("Erreur (position %d) : Caractere invalide !\n", position);
            break;
        case EXPRESSION_VIDE:
            printf("Erreur : Expression vide !\n");
            break;
        default:
            break;
    }
}
