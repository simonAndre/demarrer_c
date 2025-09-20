#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "pointeurs.h"

void chaines(){
	char mot1[20];
	char mot2[20]="tot";
	bool won=false;
    printf("\nrepète tant que votre mot n'est pas : %s\n",mot2);
	do {
		printf("entrez un mot: ");
		scanf("%s",mot1);
		if(strcmp(mot1,mot2)==0) 
		{
			won=true;
			printf("GAGNE!\n");
		}
	} while (won==false);
	

}

void pointeur1(){
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
    
    // char *mot;
    char* mot = (char*)malloc(10 * sizeof(char));
    printf("saisir un mot:\n");
    scanf("%s",mot);
    printf("->%s\n",mot);
}