#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "historique.h"

/* variables globales */
EntreeHistorique historique[MAX_HISTORIQUE];
int nbEntrees = 0;

/* ajouter un calcul à l'historique */
void ajouterHistorique(char *expression, double resultat)
{
    if (nbEntrees < MAX_HISTORIQUE)
    {
        strcpy(historique[nbEntrees].expression, expression);
        historique[nbEntrees].resultat = resultat;
        nbEntrees++;
    }
}

/* afficher tous les calculs */
void afficherHistorique()
{
    if (nbEntrees == 0)
    {
        printf("Votre historique de calculs est vide !\n");
        return;
    }
    printf("\n\n\t\t\t ********************* HISTORIQUE DES CALCULS ********************* \n");
    int i;

    for (i=0; i< nbEntrees; i++)
    {
        printf("\t\t\t\t\t   %d. %s = %.4f\n", i+1, historique[i].expression, historique[i].resultat);
    }
    printf("\n\t\t\t               ****************************************\n\n");
}

/* effacer l'historique */
void effacerHistorique()
{
    nbEntrees = 0;
    printf("Historique efface avec succes !\n");
}
