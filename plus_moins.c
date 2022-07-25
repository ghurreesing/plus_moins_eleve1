
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void plus_moins(int valeur_a_trouver, int choix_joueur) {

	if(choix_joueur<valeur_a_trouver)
	{
		printf("plus\n");
	}
	else if(choix_joueur>valeur_a_trouver)
	{
		printf("moins\n");
	}
	else
	{
		printf("bingo\n");
	}

}

int main() {

	int nombre_de_tour;
	bool defaite=false;
	int joueur=1;
	int score_joueur1=0;
	int score_joueur2=0;
	int temp1=0;
	int temp2=0;

        printf("Entrez le nombre de tour:"); 
        scanf("%d",&nombre_de_tour);
	printf("\n");



	while(nombre_de_tour>0 || defaite==false)
	{

		int choix_joueur;
        	int valeur_a_trouver;
        	int lower = 1, upper = 100, count = 10;
        	int nombre_de_coup;

        	srand(time(0));

        	valeur_a_trouver = (rand() % (upper - lower + 1)) + lower;

		if(joueur==1)
		{
			printf("Joueur 1, Entrez le nombre de coup supérieur à 10:");
        		scanf("%d",&nombre_de_coup);
			printf("\n");
			joueur=2;
			score_joueur2=nombre_de_coup;
			temp2=temp2+score_joueur2;
		}
		else if(joueur==2)
		{
			printf("Joueur 2, Entrez le nombre de coup supérieur à 10:");
                        scanf("%d",&nombre_de_coup);
			printf("\n");
			joueur=1;
			score_joueur1=nombre_de_coup;
			temp1=temp1+score_joueur1;
		}

		nombre_de_coup=nombre_de_coup+1;
		while(nombre_de_coup!=0)
		{
			nombre_de_coup=nombre_de_coup-1;
	 		if(nombre_de_coup!=0 && (valeur_a_trouver<choix_joueur || valeur_a_trouver>choix_joueur))
			{
        			if(joueur==1)
				{

	                                printf("Joueur 1, Entrez une valeur:");
                	                scanf("%d",&choix_joueur);
					if(valeur_a_trouver!=choix_joueur)
					{
                                        	plus_moins(valeur_a_trouver,choix_joueur);
						temp1=temp1-1;
					}
				}

                                else if(joueur==2)
                                {
                                        printf("Joueur 2, Entrez une valeur:");
                                       	scanf("%d",&choix_joueur);
                                        if(valeur_a_trouver!=choix_joueur)
                                        {
                                                plus_moins(valeur_a_trouver,choix_joueur);
						temp2=temp2 - 1;
                                        }
                                }
			}
			else if(valeur_a_trouver==choix_joueur)
			{
				plus_moins(valeur_a_trouver,choix_joueur);
				nombre_de_coup=0;
			}
			else if(nombre_de_coup==0)
			{
				defaite=true;
			}
		}

		nombre_de_tour=nombre_de_tour-1;
		 if (nombre_de_tour==0)
		 {
			break;
		 }
	}

	printf("Score totale joueur 1: %d\n",temp1);
	printf("Score totale joueur 2: %d\n",temp2);


	if(temp1>temp2)
	{
		printf("Joueur 1 est le gagnant\n");
	}
	else
	{
		printf("Joueur 2 est le gagnant\n");
	}
	return 0;
}
