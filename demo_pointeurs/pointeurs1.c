#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "pointeurs.h"


void swap1(int i,int j){
    int prov;
    prov=i;
    i=j;
    j=prov;
    printf("dans swap1: i=%d, j=%d\n",i,j);
}
void swap2(int *i,int *j){
    int *prov=i;
    i=j;
    j=prov;
    printf("dans swap2: i=%d, j=%d\n",*i,*j);
}
void swap3(int *i,int *j){
    int prov=*i;
    *i=*j;
    *j=prov;
    printf("dans swap3: i=%d, j=%d\n",*i,*j);
}
void swap(){
    int i=2,j=3;
    printf("\nswap de 2 variables. Avant: i=%d et j=%d\n",i,j);
    swap1(i,j);
    printf("après swap1: i=%d, j=%d\n",i,j);
    swap2(&i,&j);
    printf("après swap2: i=%d, j=%d\n\n",i,j);
    swap3(&i,&j);
    printf("après swap3: i=%d, j=%d\n\n",i,j);
}

void pointeurs1_main(){
    printf("\n---- fonction pointeurs1_main ----\n");
    int i=0,j=98;
    int *p=&j;
    printf("adresse de j: %i, valeur: %i\n",p,*p);
    printf("adresse de j: %i, valeur: %i\n",&j,*&j);
    printf("Adresse de i : %p\n", (void *)&i);
    
    int tab[5]={1,2,3};
    int *pt=tab;
    printf("%i\n",*pt);
    printf("%i\n",*++pt);
    
    
    
    char *lettre="abc";
    i=0;
    do
    {
        printf("%c\n",*lettre);
        lettre++;
    }while (*lettre!='\0');
    
    swap();
}