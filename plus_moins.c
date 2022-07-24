
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int plus_moins(int valeur_a_trouver, int choix_joueur) {

	if(choix_joueur<valeur_a_trouver)
	{
		printf("plus\n");
		return 0;
	}
	else if(choix_joueur>valeur_a_trouver)
	{
		printf("moins\n");
		return 0;
	}
	else
	{
		printf("bingo\n");
		return 1;
	}

}


int main() {
	int choix_joueur;
	int valeur_a_trouver;
	int lower = 1, upper = 100, count = 10;

	srand(time(0));

        valeur_a_trouver = (rand() % (upper - lower + 1)) + lower;
	printf("Entrez une valeur:");
	scanf("%d",&choix_joueur);

	while(plus_moins(valeur_a_trouver,choix_joueur)!=1) 
	{
		printf("Entrez une valeur:");
		scanf("%d",&choix_joueur);
	}
	return 0;
}
