#include <stdio.h>
#include <stdlib.h>
#include "piles.h"
// On initialise la pile de nombres  avant le debut du calcul
void initialiserNombres(PileNombres *pile)
{
    pile->indiceSommet = -1;
}
// On initialise la pile d'operateurs avant le debut du calcul
void initialiserOperateurs(PileOperateurs *pile)
{
    pile->indiceSommet = -1;
}

//Vérifie si la pile de nombres est vide Retourne 1 si vide, 0 sinon
int pileNombresEstVide(PileNombres *pile)
{
   return pile->indiceSommet == -1;
}
int pileNombresEstPleine(PileNombres *pile)
{
   return pile->indiceSommet == CAPACITE_MAX - 1;
}

//Vérifie si la pile d'opérateurs est vide Retourne 1 si vide, 0 sinon
int pileOperateursEstVide(PileOperateurs *pile)
{
    return pile->indiceSommet == -1;
}
int pileOperateursEstPleine(PileOperateurs *pile)
{
    return pile->indiceSommet == CAPACITE_MAX - 1;
}




void empilerNombre(PileNombres *pile, double nombre)
{
   if (!pileNombresEstPleine(pile))
   {
        /* Incrémenter et stocker en même temps */
        pile->nombres[++pile->indiceSommet] = nombre;
        /* ++pile->indiceSommet signifie : incrémente D'ABORD, puis utilise */
   }
}
void empilerOperateur(PileOperateurs *pile, char operateur)
{
    if (!pileOperateursEstPleine(pile))
    {
        pile->operateurs[++pile->indiceSommet] = operateur;
    }
}


double depilerNombre(PileNombres *pile)
{
    if(!pileNombresEstVide(pile))
    {
        return pile->nombres[pile->indiceSommet--];    /*  retourne PUIS décrémente */
    }
    return 0.0;
}
char depilerOperateur(PileOperateurs *pile)
{
    if(!pileOperateursEstVide(pile))
    {
        return pile->operateurs[pile->indiceSommet--];
    }
    return '\0';
}

double lireSommetNombre(PileNombres *pile)
{
    return pile->nombres[pile->indiceSommet];
}
char lireSommetOperateur(PileOperateurs *pile)
{
    return pile->operateurs[pile->indiceSommet];
}
