#include "Set.h"
#include "distance.h"
#include <time.h>

int main()
{
    clock_t start , finish ;
    double la_dure ;

    char *File_To_Read = (char *)malloc(30*sizeof(char));
    puts("le nom de fichier existant");
    gets(File_To_Read);
    int lines =Count_Lines(File_To_Read);

    start = clock() ;
    Purge(File_To_Read);
    finish = clock() ;

    printf("\n\t nous avons : %d mots \n\n",lines);
    printf(" \t************************ \n");
    la_dure = (double)(finish-start) / CLOCKS_PER_SEC ;
    printf("\n\n******************************************** ");
    printf(" \n\n ***  la duree est %f secondes *** \n\n" , la_dure);
    printf("******************************************** \n\n");

    return 0;
}
