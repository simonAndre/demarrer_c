#include <stdio.h>
#include <stdlib.h>
#include "pointeurs.h"

/// @brief affiche le contenu d'un tableau
/// @param tab pointeur vers le tableau (type non précisé)
/// @param taille taille du tableau
void affiche_tableau(void *tab,int taille){
    printf("\n| l.  |     v.     |\n");
    printf("|-----|------------|\n");
    int *t=(int *)tab;
    char s_valeur[10];
    for (int i=0;i<taille;i++){
        // on converti en chaine la valeur de la case i du tableau 
        sprintf(s_valeur,"%d",*(int *)(t+i));
        // on affiche une nouvelle ligne avec cette valeur 
        printf("| %3d | %10s |\n",i,s_valeur);
    }
    printf("|-----|------------|\n");
}

/// @brief création d'un tableau par allocation dynamique
/// @param taille : taille du tableau à construire
/// @param out_tab : tableau à remplir
void remplit_tab(int taille,int *out_tab){
    for (int i=0;i<taille;i++){
        *(out_tab+i)=i+11;
    }
}

/// @brief construit un talbeau d'entiers
/// @param taille taille du tableau
/// @return 
void* construit_tab(int taille){
    int *out_tab=(int *)calloc(taille,sizeof(int));
    for (int i=0;i<taille;i++){
        *(out_tab+i)=i+3256;
    }
    return out_tab;
}


void pointeurs3_main(){
    printf("\n---- fonction pointeurs3_main ----\n");
    
    int taille=7;
    int *t1=calloc(taille,sizeof(int));
    remplit_tab(taille,t1);
    affiche_tableau(t1,taille);
    
    int *t2=construit_tab(5);
    affiche_tableau(t2,5);

}