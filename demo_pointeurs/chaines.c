#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "pointeurs.h"



void guess_word(){
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

void demande_plusieurs_variables(){
	int i = 0;
	float x = 0;
	char str[10];
	// remarquer que str n'est pas préfixer de & car un tableau est déjà un pointeur
	// et une chaine est un tableau.
	printf("entrez dans cet ordre: [un entier] [un decimal] [une chaine sans espace]:");
	scanf("%d %f %s", &i, &x, str);
	printf("vous avez saisi: [%d] [%f] [%s]\n\n",i,x,str);
}

void alloc_statique(){
	// meme chose avec une allocation statique de mémoire :
	char mot2[10];  // alloue pour 9 caractères (penser au 0 final)
	printf("alloc statique - saisir un mot de 9 lettres max:\n");
	scanf("%9s",mot2);  // lit au plus 5 caractères (et s'arrette au  premier espace, tab ou retoure chariot)
	// important d'uitliser cette limitation sur le formatage de saisie pour ne pas dépasser de la zone allouée en mémoire 
	// sinon => source de piratgage
	printf("mot2->%s\n",mot2);

}	
void alloc_dynamique(){
    char* mot1 = (char*)malloc(6 * sizeof(char));
    printf("alloc dynamique - saisir un mot de 5 lettres max:\n");
    scanf("%5s",mot1);  // lit au plus 5 caractères (et s'arrette au  premier espace, tab ou retoure chariot)
	// important d'uitliser cette limitation sur le formatage de saisie pour ne pas dépasser de la zone allouée en mémoire 
	// sinon => source de piratgage
    printf("mot1->%s\n",mot1);
}

void chaines(){
    printf("\n---- fonction chaines ----\n");

	alloc_statique();
    alloc_dynamique();

	guess_word();

	demande_plusieurs_variables();
}
