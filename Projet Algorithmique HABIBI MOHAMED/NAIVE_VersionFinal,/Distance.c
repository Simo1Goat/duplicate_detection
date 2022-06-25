#include "Set.h"
#include "distance.h"

double Max(double a ,double b)
{
    if(a<=b) return b;
    else    return a;
}

int Min(int a ,int b,int c)
{
    if(a<b)
	{
		if(a<c)  return a;
		else     return c;
	}
	else
	{
		if (b<c) return b;
	    else     return c;
	}
}

int levenshtein(char *string1,char *string2)
{
	int line= strlen(string1)+1;
	int column= strlen(string2)+1;;
	int M[line][column];//matrice de l'evaluation
	int cost,i,j;

	for(i=0;i<line;i++)
	{
		M[i][0]=i;
	}
	for(j=0;j<column;j++)
	{
		M[0][j]=j;
	}
	for(i=1;i<line;i++)
	{
		for(j=1;j<column;j++)
		{
			if(toupper(string1[i]) == toupper(string2[j]))
			{
				cost=0;
			}
			else
			{
			    cost=1;
			}

		    M[i][j]=Min(M[i-1][j]+1    //supprimer caractere
			         ,M[i][j-1]+1      //insertion
					 ,M[i-1][j-1]+cost); //subtitution
		}
	}
	return (M[strlen(string1)][strlen(string2)]);
}


double distanceFinal(char *string1, char *string2)
{
    double i = (double)levenshtein(string1, string2);
	double max = Max(strlen(string1),strlen(string2));
	double result;
	result = i/max;
	return 1-result;
}


int Count_Lines(char *filename)
{
    char c;
    int lines=0;
    FILE *fp;
    fp=fopen(filename,"r");

    if(fp != NULL)
    {
        while(!feof(fp))
        {
            c=fgetc(fp);
            if(c == '\n')
                lines++;
        }
    }
    else
    {
        printf("Impossible d\'ouvrir le fichier ");
        EXIT_FAILURE;
    }
    return lines;
}
