#include "mes_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <uvsqgraphics.h>
#include "lire_ecrire.h"
#include "afficher.h"
#include "editer_slider.h"
COULEUR couleur_alea()
{
	int r,g,b;
	COULEUR COUL;
	
	r=alea_int(250);
	g=alea_int(250);
	b=alea_int(250);
	COUL=couleur_RGB(r,g,b);
	
	return COUL;
	
}
char fenetre_passage_niveau()
{
	init_graphics(800,600);
	 fill_screen(blanc);
	 POINT p,p1,p2;
	 
	 p.x=620; p.y=600; p1.x=(p.x-20)-5;p1.y=(p.y-15)-5; p2.x=(p.x-20)+5;p2.y=(p.y-15)+5;
	 draw_fill_rectangle(p1,p2,vert);
	 aff_pol("Retour au menu",20,p,couleur_alea());
	
	p.x=300; p.y=500; p1.x=(p.x-20)-10;p1.y=(p.y-40)-10; p2.x=(p.x-20)+10;p2.y=(p.y-40)+10;
	draw_fill_rectangle(p1,p2,couleur_alea());
	aff_pol("CONTINUER",50,p,couleur_alea());
	
	p1.x=200; p1.y=300;
	
	int i=1;
	while(i)
	{
        aff_pol("BRAVOO!",100,p1,couleur_alea());
		p=wait_clic();
		    if(610<p.x && p.x<780 && 580<p.y && p.y<595)
              break;
            if(305<p.x && p.x<600 && 450<p.y && p.y<490)
              return 'c';      
		
	}
	
	return 0;
	
}

void acceuil_editeur_existant(SLIDER S)
{
	
	init_graphics(800,600);
	fill_screen(blanc);
	POINT p,p1,p2;
	
	p.x=150; p.y=470; p1.x=(p.x-20)-5; p1.y=(p.y-15)-5; p2.x=(p.x-20)+5;p2.y=(p.y-15)+5;
	draw_fill_rectangle(p1,p2,vert);
	aff_pol("premier clic affiche le slider",20,p,couleur_alea());
	
	p.x=150; p.y=440; p1.x=(p.x-20)-5; p1.y=(p.y-15)-5; p2.x=(p.x-20)+5;p2.y=(p.y-15)+5;
	draw_fill_rectangle(p1,p2,vert);
	aff_pol("second clic affiche la sortie",20,p,couleur_alea());
	
	p.x=150; p.y=410; p1.x=(p.x-20)-5; p1.y=(p.y-15)-5; p2.x=(p.x-20)+5;p2.y=(p.y-15)+5;
	draw_fill_rectangle(p1,p2,vert);
	aff_pol("Second clic sur le slider permet de le prendre et le deplacer",20,p,couleur_alea());
	
	p.x=150; p.y=380; p1.x=(p.x-20)-5;p1.y=(p.y-15)-5; p2.x=(p.x-20)+5;p2.y=(p.y-15)+5;
	draw_fill_rectangle(p1,p2,vert);
	aff_pol("Second clic sur la sortie permet de la prendre et la deplacer",20,p,couleur_alea());
	
	p.x=150; p.y=350; p1.x=(p.x-20)-5;p1.y=(p.y-15)-5; p2.x=(p.x-20)+5;p2.y=(p.y-15)+5;
	draw_fill_rectangle(p1,p2,vert);
	aff_pol("Pour afficher un mur on clic sur le cadrillage",20,p,couleur_alea());
	
	p.x=150; p.y=320; p1.x=(p.x-20)-5;p1.y=(p.y-15)-5; p2.x=(p.x-20)+5;p2.y=(p.y-15)+5;
	draw_fill_rectangle(p1,p2,vert);
	aff_pol("Second clic sur le mur permet de l'effacer",20,p,couleur_alea());
	
	p.x=250; p.y=205; p1.x=(p.x-20)-10;p1.y=(p.y-40)-10; p2.x=(p.x-20)+10;p2.y=(p.y-40)+10;
	draw_fill_rectangle(p1,p2,rouge);
	aff_pol("Commencer",50,p,couleur_alea());
	int i=1;
	
	while(i)
	{ p=wait_clic();
		if(250<p.x && p.x<540 && 155<p.y && p.y<190)
		  break;	
	}
}

void init_graphics_pour_edit(SLIDER S)
{
	POINT p1,p2,p;
	
	init_graphics (TAILLE_CASE*S.L,TAILLE_CASE*S.H+30);
	fill_screen(blanc);
	p.x=5; p.y=S.H*TAILLE_CASE+30; p1.x=(p.x-20)-5;p1.y=(p.y-15)-5; p2.x=(p.x-20)+5;p2.y=(p.y-15)+5;
	draw_fill_rectangle(p1,p2,vert);
	if (S.L<12)
	aff_pol("Appuyer ici pour commencer",2*S.L,p,couleur_alea());
	else
	aff_pol("Appuyer ici pour commencer",1.5*S.L,p,couleur_alea());

}

SLIDER acceuil_editeur(SLIDER S)
{
	
	init_graphics(800,600);
	fill_screen(blanc);
	POINT p,p1,p2;
	
	p.x=150; p.y=580; p1.x=(p.x-20)-10;p1.y=(p.y-20)-10; p2.x=(p.x-20)+10;p2.y=(p.y-20)+10;
	draw_fill_rectangle(p1,p2,vert);
	aff_pol("Entrez dans le terminal nombre de lignes",30,p,couleur_alea());
	
	p.x=150; p.y=520; p1.x=(p.x-20)-10; p1.y=(p.y-20)-10; p2.x=(p.x-20)+10;p2.y=(p.y-20)+10;
	draw_fill_rectangle(p1,p2,vert);
	aff_pol("Entrer le nombre de colonnes",30,p,couleur_alea());
	
	p.x=150; p.y=470; p1.x=(p.x-20)-5; p1.y=(p.y-15)-5; p2.x=(p.x-20)+5;p2.y=(p.y-15)+5;
	draw_fill_rectangle(p1,p2,vert);
	aff_pol("premier clic affiche le slider",20,p,couleur_alea());
	
	p.x=150; p.y=440; p1.x=(p.x-20)-5;p1.y=(p.y-15)-5; p2.x=(p.x-20)+5;p2.y=(p.y-15)+5;
	draw_fill_rectangle(p1,p2,vert);
	aff_pol("second clic affiche la sortie",20,p,couleur_alea());
	
	p.x=150; p.y=410; p1.x=(p.x-20)-5;p1.y=(p.y-15)-5; p2.x=(p.x-20)+5;p2.y=(p.y-15)+5;
	draw_fill_rectangle(p1,p2,vert);
	aff_pol("Second clic sur le slider permet de le prendre et le deplacer",20,p,couleur_alea());
	
	p.x=150; p.y=380; p1.x=(p.x-20)-5;p1.y=(p.y-15)-5; p2.x=(p.x-20)+5;p2.y=(p.y-15)+5;
	draw_fill_rectangle(p1,p2,vert);
	aff_pol("Second clic sur la sortie permet de la prendre et la deplacer",20,p,couleur_alea());
	
	p.x=150; p.y=350; p1.x=(p.x-20)-5;p1.y=(p.y-15)-5; p2.x=(p.x-20)+5;p2.y=(p.y-15)+5;
	draw_fill_rectangle(p1,p2,vert);
	aff_pol("Pour afficher un mur on clic sur le cadrillage",20,p,couleur_alea());
	
	p.x=150; p.y=320; p1.x=(p.x-20)-5;p1.y=(p.y-15)-5; p2.x=(p.x-20)+5;p2.y=(p.y-15)+5;
	draw_fill_rectangle(p1,p2,vert);
	aff_pol("Second clic sur le mur permet de l'effacer",20,p,couleur_alea());
	
	printf("entrez le nombre de lignes:\n");
	scanf("%d",&S.H);
	printf("entrez le nombre de colonnes:\n");
	scanf("%d",&S.L);
	init_graphics_pour_edit(S);
	afficher_grille(S);	
	S.Tm=allocation_tab_trois_dim(S.Tm,S.L,S.H);
	return S;
}

void acceuil_saufgarde(SLIDER S)
{
	init_graphics(800,600);
	fill_screen(blanc);
	POINT p,p1,p2;
	
	p.x=50; p.y=550; p1.x=(p.x-20)-10;p1.y=(p.y-20)-10; p2.x=(p.x-20)+10;p2.y=(p.y-20)+10;
	draw_fill_rectangle(p1,p2,vert);
	aff_pol("Voulez vous saufgarder votre niveau ?",30,p,couleur_alea());
	
	p.x=200; p.y=320; p1.x=(p.x-20)-5;p1.y=(p.y-15)-5; p2.x=(p.x-20)+5;p2.y=(p.y-15)+5;
	draw_fill_rectangle(p1,p2,couleur_alea());
	aff_pol("OUI",20,p,vert);
	
	p.x=350; p.y=320; p1.x=(p.x-20)-5;p1.y=(p.y-15)-5; p2.x=(p.x-20)+5;p2.y=(p.y-15)+5;
	draw_fill_rectangle(p1,p2,couleur_alea());
	aff_pol("NON",20,p,couleur_alea());
	int i=1;
	while(i)
	{
	p=wait_clic();
	if(300<p.y && p.y<315)
	{
		if(175<p.x && p.x<300)
		{
		saufgarder_mon_jeu(S);
		break;
	    }
		if(325<p.x && p.x<395)
		break;
	}
}
		
}

char fenetre_acceuil()
{
	init_graphics(800,600);
	fill_screen(blanc);
	POINT p,p1,p2;
	
	p.x=200; p.y=600; p1.x=(p.x-20)-10;p1.y=(p.y-40)-10; p2.x=(p.x-20)+10;p2.y=(p.y-40)+10;
	draw_fill_rectangle(p1,p2,rouge);
	aff_pol("Jouer",50,p,couleur_alea());
	
	
	p.x=200; p.y=500; p1.x=(p.x-20)-10;p1.y=(p.y-40)-10; p2.x=(p.x-20)+10;p2.y=(p.y-40)+10;
	draw_fill_rectangle(p1,p2,rouge);
	aff_pol("Editer",50,p,couleur_alea());
	
	p.x=725; p.y=600; p1.x=(p.x-20)-5;p1.y=(p.y-15)-5; p2.x=(p.x-20)+5;p2.y=(p.y-15)+5;
	draw_fill_rectangle(p1,p2,vert);
	aff_pol("Quitter",20,p,couleur_alea());
	
	int i=1;
	while(i)
	{
	p=wait_clic();
	if(200<p.x && p.x<330 && 550<p.y && p.y<580)
	return 'j';
	if(200<p.x && p.x<340 && 450<p.y && p.y<480)
	{
	   p.x=250; p.y=400; p1.x=(p.x-20)-10;p1.y=(p.y-20)-10; p2.x=(p.x-20)+10;p2.y=(p.y-20)+10;
	draw_fill_rectangle(p1,p2,vert);
	aff_pol("Nouveau niveau",30,p,couleur_alea());
	
	p.x=250; p.y=300; p1.x=(p.x-20)-10;p1.y=(p.y-20)-10; p2.x=(p.x-20)+10;p2.y=(p.y-20)+10;
	draw_fill_rectangle(p1,p2,vert);
	
	aff_pol("continuer sur niveau existant ",30,p,couleur_alea());
  }
	if(250<p.x && p.x<490 && 370<p.y && p.y<390)
		return 'n';
	if(250<p.x && p.x<690 && 270<p.y && p.y<285)
        return 'o';
    if(725<p.x && p.x<780 && 580<p.y && p.y<595)
      exit(0);
	}
     wait_escape();
	exit(0);
}


