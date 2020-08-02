#include <stdio.h>
#include <stdlib.h>
#include <uvsqgraphics.h>
#include "mes_types.h"
#include "afficher.h"
#include "run_slider.h"
#include "mes_phenetres_graphiques.h"




int main (int argc, char**argv) {
	
    SLIDER S;
    char w;
    int i=1;
    while(i)
    {
    w=fenetre_acceuil();
   
   jouer(argc,argv,S,w);

}
finir_affichage();
	
	printf("Fin slider\n");
	
	exit(0);
}
