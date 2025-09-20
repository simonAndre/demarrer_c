#include "pointeurs_struct.h"
#include <stdio.h>

struct eleve
{
    char nom[20];
    int annee;
};
typedef struct eleve *classe;

void affiche_classe(classe une_classe,int nb_eleves){
    printf("# : nom elève : annee naissance\n");
    for(int i=0;i<nb_eleves;i++){
        printf("%i : %s : %d\n",i,(une_classe+i)->nom,(une_classe+i)->annee);
        // équivalent à:
        // printf("%i : %s : %d\n",i,une_classe[i].nom,une_classe[i].annee);
    }
    printf("-------------");
}

void pointeur_struct1_main(){
    printf("\n---- fonction pointeur_struct1_main ----\n");

    int nb_eleves=3;
    classe ma_classe;
    ma_classe = (classe)malloc(nb_eleves * sizeof(struct eleve));
    printf("Saisie des %d élèves de la classe\n",nb_eleves);
    for(int i=0;i<nb_eleves;i++){
        printf("nom élève %d:",i);
        scanf("%s",&ma_classe[i].nom);
        printf("année élève %d:",i);
        scanf("%d",&ma_classe[i].annee);
    }
    affiche_classe(ma_classe,nb_eleves);
}