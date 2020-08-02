#include <stdio.h>
#include <stdlib.h>
#include "mes_types.h"

void my_free(int ***ptr,int tailleDejaAllouee1,int tailleDejaAllouee2){

    int i,j;

    if(ptr!=NULL)
  {
    for(i=0 ; i < tailleDejaAllouee1 ; i++)
    {
		
         for(j=0 ; j < tailleDejaAllouee2 ; j++)
         {

               free(ptr[i][j]);

         }

         free(ptr[i]);

    }
    free(ptr);
 }
}

int ***allocation_tab_trois_dim(int ***ptr,int l,int c)
{
	
int mur=4;
int i,j;

ptr = malloc(l * sizeof(*ptr));

for(i=0 ; i < l ; i++)
{
	ptr[i] = malloc(c * sizeof(**ptr));
}
for(i=0 ; i < l; i++){
     for(j=0 ; j < c ; j++)
     {
		  ptr[i][j] = malloc(mur* sizeof(1));  
     }
}

for(i=0 ; i < l; i++) //initialisation des cases de mon tab à 4 colones de murs 
{
     for(j=0 ; j < c; j++)
     {
		 ptr[i][j][G_TAB]=0;
		 ptr[i][j][D_TAB]=0;
		 ptr[i][j][H_TAB]=0;
		 ptr[i][j][B_TAB]=0;
		 
    }
}
 return(ptr);
}


SLIDER lire_fichier(char *nom , SLIDER S) {
	
	printf("nom du fichier ouvert = %s\n",nom);
	
	FILE *fichier=NULL;
	fichier=fopen(nom,"r");
    
    if(fichier!=NULL)
	{
	printf("fichier ouvet\n");
	
    }
	else 
	{
	printf("fichier non ouvert\n");
    }
	
	fscanf(fichier,"%d",&S.L);
	fscanf(fichier,"%d",&S.H);
	
	fscanf(fichier,"%d",&S.x_slider);
    fscanf(fichier,"%d",&S.y_slider);
	
	fscanf(fichier,"%d",&S.x_sortie);
	fscanf(fichier,"%d",&S.y_sortie);
	
	fscanf(fichier,"%d",&S.N);
	printf("nbr_mur=%d\n",S.N);
	S.Tm=allocation_tab_trois_dim(S.Tm,S.L,S.H);
	
	int x_mur,y_mur,d_mur,i;
	
	for(i=0;i<S.N;i++)
	{
		fscanf(fichier,"%d %d %d",&x_mur,&y_mur,&d_mur); //stoquer les valeurs dans un tableau 
	    if (d_mur==GAUCHE)
	      S.Tm[x_mur][y_mur][G_TAB]=1;
	    if (d_mur==DROITE)
	      S.Tm[x_mur][y_mur][D_TAB]=1;
	    if (d_mur==HAUT)
	      S.Tm[x_mur][y_mur][H_TAB]=1;
	    if (d_mur==BAS)
	      S.Tm[x_mur][y_mur][B_TAB]=1;
	}
		fclose(fichier);
	return S;
}
	

