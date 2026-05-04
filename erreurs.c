#include <stdlib.h>
#include <stdio.h>
#include "erreurs.h"

void afficherErreur(TypeErreur erreur)
{
    switch(erreur)
    {
        case DIVISION_ZERO:
           printf("\nErreur: Vous venez d'effectuer une division par 0! \n") ;
           break;

        case PARENTHESE_ERREUR:
            printf("\nErreur: Il semble avoir une erreur de parentheses\n");
            break;

        case CARACTERE_INVALIDE:
            printf("\nErreur: Vous avez entrer un caractere invalide\n");
            break;

        case EXPRESSION_VIDE:
            printf("\nErreur: veuiller entrer des chiffres pour effectuer un calcul !\n");
            break;

        default:
            break;
    }
}
