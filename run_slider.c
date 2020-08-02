#include <stdio.h>
#include <stdlib.h>
#include <uvsqgraphics.h>
#include "mes_types.h"
#include "lire_ecrire.h"
#include "afficher.h"
#include "deplacer_balle.h"
#include "editer_slider.h"
#include "mes_phenetres_graphiques.h"

void enchainer_niveau(SLIDER S,int argc,char **argv)
{
	
		char key;
		int i=1,cmpt=1;
	
	
	while(i<argc && cmpt==1)
	{
		S=lire_fichier(argv[i],S);
		printf("Debut slider\n");
		afficher_slider(S);
		S=detection_murs(S);
		deplace_balle(S);
		
		my_free(S.Tm,S.L,S.H);
		i++;
		key=fenetre_passage_niveau();
			if(key == 'c')
			cmpt = 1;	
			else
			cmpt = 0;
		 
	}
	
	
}

void jouer(int argc, char**argv,SLIDER S,char w)
{
 
    if(w=='j')
    {
enchainer_niveau(S,argc,argv);
}
if(w=='o' || w=='n')
{
int i=1;
POINT p;
int l,c,d,k;

if(w=='n')
{
    S=acceuil_editeur(S);
    p=wait_clic();
    l=chercher_ligne(S,p);
	c=chercher_colone(S,p);
    S=edit_slider(S,l,c);
    while(c==S.x_slider && l==S.y_slider)
    {
    p=wait_clic();
	l=chercher_ligne(S,p);
	c=chercher_colone(S,p);
    }
    S=edit_sortie(S,l,c);
    k=1;
    S.N=0;
while(i)
{
	p=wait_clic();
    l=chercher_ligne(S,p);
	c=chercher_colone(S,p);
	d=chercher_direction(S,p);
	
	if(p.y>S.H*TAILLE_CASE)
	  break;
	 
	 S=refaire_mur(S,l,c,d,&k);
	
	if(c==S.x_slider && l==S.y_slider && S.x_sortie!=S.x_slider && S.y_sortie!=S.y_slider)
		S=refaire_slideur(S);
	
	if(c==S.x_sortie && l==S.y_sortie && S.x_sortie!=S.x_slider && S.y_sortie!=S.y_slider)
	  S=refaire_sortie(S);
	
	if (k)
     S=edit_mur(S,l,c,d);

     k=1;
}
afficher_slider(S);
deplace_balle(S);
}

if(w=='o')
{
	S=lire_fichier("niveau-edite.slider",S);
	acceuil_editeur_existant(S);
	init_graphics_pour_edit(S);
	afficher_grille(S);
	afficher_le_slider(S);
	afficher_sortie(S);
	afficher_murs(S);
	S=detection_murs(S);
	k=1;
	
while(i)
{
	
	break;
	p=wait_clic();
    l=chercher_ligne(S,p);
	c=chercher_colone(S,p);
	d=chercher_direction(S,p);
	
	if(p.y>S.H*TAILLE_CASE)
	 break;
	
	 S=refaire_mur(S,l,c,d,&k);
	
	if(c==S.x_slider && l==S.y_slider)
		S=refaire_slideur(S);
	
	if(c==S.x_sortie && l==S.y_sortie)
		S=refaire_sortie(S);
	
	if (k)
        S=edit_mur(S,l,c,d);
k=1;
}
afficher_slider(S);
deplace_balle(S);	
} 
acceuil_saufgarde(S);
my_free(S.Tm,S.L,S.H);
}
}
