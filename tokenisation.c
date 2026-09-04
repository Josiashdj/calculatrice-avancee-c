#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    /* pour isdigit() et isspace() */
#include "tokenisation.h"
#include "erreurs.h"
#include "string.h"

int nbErreurs = 0;

/* convertit une chaîne en minuscules pour comparaison */
int comparerSansCasse(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] && s2[i])
    {
        if (tolower(s1[i]) != tolower(s2[i]))
            return 1;
        i++;
    }
    return s1[i] != s2[i];
}

int decouperExpression(char *expression, Token *tokens, int *nbTokens, double ans)
{
    int i=0;
    *nbTokens =0;
    TypeToken tokenPrecedent = OP;

    if (expression[0] == '\0')
    {
        afficherErreur(EXPRESSION_VIDE, expression, 0);

        nbErreurs++;
        i++;
    }

    while(expression[i] != '\0')  // fin de l'expression entrer par l'utilisateur
    {

            if (isspace(expression[i])) // isspace pour les espace entrer par l'utilisateur dans sont calcul
            {
                i++;
            }
            else if (expression[i] == '-' && (tokenPrecedent == OP || tokenPrecedent == PAR_OUV))
            {
                char buffer[50];
                int j = 0;
                buffer[j] = '-';
                j++;
                i++;
                while (isdigit(expression[i]) || expression[i] == '.')
                {
                    buffer[j] = expression[i];
                    j++; i++;
                }
                buffer[j] = '\0';
                tokens[*nbTokens].type   = NUM;
                tokens[*nbTokens].valeur = atof(buffer);
                (*nbTokens)++;
                tokenPrecedent = NUM;
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
                tokenPrecedent = NUM;
            }
            else if(expression[i] == '(') // parenthèse
            {
                tokens[*nbTokens].type =PAR_OUV;
                tokens[*nbTokens].symbole = '(';
                (*nbTokens)++;
                i++;
                tokenPrecedent = PAR_OUV;
            }
            else if(expression[i] == ')') // parenthèse
            {
                tokens[*nbTokens].type =PAR_FER;
                tokens[*nbTokens].symbole = ')';
                (*nbTokens)++;
                i++;
                tokenPrecedent = PAR_FER;
            }
            else if (isalpha(expression[i]))
            {
                char mot[10];
                int j = 0;

                /* lire tous les caractères du mot */
                while (isalpha(expression[i]))
                {
                    mot[j] = expression[i];
                    j++;
                    i++;
                }
                mot[j] = '\0';

                if (comparerSansCasse(mot, "pi") == 0)
                {
                    tokens[*nbTokens].type  = NUM;
                    tokens[*nbTokens].valeur = 3.14159265358979;
                    (*nbTokens)++;
                    tokenPrecedent = NUM;
                }
                else if (comparerSansCasse(mot, "e") == 0)
                {
                    tokens[*nbTokens].type  = NUM;
                    tokens[*nbTokens].valeur = 2.71828182845904;
                    (*nbTokens)++;
                    tokenPrecedent = NUM;
                }
                else if (comparerSansCasse(mot, "ans") == 0)  /* ← ajoute ici */
                {
                    tokens[*nbTokens].type   = NUM;
                    tokens[*nbTokens].valeur = ans; /* quelle valeur met-on ici ? */
                    (*nbTokens)++;
                    tokenPrecedent = NUM;
                }
                else if (comparerSansCasse(mot, "sqrt") == 0 || comparerSansCasse(mot, "sin")  == 0 || comparerSansCasse(mot, "cos")  == 0 || comparerSansCasse(mot, "abs")  == 0)
                {
                    tokens[*nbTokens].type = FUNC;
                    strcpy(tokens[*nbTokens].nomFonction, mot);
                    (*nbTokens)++;
                    tokenPrecedent = FUNC;
                }
                else
                {
                    afficherErreur(CARACTERE_INVALIDE, expression, i);
                    return 0;
                }
            }
            else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^' || expression[i] == '%')
            {
                tokens[*nbTokens].type =OP;
                tokens[*nbTokens].symbole = expression[i];
                (*nbTokens)++;
                i++;
                tokenPrecedent = OP;
            }
            else  // sinon, les opérateurs
            {
                afficherErreur(CARACTERE_INVALIDE, expression, i);

                nbErreurs++;
                i++;
                /*tokens[*nbTokens].type =OP;
                tokens[*nbTokens].symbole = expression[i];
                (*nbTokens)++;
                i++; */
            }

    }
        if (nbErreurs > 0) return 0;
        return 1;
}
