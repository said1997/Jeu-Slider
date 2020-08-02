#include "mes_types.h"
#include <stdlib.h>
#include "afficher.h"
#include <stdio.h>

elm *puch_liste(elm * liste,int x_slidd,int y_slidd) // c'est la meme cose que ajouter au début de la liste
{
	 elm * nouvel_elm;
	 nouvel_elm=malloc(sizeof(elm));
	 nouvel_elm->x_slid=x_slidd;
	 nouvel_elm->y_slid=y_slidd;
	 nouvel_elm->suivant=liste;
	 return nouvel_elm;
 }
elm *pop_Debut(elm * liste){
  elm * ll;
  if(liste->suivant!=NULL){
	
    ll = liste;
    liste = liste->suivant; 
    free(ll);
  }
  
  return liste;
}

elm *Restart(elm * liste){
  elm * ll;
  while(liste->suivant!=NULL){
	
    ll = liste;
    liste = liste->suivant;
    free(ll);
  }
  
  return liste;
}


SLIDER dessine_dernier_elm(elm * liste ,SLIDER S){
  if(liste != NULL){
    S.x_slider=liste->x_slid;
    S.y_slider=liste->y_slid;
    afficher_le_slider(S);
    }
    return S;
}
