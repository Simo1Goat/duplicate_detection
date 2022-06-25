#include "Set.h"
#include "distance.h"

char **MappingToSet(char *filename)
{
    int i=0, lines = Count_Lines(filename)+1;
    char **mot;
    mot=(char **)malloc(lines*sizeof(*mot));
    char *aux;
    aux=(char *)malloc(40*sizeof(char));

    FILE *fp;
    fp=fopen(filename,"r");

    if(fp != NULL)
    {
        while(!feof(fp))
        {
            mot[i]=strdup(fgets(aux,40,fp));
            i++;
        }
    }
    else
    {
        printf("Impossible d\'ouvrir ce fichier\n");
        EXIT_FAILURE;
    }
    fclose(fp);
    return(mot);
}
