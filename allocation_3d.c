#include <stdio.h>
#include <stdlib.h>
int ***allocatin_tab_trois_dim(int ***ptr,int l,int c)
{
	
int mur=4;
int i,j;

ptr = malloc(l * sizeof(int *));

for(i=0 ; i < l ; i++)
{
	
     ptr[i] = malloc(c * sizeof(int *));

}
for(i=0 ; i < l; i++){
     for(j=0 ; j < c ; j++)
     {
		 
           ptr[i][j] = malloc(mur* sizeof(1));
           
     }
}

for(i=0 ; i < l; i++)
{
     for(j=0 ; j < c; j++)
     {
		 ptr[i][j][0]=999 ;
		 ptr[i][j][1]=999;
		 ptr[i][j][2]=999;
		 ptr[i][j][3]=999;
		 printf("ptr[%d][%d][0]=%d\n",i,j,ptr[i][j][0]);
		 printf("ptr[%d][%d][1]=%d\n",i,j,ptr[i][j][1]);
		 printf("ptr[%d][%d][2]=%d\n",i,j,ptr[i][j][2]);
		 printf("ptr[%d][%d][3]=%d\n\n",i,j,ptr[i][j][3]);
	 }
 }
 return(ptr);
}


void my_free(int ***ptr,int tailleDejaAllouee1,int tailleDejaAllouee2){

    int i,j;


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
int main()
{
	int ***ptr;
int l,c;
printf("Entrez le nombre de lignes : ");
    scanf("%d", &l);
    printf("Entrez le nombre de colones : ");
    scanf("%d", &c);
ptr=allocatin_tab_trois_dim(ptr,l,c);



my_free(ptr,l,c);

	return 0;
}
