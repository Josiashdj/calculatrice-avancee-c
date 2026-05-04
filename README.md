# Calculatrice Avancée en C

Calculatrice en ligne de commande évaluant des expressions 
arithmétiques complexes avec gestion des priorités (PEMDAS).

## Fonctionnalités
- Évaluation d'expressions complexes : `2*(12*4)+4/3`
- Respect des priorités (PEMDAS)
- Gestion des parenthèses
- Historique des calculs
- Gestion des erreurs

## Compilation
```bash
gcc -o calculatrice main.c piles.c tokenisation.c organiser_expression.c evaluation.c erreurs.c historique.c
```

## Auteur
HOUENAGNON Josias Djossou