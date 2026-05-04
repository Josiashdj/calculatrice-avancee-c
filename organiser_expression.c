#include <stdio.h>
#include <stdlib.h>
#include "organiser_expression.h"
#include "erreurs.h"

int priorite(char op)
{
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

int organiserExpression(Token *tokens, int nbTokens, Token *sortie, int *nbSortie)
{
    /* piles des diff oppérateur, on initialise et on ajoute un compteur */
    PileOperateurs pile;
    initialiserOperateurs(&pile);
    *nbSortie = 0;

    int i;
    for(i=0; i< nbTokens;i++)
    {
        // Si l'expression est un nombre
        if(tokens[i].type ==NUM)
        {
            /* On copie l'expression du calcul entrrer dans la sortie et on passe a l'expression suivante*/
            sortie[*nbSortie]= tokens[i];
            (*nbSortie)++;
        }
        // Si l'expression est un opérateur arithmétique, on applique les regle du PEMDAS
        else if(tokens[i].type == OP)
        {
            // on verifie la priorite entre les operateur
            while(!pileOperateursEstVide(&pile) && lireSommetOperateur(&pile) != '(' && priorite(lireSommetOperateur(&pile)) >= priorite(tokens[i].symbole))
            {
                sortie[*nbSortie].type = OP;
                sortie[*nbSortie].symbole = depilerOperateur(&pile);
                (*nbSortie)++;
            }
            // on empile l'operateur actuel
            empilerOperateur(&pile, tokens[i].symbole);
        }
        // Si l'expression est une parenthèse ouvrante
        else if(tokens[i].type == PAR_OUV)
        {
            empilerOperateur(&pile, '(');
        }
        // Si l'expression est une parenthèse fermante
        else if(tokens[i].type == PAR_FER)
        {
            // on depile
            while(!pileOperateursEstVide(&pile) && lireSommetOperateur(&pile) != '(' )
            {
                sortie[*nbSortie].type = OP;
                sortie[*nbSortie].symbole = depilerOperateur(&pile);
                (*nbSortie)++;
            }
            depilerOperateur(&pile);
        }
    }

    //On vide le reste de la pile dans la sortie
    while(!pileOperateursEstVide(&pile))
    {
        if (lireSommetOperateur(&pile) == '(')
        {
            afficherErreur(PARENTHESE_ERREUR);
            return 0;
        }
        sortie[*nbSortie].type = OP;
        sortie[*nbSortie].symbole = depilerOperateur(&pile);
        (*nbSortie)++;
    }

    return 1;
}
