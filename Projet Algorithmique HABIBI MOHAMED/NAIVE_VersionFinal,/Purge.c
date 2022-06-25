#include "Set.h"
#include "distance.h"

void Purge(char *filename)
{
    int number_of_words = Count_Lines(filename)+1;
    char **table = (char **)malloc(number_of_words*sizeof(char *));
    char *File_To_Write_In = (char *)malloc(30*sizeof(char));
    table = MappingToSet(filename);

    puts("le nom du nouveau fichier");
    gets(File_To_Write_In);
    FILE *newfile = fopen(File_To_Write_In,"w+");
    int i,j;

    for(i=0;i<number_of_words;i++)
    {
        for(j=i+1;j<number_of_words;j++)
        {
            if(distanceFinal(table[i],table[j]) >= 0.8)
            {
                strcpy(table[j],"\0");
            }
        }
    }

    //upload les donnees dans le nouveau fichier
    for(i=0;i<number_of_words;i++)
    {
        fprintf(newfile,"%s",table[i]);
    }
}

