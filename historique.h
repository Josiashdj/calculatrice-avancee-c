#ifndef HISTORIQUE_H_INCLUDED
#define HISTORIQUE_H_INCLUDED


#define MAX_HISTORIQUE 50

typedef struct{
    char expression[100];
    double resultat;
    char date[30];

}EntreeHistorique;

void ajouterHistorique(char *expression, double resultat);
void afficherHistorique();
void effacerHistorique();
void sauvegarderHistorique();
void chargerHistorique();


#endif // HISTORIQUE_H_INCLUDED
