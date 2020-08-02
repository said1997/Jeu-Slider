#include <uvsqgraphics.h>
#include "mes_types.h"
#include <stdio.h>
#include <stdlib.h>
#include "mes_phenetres_graphiques.h"

void initialiser_affichage(SLIDER S) {
	init_graphics (TAILLE_CASE*S.L,TAILLE_CASE*S.H);
	fill_screen(blanc);
}

void afficher_grille(SLIDER S) {
	
	POINT p1,p2;
	p1.y=0; p2.y=TAILLE_CASE*S.H;
	
	for(p1.x=0;p1.x<=TAILLE_CASE*S.L;p1.x=p1.x+TAILLE_CASE)
	{ 
		p2.x=p1.x;
		draw_line(p1,p2,rouge);
		
	}
	p1.x=0; p2.x=50*S.L;
	for(p1.y=0;p1.y<=TAILLE_CASE*S.H;p1.y=p1.y+TAILLE_CASE)
	{
		
		p2.y=p1.y;
		draw_line(p1,p2,rouge);
	}
	
	
	
}

void afficher_le_slider(SLIDER S) {

	POINT p;
	p.x=(TAILLE_CASE+S.x_slider*TAILLE_CASE)-(TAILLE_CASE/2);
	p.y=(TAILLE_CASE+S.y_slider*TAILLE_CASE)-(TAILLE_CASE/2);
	draw_fill_circle(p,TAILLE_SLIDER,couleur_alea());

}

void finir_affichage() {
	wait_escape();
}

void afficher_sortie(SLIDER S) {
	POINT p,p1,p2;
	p.x=((TAILLE_CASE+S.x_sortie*TAILLE_CASE)-(TAILLE_CASE/2));
	p.y=((TAILLE_CASE+S.y_sortie*TAILLE_CASE)-(TAILLE_CASE/2));
	p1.x=p.x-(TAILLE_CASE/2-1);p1.y=p.y-(TAILLE_CASE/2-1);
	p2.x=p.x+(TAILLE_CASE/2-1);p2.y=p.y+(TAILLE_CASE/2-1);
	draw_fill_rectangle(p1,p2,couleur_alea());
	p.x=((TAILLE_CASE+S.x_sortie*TAILLE_CASE)-(TAILLE_CASE/2))-25;
	p.y=((TAILLE_CASE+S.y_sortie*TAILLE_CASE)-(TAILLE_CASE/2))+20;
	aff_pol("exit",TAILLE_CASE/2,p,couleur_alea());
	
	
}
void effacer_sortie(SLIDER S) {
	POINT p,p1,p2;
	p.x=((TAILLE_CASE+S.x_sortie*TAILLE_CASE)-(TAILLE_CASE/2));
	p.y=((TAILLE_CASE+S.y_sortie*TAILLE_CASE)-(TAILLE_CASE/2));
	p1.x=p.x-(TAILLE_CASE/2-1);p1.y=p.y-(TAILLE_CASE/2-1);
	p2.x=p.x+(TAILLE_CASE/2-1);p2.y=p.y+(TAILLE_CASE/2-1);
	draw_fill_rectangle(p2,p1,blanc);
	p.x=((TAILLE_CASE+S.x_sortie*TAILLE_CASE)-(TAILLE_CASE/2))-25;
	p.y=((TAILLE_CASE+S.y_sortie*TAILLE_CASE)-(TAILLE_CASE/2))+20;
	aff_pol("exit",TAILLE_CASE/2,p,blanc);
	
	
}
void dessine_mur(int l ,int c,int d)
{
	POINT p,p1,p2;
	if(d==GAUCHE)
	{
		p.x=(TAILLE_CASE+c*TAILLE_CASE)-(TAILLE_CASE/2);p.y=(TAILLE_CASE+l*TAILLE_CASE)-(TAILLE_CASE/2); 
		p1.x=p.x-(TAILLE_CASE/2+3);p1.y=p.y-(TAILLE_CASE/2); p2.x=p.x-(TAILLE_CASE/2-3);p2.y=p.y+(TAILLE_CASE/2);
		     draw_fill_rectangle(p1,p2,couleur_alea());
	}
	if(d==DROITE)
	{
		p.x=(TAILLE_CASE+c*TAILLE_CASE)-(TAILLE_CASE/2); p.y=(TAILLE_CASE+l*TAILLE_CASE)-(TAILLE_CASE/2); 
		p1.x=p.x+(TAILLE_CASE/2+3);p1.y=p.y-(TAILLE_CASE/2); p2.x=p.x+(TAILLE_CASE/2-3);p2.y=p.y+(TAILLE_CASE/2);
		     draw_fill_rectangle(p1,p2,couleur_alea());
	}
	if(d==HAUT)
	{
		p.x=(TAILLE_CASE+c*TAILLE_CASE)-(TAILLE_CASE/2); p.y=(TAILLE_CASE+l*TAILLE_CASE)-(TAILLE_CASE/2); 
		p1.x=p.x-(TAILLE_CASE/2);p1.y=p.y+(TAILLE_CASE/2+3); p2.x=p.x+(TAILLE_CASE/2);p2.y=p.y+(TAILLE_CASE/2-3);
		   draw_fill_rectangle(p1,p2,couleur_alea());
	}
	if(d==BAS)
	{
		p.x=(TAILLE_CASE+c*TAILLE_CASE)-(TAILLE_CASE/2); p.y=(TAILLE_CASE+l*TAILLE_CASE)-(TAILLE_CASE/2); 
		p1.x=p.x-(TAILLE_CASE/2);p1.y=p.y-(TAILLE_CASE/2+3); p2.x=p.x+(TAILLE_CASE/2);p2.y=p.y-(TAILLE_CASE/2-3);
		     draw_fill_rectangle(p1,p2,couleur_alea());	
	}
	
}
void efface_mur(int l ,int c,int d)
{
	POINT p,p1,p2;
	if(d==GAUCHE)
	{
		p.x=(TAILLE_CASE+c*TAILLE_CASE)-(TAILLE_CASE/2);p.y=(TAILLE_CASE+l*TAILLE_CASE)-(TAILLE_CASE/2); p1.x=p.x-(TAILLE_CASE/2+3);p1.y=p.y-(TAILLE_CASE/2); p2.x=p.x-(TAILLE_CASE/2-3);p2.y=p.y+(TAILLE_CASE/2);
		     draw_fill_rectangle(p1,p2,blanc);
		      p1.x=p.x-(TAILLE_CASE/2);p1.y=p.y-(TAILLE_CASE/2); p2.x=p.x-(TAILLE_CASE/2);p2.y=p.y+(TAILLE_CASE/2);
		     draw_line(p1,p2,rouge);
	}
	if(d==DROITE)
	{
		p.x=(TAILLE_CASE+c*TAILLE_CASE)-(TAILLE_CASE/2); p.y=(TAILLE_CASE+l*TAILLE_CASE)-(TAILLE_CASE/2); p1.x=p.x+(TAILLE_CASE/2+3);p1.y=p.y-(TAILLE_CASE/2); p2.x=p.x+(TAILLE_CASE/2-3);p2.y=p.y+(TAILLE_CASE/2);
		     draw_fill_rectangle(p1,p2,blanc);
		     p1.x=p.x+(TAILLE_CASE/2);p1.y=p.y-(TAILLE_CASE/2); p2.x=p.x+(TAILLE_CASE/2);p2.y=p.y+(TAILLE_CASE/2);
		     draw_line(p1,p2,rouge);
	}
	if(d==HAUT)
	{
		p.x=(TAILLE_CASE+c*TAILLE_CASE)-(TAILLE_CASE/2); p.y=(TAILLE_CASE+l*TAILLE_CASE)-(TAILLE_CASE/2); p1.x=p.x-(TAILLE_CASE/2);p1.y=p.y+(TAILLE_CASE/2+3); p2.x=p.x+(TAILLE_CASE/2);p2.y=p.y+(TAILLE_CASE/2-3);
		     draw_fill_rectangle(p1,p2,blanc);
		     p1.x=p.x-(TAILLE_CASE/2);p1.y=p.y+(TAILLE_CASE/2); p2.x=p.x+25;p2.y=p.y+(TAILLE_CASE/2);
		     draw_line(p1,p2,rouge);
	}
	if(d==BAS)
	{
       p.x=(TAILLE_CASE+c*TAILLE_CASE)-(TAILLE_CASE/2); p.y=(TAILLE_CASE+l*TAILLE_CASE)-(TAILLE_CASE/2); p1.x=p.x-(TAILLE_CASE/2);p1.y=p.y-(TAILLE_CASE/2+3); p2.x=p.x+(TAILLE_CASE/2);p2.y=p.y-(TAILLE_CASE/2-3);
		     draw_fill_rectangle(p1,p2,blanc);
		     p1.x=p.x-(TAILLE_CASE/2);p1.y=p.y-(TAILLE_CASE/2); p2.x=p.x+(TAILLE_CASE/2);p2.y=p.y-(TAILLE_CASE/2);
		     draw_line(p1,p2,rouge);
	}
	
}
void afficher_murs(SLIDER S) {
	int i,j;
	for(i=0 ; i < S.L; i++)
   {
     for(j=0 ; j < S.H; j++)
     {
		 if (S.Tm[i][j][G_TAB]==1) // je teste si mon mur est a gauche et je le dessine 
		 {
			dessine_mur(j,i,GAUCHE);
		 }
	     if (S.Tm[i][j][D_TAB]==1) // je teste si mon mur est a droite et je le dessine
		 {
			 dessine_mur(j,i,DROITE);
	     }
	     if (S.Tm[i][j][H_TAB]==1) // je teste si mon mur est en haut et je le dessine
		 {
			 dessine_mur(j,i,HAUT);
	         
	     }
		 if (S.Tm[i][j][B_TAB]==1) // je teste si mon mur est en bas et je le dessine
		 {
			 dessine_mur(j,i,BAS);
	      }
     }
   }	
		
}

void afficher_slider (SLIDER S) {
	initialiser_affichage(S);
	afficher_grille(S);
	afficher_le_slider(S);
	afficher_sortie(S);
	afficher_murs(S);
}

void effacer_le_slider(SLIDER S) {

	POINT p;
	p.x=(TAILLE_CASE+S.x_slider*TAILLE_CASE)-(TAILLE_CASE/2);
	p.y=(TAILLE_CASE+S.y_slider*TAILLE_CASE)-(TAILLE_CASE/2);
	draw_fill_circle(p,TAILLE_SLIDER,blanc);

}





	
