#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    /* pour isdigit() et isspace() */
#include "tokenisation.h"
#include "erreurs.h"


int decouperExpression(char *expression, Token *tokens, int *nbTokens)
{
    int i=0;
    *nbTokens =0;

    if (expression[0] == '\0')
    {
        afficherErreur(EXPRESSION_VIDE);
        return 0;
    }

    while(expression[i] != '\0')  // fin de l'expression entrer par l'utilisateur
    {

            if (isspace(expression[i])) // isspace pour les espace entrer par l'utilisateur dans sont calcul
            {
                i++;
            }
            else if(isdigit(expression[i])) //isdigit pour les chiffres
            {
                char buffer[50]; // stocke temporairement les chiffre
                int j=0;

                while (isdigit(expression[i]) || expression[i] == '.')
                {
                    buffer[j] = expression[i]; // on copie chaque chiffre
                    j++;
                    i++;
                }
                buffer[j]= '\0'; // on termine la chaine
                /*On convertit et on stocke l'expression découpé*/
                tokens[*nbTokens].type = NUM;
                tokens[*nbTokens].valeur = atof(buffer); // atof est une fonction de bibliothèque
                (*nbTokens)++;
            }
            else if(expression[i] == '(') // parenthèse
            {
                tokens[*nbTokens].type =PAR_OUV;
                tokens[*nbTokens].symbole = '(';
                (*nbTokens)++;
                i++;
            }
            else if(expression[i] == ')') // parenthèse
            {
                tokens[*nbTokens].type =PAR_FER;
                tokens[*nbTokens].symbole = ')';
                (*nbTokens)++;
                i++;
            }
            else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^')
            {
                tokens[*nbTokens].type =OP;
                tokens[*nbTokens].symbole = expression[i];
                (*nbTokens)++;
                i++;
            }
            else  // sinon, les opérateurs
            {
                afficherErreur(CARACTERE_INVALIDE);
                return 0;
                /*tokens[*nbTokens].type =OP;
                tokens[*nbTokens].symbole = expression[i];
                (*nbTokens)++;
                i++; */
            }

    }
        return 1;
}
