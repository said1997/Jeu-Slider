#define GAUCHE 9
#define DROITE 3
#define HAUT 0
#define BAS 6
#define G_TAB 0
#define D_TAB 1
#define H_TAB 2
#define B_TAB 3
#define TAILLE_CASE 50
#define TAILLE_SLIDER 21
#define FLECH_DROITE 275
#define FLECH_GAUCHE 276
#define FLECH_HAUT 273
#define FLECH_BAS 274
#define U 117
#define R 114
#define Q 113

struct slider {
	
	int L,H,x_slider,y_slider,x_sortie,y_sortie;
	int ***Tm;
	int N;
};

typedef struct slider SLIDER;


typedef struct Element{
	
	int x_slid;
	int y_slid;
	struct Element * suivant;
}elm;
