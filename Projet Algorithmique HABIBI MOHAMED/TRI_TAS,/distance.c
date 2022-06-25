#include "distance.h"

/**************************************************  LEVENSHTEIN  ***************************************************************/

int LevenshteinDistance(char *string1, char *string2)
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

		    M[i][j]=MIN3(M[i-1][j]+1    //supprimer caractere
			         ,M[i][j-1]+1      //insertion
					 ,M[i-1][j-1]+cost); //subtitution
		}
	}
	return (M[strlen(string1)][strlen(string2)]);
}

double dis(char *string1, char *string2)
{
	double i = (double)LevenshteinDistance(string1, string2);
	double Max = (double)max(strlen(string1),strlen(string2));
	double result;
	result = i/Max;
	return 1-result;
}


void permuter(char **tableau, int index1, int index2)
{
  char *aux = (char *)malloc(sizeof(char )*30);

  aux = strdup(tableau[index1]);
  free(tableau[index1]);
  tableau[index1] = (char *)malloc(sizeof(char)*strlen(tableau[index2]));
  tableau[index1] = strdup(tableau[index2]);
  free(tableau[index2]);
  tableau[index2] = (char *)malloc(sizeof(char)*strlen(aux));
  tableau[index2] = strdup(aux);
  free(aux);
}
