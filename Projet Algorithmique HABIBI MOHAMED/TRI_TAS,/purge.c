#include "tas.h"
#include "distance.h"

char** purge(char* file_name)
{

    int number_of_words = Count_Lines(file_name)+1;
    char **table = (char **)malloc(number_of_words*sizeof(char *));
    table = MappingToTable(file_name);

    int i,j;

    for(i=0;i<number_of_words;i++)
    {
        for(j=i+1;j<number_of_words;j++)
        {
            if(dis(table[i],table[j]) >= 0.8)
            {
                strcpy(table[j],"\0");
            }
        }
    }
    return table;
}
