#ifndef ERREURS_H_INCLUDED
#define ERREURS_H_INCLUDED

typedef enum {
    PAS_ERREUR,        /* tout va bien */
    DIVISION_ZERO,     /* division par zéro */
    PARENTHESE_ERREUR, /* parenthèses mal formées */
    CARACTERE_INVALIDE,/* caractère inconnu */
    EXPRESSION_VIDE    /* expression vide */
} TypeErreur;

void afficherErreur(TypeErreur erreur, char *expression, int position);

#endif // ERREURS_H_INCLUDED
