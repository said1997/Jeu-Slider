#include <uvsqgraphics.h>
#include "mes_types.h"
#include "afficher.h"
#include "pop_puch.h"

SLIDER detection_murs(SLIDER S) {
	
	int i,j;
	
	for(i=0 ; i < S.L; i++)
{
     for(j=0 ; j < S.H; j++)
     {
		  if (S.Tm[i][j][G_TAB]==1 && i>0) 
			S.Tm[i-1][j][D_TAB]=1;		 
	     
	     if (S.Tm[i][j][D_TAB]==1 && i<S.L-1)
			S.Tm[i+1][j][G_TAB]=1;
	
	     if (S.Tm[i][j][H_TAB]==1 && j<S.H-1) 
			S.Tm[i][j+1][B_TAB]=1;
		 
		 if (S.Tm[i][j][B_TAB]==1 && j>0) 
			S.Tm[i][j-1][H_TAB]=1;
	  }
}
return S;	
		
}
int tester_sortie(SLIDER S)
{ 
	if((S.x_slider==S.x_sortie) && (S.y_slider==S.y_sortie))
	{
		attendre(200);
		return 0;
	}	
	return 1;
}

void deplace_balle(SLIDER S)
{
	elm * l=NULL;
	int arrow;
    
    l=puch_liste(l,S.x_slider,S.y_slider);
while(tester_sortie(S)) // je teste tant que les cohordonnées de ma balle sont différents de celles de la sortie 
{
	afficher_le_slider(S);
	 arrow=get_key();
	 attendre(50);
	 if(arrow==FLECH_DROITE || arrow==FLECH_GAUCHE || arrow==FLECH_HAUT || arrow==FLECH_BAS || arrow==U || arrow==R || arrow==Q) //la fonction me renvoie le code ASCII de chaque touche du clavier et (275,276,273,274) sont le code ASCII des fleches du clavier 
	 {
		  effacer_le_slider(S);
		  if(arrow==Q)
		   break;
		 if(arrow==U)
		 { //je d'epile de ma pile
			 effacer_le_slider(S);
		   l=pop_Debut(l);
		   S=dessine_dernier_elm(l,S);
	   }
	   if(arrow==R)
		 {  //je depile toute ma pile pour revenir au debut
			 effacer_le_slider(S);
		   l=Restart(l);
		   S=dessine_dernier_elm(l,S);
	   }
	   
while(S.x_slider<S.L && S.y_slider<S.H && S.x_slider>=0 && S.y_slider>=0 && tester_sortie(S)==1) // conditions pour ne pas sortir de ma fenetre graphique
 {
	
	 attendre(40);
	 effacer_le_slider(S);
	 if(arrow==U || arrow==R)
	  break;
	 if (arrow==FLECH_DROITE)
	 {
		 if (S.Tm[S.x_slider][S.y_slider][D_TAB]==0)
	     S.x_slider=S.x_slider+1;  
	     else
	      break;
      }
	 if (arrow==FLECH_GAUCHE)
	 {
		if (S.Tm[S.x_slider][S.y_slider][G_TAB]==0) 
			S.x_slider=S.x_slider-1; 
	    else
	     break;
     }
	 if (arrow==FLECH_HAUT)
	 {
		if (S.Tm[S.x_slider][S.y_slider][H_TAB]==0)
	          S.y_slider=S.y_slider+1; 
	    else
	     break; 
     }
	 if (arrow==FLECH_BAS)
	 {
		if (S.Tm[S.x_slider][S.y_slider][B_TAB]==0)
	     S.y_slider=S.y_slider-1;
	    else
	     break;
     }
      afficher_le_slider(S);
}
// les 4 (if) pour remettre ma balle a l'interieur de ma fenetre en cas ou elle deborde 
if(S.x_slider==S.L)
 S.x_slider=S.x_slider-1;

if(S.y_slider==S.H)
{ effacer_le_slider(S);
 S.y_slider=S.y_slider-1;
}

if(S.x_slider<0)
 S.x_slider=0;

if(S.y_slider<0)
 S.y_slider=0;
   if(arrow!=U && arrow!=R)
     l=puch_liste(l,S.x_slider,S.y_slider);//j'empile dans ma pile
   
}
 
}

}


