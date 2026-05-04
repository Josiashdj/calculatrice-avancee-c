#ifndef PILES_H_INCLUDED
#define PILES_H_INCLUDED

#define CAPACITE_MAX 100
typedef struct{

    double nombres[CAPACITE_MAX];
    int indiceSommet;
}PileNombres;// on stocke les nombres au cour de l'operation

typedef struct{
    char operateurs[CAPACITE_MAX];
    int indiceSommet; // indice du dernier operateur
}PileOperateurs;// contient les operateurs arithmetique






/* prototypes PileNombres */
void   initialiserNombres(PileNombres *pile);
int    pileNombresEstVide(PileNombres *pile);
int    pileNombresEstPleine(PileNombres *pile);
void   empilerNombre(PileNombres *pile, double nombre);
double depilerNombre(PileNombres *pile);
double lireSommetNombre(PileNombres *pile);

/* prototypes PileOperateurs */
void initialiserOperateurs(PileOperateurs *pile);
int  pileOperateursEstVide(PileOperateurs *pile);
int  pileOperateursEstPleine(PileOperateurs *pile);
void empilerOperateur(PileOperateurs *pile, char operateur);
char depilerOperateur(PileOperateurs *pile);
char lireSommetOperateur(PileOperateurs *pile);
#endif // PILES_H_INCLUDED
