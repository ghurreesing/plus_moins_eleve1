
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
	int niveau;

	srand(time(0));

	valeur_a_trouver = (rand() % (upper - lower + 1)) + lower;

	printf("Choisissez le mode de difficulté:\n"); 
	printf("1. Facile --> Nombre d'essaie illimités\n");
	printf("2. Moyen --> Nombre d'essaie 25\n");
	printf("3. Difficile --> Nombre d'essaie 10\n");
	printf("Entrez le niveau 1, 2 ou 3: ");
	scanf("%d",&niveau);
	if (niveau==1 || niveau==2 || niveau==3)
	{

		printf("Entrez une valeur:");
                scanf("%d",&choix_joueur);

		if(niveau==1)
		{ 
			while(plus_moins(valeur_a_trouver,choix_joueur)!=1) 
			{
				printf("Entrez une valeur:");
				scanf("%d",&choix_joueur);
			}
		}
		else if (niveau==2)
		{
			for(int i=0;i<25;i++)
			{
				if(plus_moins(valeur_a_trouver,choix_joueur)!=1 && i<=23) 
				{
					printf("Entrez une valeur:");
                                	scanf("%d",&choix_joueur);
				}
				else
				{
					i=25;  //reach end of loop if guessed correctly
				}
			}
		}
		else if(niveau==3)
		{
                        for(int i=0;i<10;i++)
                        {
                                if(plus_moins(valeur_a_trouver,choix_joueur)!=1 && i<=8) 
                                {
                                        printf("Entrez une valeur:");
                                        scanf("%d",&choix_joueur);
                                }

                                else
                                {
                                        i=10; //reach end of loop if guessed correctly

                                }

                        }
		}

	}
	return 0;
}
