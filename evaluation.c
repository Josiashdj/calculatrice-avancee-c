#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "evaluation.h"
#include "erreurs.h"
#include "tokenisation.h"

double evaluerExpression(Token *sortie, int nbSortie)
{

    // on prepare la pile qui va stocker le nombre temporairement les calcul intermédiaire
    PileNombres pile;
    initialiserNombres(&pile);

    int i;
    for(i=0; i< nbSortie;i++)
    {
        if(sortie[i].type == NUM)
        {
            empilerNombre(&pile, sortie[i].valeur);
        }
        else if(sortie[i].type == OP)
        {
            double b = depilerNombre(&pile);
            double a = depilerNombre(&pile);
            double resultat = 0.0;

            if (sortie[i].symbole == '+') resultat = a + b;
            else if (sortie[i].symbole == '-') resultat = a - b;
            else if (sortie[i].symbole == '*') resultat = a * b;
            else if (sortie[i].symbole == '/')
            {
                if (b == 0)
                {
                    afficherErreur(DIVISION_ZERO);
                    return 0.0;
                }
                resultat = a / b;

            }
            else if (sortie[i].symbole == '^')
            {
                resultat = pow(a, b);
            }
            else if (sortie[i].symbole == '%')
            {
                resultat = fmod(a, b);

            }


            empilerNombre(&pile, resultat);
        }
        else if (sortie[i].type == FUNC)
            {
                double a = depilerNombre(&pile);
                double resultat = 0.0;

                if (comparerSansCasse(sortie[i].nomFonction, "sqrt") == 0)
                    resultat = sqrt(a);
                else if (comparerSansCasse(sortie[i].nomFonction, "sin") == 0)
                    resultat = sin(a);
                else if (comparerSansCasse(sortie[i].nomFonction, "cos") == 0)
                    resultat = cos(a);
                else if (comparerSansCasse(sortie[i].nomFonction, "abs") == 0)
                    resultat = fabs(a);

                empilerNombre(&pile, resultat);
            }
    }
    return depilerNombre(&pile);
}
