#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piles.h"
#include "tokenisation.h"
#include "organiser_expression.h"
#include "erreurs.h"
#include "evaluation.h"
#include "historique.h"



int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        char expression[100];
        Token tokens[50];
        int nbTokens = 0;
        Token sortie[50];
        int nbSortie = 0;
        double resultat;

        strcpy(expression, argv[1]);

        if (decouperExpression(expression, tokens, &nbTokens))
        {
            if (organiserExpression(tokens, nbTokens, sortie, &nbSortie))
            {
                resultat = evaluerExpression(sortie, nbSortie);
                printf("\n\tResultat : %.4f\n\n", resultat);
            }
        }
        return 0;
    }
    else
    {
        /* tout ton do while ici */
        printf("\t==========================================================================================================\n\t||\t\t\t\t\t\t\t\t\t\t\t\t\t||");
        printf("\n\t|| \t\t\t  ********* Bienvenue sur notre CALCULATRICE***********\t\t\t\t|| \n\t||\t\t\t\t\t\t\t\t\t\t\t\t\t||\n \t||\t\t *********Veuillez choisir le type d'opperation que vous voulez !*********\t\t||\n\t||\t\t\t\t\t\t\t\t\t\t\t\t\t||\n\t========================================================================================================== \n\n");
        int choix = 0;
        do
        {
            /* menu... */
            printf("\n\t \t \t 1- Effectuer un calcul \t \t  2- Voir l'historique \n\n \t \t \t 3- Effacer l'historique \t \t  4- Mode d'utilisation \n\n \t \t \t 5- A propos \t \t \t\t  6-Quitter \n   \n\n");
            printf("\n \t\tVeuillez entrer votre choix !\t");

            if (scanf("%d", &choix) !=1)
            {
                printf("\nERREUR : veuillez entrer un chiffre entre 1 et 6 !\n");
                while(getchar() != '\n');
                choix = 0;
            }
            else
            {
                while(getchar() != '\n');
            }

            switch (choix)
            {
                case 1:
                    {

                        char expression[100];
                        Token tokens[50];
                        int nbTokens = 0;
                        Token sortie[50];
                        int nbSortie = 0;
                        double  resultat;

                        printf("\nVeuillez entrer votre calcul:\t");
                        //scanf(" %[^\n]", expression);
                        fgets(expression, 100, stdin);
                        expression[strcspn(expression, "\n")] = '\0';
                        if (expression[0] == '\0')                            /* ← expression vide */
                        {
                            afficherErreur(EXPRESSION_VIDE);
                            break;
                        }

                        if (decouperExpression(expression, tokens, &nbTokens))
                        {
                            if (organiserExpression(tokens, nbTokens, sortie, &nbSortie))
                            {
                                resultat= evaluerExpression(sortie, nbSortie);
                                printf("\n \tResultat : %.4f\n\n", resultat);
                                ajouterHistorique(expression, resultat);

                            }
                            //organiserExpression(tokens, nbTokens, sortie, &nbSortie);
                        }
                        break;
                    }

                case 2:
                    afficherHistorique();
                    break;

                case 3:
                    effacerHistorique();
                    break;

                case 4:
                    {
                        printf("\n\t==========================================\n");
                        printf("\t||         MODE D'UTILISATION           ||\n");
                        printf("\t==========================================\n");
                        printf("\t|| Operateurs supportes :               ||\n");
                        printf("\t||   (+)   Addition                     ||\n");
                        printf("\t||   (-)   Soustraction                 ||\n");
                        printf("\t||   (*)   Multiplication               ||\n");
                        printf("\t||   (/)   Division                     ||\n");
                        printf("\t||   (^)   Puissance                    ||\n");
                        printf("\t||                                      ||\n");
                        printf("\t|| Exemples :                           ||\n");
                        printf("\t||   2 * (12 * 4) + 4 / 3               ||\n");
                        printf("\t||   (10 + 5) * 2 - 8 / 4               ||\n");
                        printf("\t||   2 ^ 10                             ||\n");
                        printf("\t==========================================\n\n");
                        break;
                    }

                case 5:
                    {
                        printf("\n\t==========================================\n");
                        printf("\t||              A PROPOS                ||\n");
                        printf("\t==========================================\n");
                        printf("\t|| Nom    : HOUENAGNON Josias Djossou   ||\n");
                        printf("\t|| Statut : Etudiant L1 IRT             ||\n");
                        printf("\t|| Mail   : houenagnondjossoujosias     ||\n");
                        printf("\t||          @gmail.com                  ||\n");
                        printf("\t|| GitHub : houenagnondjossou           ||\n");
                        printf("\t||          josias-a11y                 ||\n");
                        printf("\t||                                      ||\n");
                        printf("\t|| Description :                        ||\n");
                        printf("\t|| Calculatrice evaluant des            ||\n");
                        printf("\t|| expressions complexes avec           ||\n");
                        printf("\t|| gestion des priorites (PEMDAS)       ||\n");
                        printf("\t==========================================\n\n");
                        break;
                    }

                case 6:
                    printf("MERCI D'AVOIR TESTER NOTRE PROGRAMME ! ");
                    break;

                default: printf("Choix invalide !\n");
            }
        } while (choix != 6);
    }

    return 0;
}



    /*Token tokens[50];
    int nbTokens = 0;
    char expression[] = "2*(12*4)+4/3";
    decouperExpression(expression, tokens, &nbTokens);
    / après decouperExpression() /
    Token sortie[50];
    int nbSortie = 0;

    organiserExpression(tokens, nbTokens, sortie, &nbSortie);
    double resultat = evaluerExpression(sortie, nbSortie);
    printf("Resultat : %.4f\n", resultat); */

