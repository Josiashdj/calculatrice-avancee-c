#ifndef TOKENISATION_H_INCLUDED
#define TOKENISATION_H_INCLUDED

typedef enum {
    NUM,        /* un nombre : 2.0, 12.0, 4.0 */
    OP,         /* un opérateur : +, -, *, /, ^ */
    PAR_OUV,    /* parenthèse ouvrante : ( */
    PAR_FER     /* parenthèse fermante : ) */
} TypeToken;

typedef struct {
    TypeToken type;    /* le type du token */
    double    valeur;  /* utilisé si type == NUM */
    char      symbole; /* utilisé si type == OP ou PAR */
} Token;

/* prototype */
int decouperExpression(char *expression, Token *tokens, int *nbTokens);

#endif // TOKENISATION_H_INCLUDED
