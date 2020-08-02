#include "mes_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <uvsqgraphics.h>
#include "lire_ecrire.h"
#include "afficher.h"
#include "mes_phenetres_graphiques.h"

int chercher_colone (SLIDER S ,POINT p)
{
	int c;
	for(c=1;c<=S.L;c++)
	{
		if(p.x<c*TAILLE_CASE)
		     return c-1;
	
}
	return 0;
}
int chercher_ligne(SLIDER S ,POINT p)
{
	int l;
	for(l=1;l<=S.H;l++)
	{
		if(p.y<l*TAILLE_CASE)
         {
			 return l-1;
		 }	
	
}
return 0;

}
int chercher_direction(SLIDER S ,POINT p)
{
	int c,l;
	for(c=1;c<=S.L;c++)
	{
		if(p.x<c*TAILLE_CASE)
         {
			 if(c*TAILLE_CASE-(TAILLE_CASE/5)<p.x && p.x<c*TAILLE_CASE+(TAILLE_CASE/5))
			 return DROITE;
			 
			 if((c*TAILLE_CASE-TAILLE_CASE)-(TAILLE_CASE/5)<p.x && p.x<(c*TAILLE_CASE-TAILLE_CASE)+(TAILLE_CASE/5))
			 return GAUCHE;
		 }	
	
}
for(l=1;l<=S.H;l++)
	{
		if(p.y<l*TAILLE_CASE)
         {
			 if(l*TAILLE_CASE-(TAILLE_CASE/5)<p.y && p.y<l*TAILLE_CASE+(TAILLE_CASE/5))
			 return HAUT;
			 
			 if((l*TAILLE_CASE-TAILLE_CASE)-(TAILLE_CASE/5)<p.y && p.y<(l*TAILLE_CASE-TAILLE_CASE)+(TAILLE_CASE/5))
			 return BAS;
				
		 }	
	
}
return 5;
}


SLIDER edit_slider(SLIDER S,int l,int c)
{
        S.x_slider=c;
        S.y_slider=l;
        afficher_le_slider(S);
		return S;
}
SLIDER refaire_slideur(SLIDER S)
{
	int l,c;
	POINT p;
	effacer_le_slider(S);
		p=wait_clic();
		l=chercher_ligne(S,p);
	    c=chercher_colone(S,p);
		S=edit_slider(S,l,c);
		return S;
	
}

SLIDER edit_sortie(SLIDER S,int l,int c)
{
        S.x_sortie=c;
        S.y_sortie=l;
        afficher_sortie(S);
		return S;
}
SLIDER refaire_sortie(SLIDER S)
{
	int l,c;
	POINT p;
	effacer_sortie(S);
		p=wait_clic();
		l=chercher_ligne(S,p);
	    c=chercher_colone(S,p);
		S=edit_sortie(S,l,c);
		return S;
	
}

SLIDER edit_mur(SLIDER S,int l, int c,int d_mur)
{
	   if (d_mur==GAUCHE)
	    {
			if(S.Tm[c][l][G_TAB]==0 || S.Tm[c-1][l][D_TAB]==0 )
			{
	      S.Tm[c][l][G_TAB]=1;
	      if (S.Tm[c][l][G_TAB]==1 && c>0) 
	      S.Tm[c-1][l][D_TAB]=1;
	      dessine_mur(l,c,d_mur);
	      S.N=S.N+1;
	      
		    }
	    }
	    if (d_mur==DROITE)
	    {
			if(S.Tm[c][l][D_TAB]==0 || S.Tm[c+1][l][H_TAB]==1)
			{
	      S.Tm[c][l][D_TAB]=1;
	      if (S.Tm[c][l][D_TAB]==1 && c<S.L-1)
	      S.Tm[c+1][l][G_TAB]=1;
	      dessine_mur(l,c,d_mur);
	      S.N=S.N+1;
	       
		    }
	    }
	    if (d_mur==HAUT)
	    {
			if(S.Tm[c][l][H_TAB]==0 ||  S.Tm[c][l+1][B_TAB]==0)
			{
	      S.Tm[c][l][H_TAB]=1;
	         if (S.Tm[c][l][H_TAB]==1 && l<S.H-1) 
	      S.Tm[c][l+1][B_TAB]=1;
	      dessine_mur(l,c,d_mur);
	      S.N=S.N+1;
			}
	    }
	    if (d_mur==BAS)
	    {
			if(S.Tm[c][l][B_TAB]==0 || S.Tm[c][l-1][H_TAB]==0)
			{
	      S.Tm[c][l][B_TAB]=1;
	      if (S.Tm[c][l][B_TAB]==1 && l>0) 
	      S.Tm[c][l-1][H_TAB]=1;
	      dessine_mur(l,c,d_mur);
	      S.N=S.N+1;
	       
			}
	    }
		return S;
}
			
SLIDER refaire_mur(SLIDER S,int l,int c,int d,int * a)
{
	if (S.Tm[c][l][G_TAB]==1 && d==GAUCHE && S.Tm[c-1][l][D_TAB]==1) // je teste si mon mur est a gauche et je le dessine 
		 {
			 efface_mur(l,c,d);
			 S.N=S.N-1;
		     S.Tm[c][l][G_TAB]=0;
		     S.Tm[c-1][l][D_TAB]=0;
		     *a=0;
		     
		 }
	     if (S.Tm[c][l][D_TAB]==1 && d==DROITE && S.Tm[c+1][l][G_TAB]==1) // je teste si mon mur est a droite et je le dessine
		 {
			 efface_mur(l,c,d);
			 S.N=S.N-1;
		     S.Tm[c][l][D_TAB]=0;
		     S.Tm[c+1][l][G_TAB]=0;
		     *a=0;
	     }
	     if (S.Tm[c][l][H_TAB]==1 && d==HAUT && S.Tm[c][l+1][B_TAB]==1) // je teste si mon mur est en haut et je le dessine
		 {
			 efface_mur(l,c,d);
			 S.N=S.N-1;
		     S.Tm[c][l][H_TAB]=0;
		     S.Tm[c][l+1][B_TAB]=0;
		     *a=0;
	     }
		 if (S.Tm[c][l][B_TAB]==1 && d==BAS && S.Tm[c][l-1][H_TAB]==1) // je teste si mon mur est en bas et je le dessine
		 {
			 efface_mur(l,c,d);
			 S.N=S.N-1;
		     S.Tm[c][l][B_TAB]=0;
		     S.Tm[c][l-1][H_TAB]=0;
		     *a=0;
	      }
	  
	      return S;
	
}

void saufgarder_mon_jeu(SLIDER S)
{
	FILE *fichier;
	
	fichier=fopen("niveau-edite.slider","w");
	
	fprintf(fichier,"%d %d\n",S.L,S.H);
	fprintf(fichier,"%d %d\n",S.x_slider,S.y_slider);
	fprintf(fichier,"%d %d\n",S.x_sortie,S.y_sortie);
	fprintf(fichier,"%d\n",S.N);
	
	int i,j;
	
	for(i=0 ; i < S.L; i++)
   {
     for(j=0 ; j < S.H; j++)
     {
		 if (S.Tm[i][j][G_TAB]==1 && i>0) // je teste si mon mur est a gauche et je le dessine 
		 {
			 S.Tm[i-1][j][D_TAB]=0;
			fprintf(fichier,"%d %d %d\n",i,j,GAUCHE);
		 }
	     if (S.Tm[i][j][D_TAB]==1 && i<S.L-1) // je teste si mon mur est a droite et je le dessine
		 {
			 S.Tm[i+1][j][G_TAB]=0;
			fprintf(fichier,"%d %d %d\n",i,j,DROITE);
	     }
	     if (S.Tm[i][j][H_TAB]==1 && j<S.H-1) // je teste si mon mur est en haut et je le dessine
		 {
			 S.Tm[i][j+1][B_TAB]=0; 
			 fprintf(fichier,"%d %d %d\n",i,j,HAUT);
	         
	     }
		 if (S.Tm[i][j][B_TAB]==1 && j>0) // je teste si mon mur est en bas et je le dessine
		 {
			 S.Tm[i][j-1][H_TAB]=0;
			fprintf(fichier,"%d %d %d\n",i,j,BAS);
	      }
     }
   }
   
   fclose(fichier);
   	
		
	
}


