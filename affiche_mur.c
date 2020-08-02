#include <stdio.h>
#include <stdlib.h>

Mur * crier_liste(Mur * liste,int c,int l, int d)
{
	Mur * new_elem;
	new_elem=malloc(sizeof(Mur));
	
	new_elem->C=c;
	new_elem->L=l;
	new_elem->D=d;
	new_elem->suivant=liste;
	
	return new_elem;
};

void afficher_liste(Mur *L)
{
	printf("affichage liste\n");
	Mur * p;
	for(p=L;p!=NULL;p=p->suivant)
	{
		printf("%d--%d--%d\n",p->C,p->L,p->D);
	}
}


