#include <stdio.h>
#include <stdlib.h>
#include "pointeurs.h"

/// @brief démontration de l'utilisation du pointeur générique void * qui peut ensuite être casté en un pointeur typé
/// @param ptr : pointeur générique
/// @param type : type intrinsèque du pointeur
void afficher_valeur(void *ptr, char type) {
    if (ptr==NULL) {
        printf("pointeur vide\n"); 
        return;
    }
  switch (type) {
  case 'i':
    printf("Valeur : %d\n", *(int *)ptr);
    break;
  case 'f':
    printf("Valeur : %.2f\n", *(float *)ptr);
    break;
  }
}

void pointeur2() {
  printf("*** pointeurs2 ***\n");
  int a = 10;
  float b = 3.14;
  int *c=NULL;
  afficher_valeur(c, 'i');
  int *d=calloc(1,sizeof(int));
  *d=47;
  afficher_valeur(d, 'i');
  afficher_valeur(&a, 'i');
  afficher_valeur(&b, 'f');
}