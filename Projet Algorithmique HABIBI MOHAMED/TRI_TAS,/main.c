#include "tas.h"
#include "distance.h"
#include <time.h>
int main()
{
    int k=0;
    clock_t start , finish ;
    double la_dure ;
    char *File_To_Read  = (char *)malloc(sizeof(char )*30);
    char *File_To_write = (char *)malloc(sizeof(char )*30);

    puts("le nom du fichier existant ");
    gets(File_To_Read);
    int lines =Count_Lines(File_To_Read);
    char **filtredtable = (char**)malloc(lines*sizeof(char *));

    start = clock();
    filtredtable = purge(File_To_Read);
    finish = clock();

    puts("nom du fichier a ecrire");
    gets(File_To_write);

   FILE *f_out = fopen(File_To_write,"w+");

   printf("\n\t nous avons : %d mots \n\n",lines);
   printf(" \t************************ \n");
   la_dure = (double)(finish-start) / CLOCKS_PER_SEC ;
   printf("\n\n******************************************** ");
   printf(" \n\n ***  la duree est %f secondes *** \n\n" , la_dure);
   printf("******************************************** \n\n");

   while(filtredtable[k])
   {
       fprintf(f_out,"%s\n",filtredtable[k]);
       k++;
   }

    return 0;
}
