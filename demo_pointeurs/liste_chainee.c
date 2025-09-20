#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"


liste insere_entete(int element, liste Q)
{
    liste L;
    L = (liste)malloc(sizeof(struct cellule));
    L->valeur = element;
    L->suivant = Q;
    return(L);
}