#ifndef HISTORIQUE_H_INCLUDED
#define HISTORIQUE_H_INCLUDED


#define MAX_HISTORIQUE 50

typedef struct{
    char expression[100];
    double resultat;

}EntreeHistorique;

void ajouterHistorique(char *expression, double resultat);
void afficherHistorique();
void effacerHistorique();


#endif // HISTORIQUE_H_INCLUDED
