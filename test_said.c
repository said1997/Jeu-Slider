#include <stdio.h>
#include <stdlib.h>


void free_tab_une_dim(int *tab)
{
	free(tab);
}
int * allocatin_tab_une_dim()
{
	int *tab;
	int taille,i;
	printf("entrez la taille de votre tab\n");
	scanf("%d",&taille);
	tab=malloc(taille*sizeof(int));
	for(i=0;i<taille;i++)
	{
		tab[i]=0;
		printf("tab[%d]=%d\n",i,tab[i]);
	}
	return(tab);
}
void free_tab_deux_dim(int ***tab,int l)
{
	int i,j;
	
	for (i = 0 ; i < l ; i++)
    {
        
           free(tab[i][0]);
           free(tab[i][1]);
           free(tab[i][2]);
     
}
for (i = 0 ; i < l ; i++)
{
	free(tab[i]);
}
free(tab);
        
       
}
int ***allocation_tab_deux_dim(int l,int c)
{
	   int i,j;
	   
    int ***tab;
    
    tab = malloc(l * sizeof(int*));
    for (i = 0 ; i < l ; i++)
    {
        tab[i] = malloc(c * sizeof(int));
    }
    
    for(i=0 ; i < l ; i++)
    {

       for(j=0;j<c;j++)
		{     
       tab[i][j] = malloc(4* sizeof(1));
       
	 }     

     }
    
    for(i=0;i<l;i++)
    {
		for(j=0;j<c;j++)
		{
			tab[i][j][0]=1;
			tab[i][j][1]=1;
			tab[i][j][2]=1;
			tab[i][j][3]=1;
			printf("tab[%d][%d][0]==%d\n",i,j,tab[i][j][0]);
			printf("tab[%d][%d][1]==%d\n",i,j,tab[i][j][1]);
			printf("tab[%d][%d][2]==%d\n",i,j,tab[i][j][2]);
			printf("tab[%d][%d][3]==%d\n\n",i,j,tab[i][j][3]);
		}

	}
	
	
	return(tab);
	
}

	
int main ()
{
 int l,c;
 //free_tab_une_dim(allocatin_tab_une_dim());
 
printf("Entrez le nombre de lignes : ");
    scanf("%d", &l);
    printf("Entrez le nombre de colones : ");
    scanf("%d", &c);
    
free_tab_deux_dim(allocation_tab_deux_dim(l,c),l);
	return 0;
}
