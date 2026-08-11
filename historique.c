#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
        time_t maintenant = time(NULL);
        struct tm *t = localtime(&maintenant);
        strftime(historique[nbEntrees].date, 30, "%d/%m/%Y %H:%M:%S", t);
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
        printf("\t\t\t\t\t   %d:  [%s] :   %s = %.4f\n", i+1,historique[i].date, historique[i].expression, historique[i].resultat);
    }
    printf("\n\t\t\t               ****************************************\n\n");
}

void sauvegarderHistorique()
{
    FILE *fichier = fopen("Historique_de_calculs.txt", "a");
    if (fichier == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier !\n");
        return;
    }
    fprintf(fichier, "[%s] %s = %.4f\n",
            historique[nbEntrees-1].date,
            historique[nbEntrees-1].expression,
            historique[nbEntrees-1].resultat);
    fclose(fichier);
}


void chargerHistorique()
{
    FILE *fichier = fopen("Historique_de_calculs.txt", "r");
    if (fichier == NULL)
    {
        return; /* pas de fichier → historique vide */
    }
    while (nbEntrees < MAX_HISTORIQUE)
    {
        int lu = fscanf(fichier, "[%29[^]]] %99[^=]= %lf\n",historique[nbEntrees].date, historique[nbEntrees].expression, &historique[nbEntrees].resultat);
        if (lu != 3) break;
        nbEntrees++;
    }
    fclose(fichier);
}



void effacerHistorique()
{
    nbEntrees = 0;
    printf("Historique efface avec succes !\n");
}
