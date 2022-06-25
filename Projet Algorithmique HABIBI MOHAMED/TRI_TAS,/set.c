#include "Tas.h"
#include "distance.h"

int Count_Lines(char *filename)
{
    int lines=0;
    FILE *fp = fopen(filename,"r");
    char c  = fgetc(fp);
    while(!feof(fp))
    {
         if(c == '\n')
            lines++;
       c = fgetc(fp);
    }
    return lines;
}


void ajout(char** t,char* s)
{
	int i = 0;
	while(t[i])       // Compter les cases de tableau . On peut utiliser la fonction Compter_Ligne mais on a respecté la fonction que vous nous posez dans le projet.
		i++;
	t[i] = (char*)malloc(sizeof(char)*strlen(s));
	t[i] = strdup(s);
	t[i+1] = (char*)malloc(sizeof(char));
	t[i+1] = NULL;
	while(i > 0 && strcmp(t[i],t[(i-1)/2]) < 0)
	{
		permuter(t , i , (i-1)/2);
		i = (i-1)/2;
	}
}
// ajout(char** t,char* s) comme dans le cours.
char* extraire_min(char** t)
{
	if(t[0] == NULL)
		return NULL;
	int i = 0;
	while (t[i])  // Compter les cases de tableau . On peut utiliser la fonction Compter_Ligne mais on a respecté la fonction que vous nous posez dans le projet.
		i++;
	char* min = (char*)malloc(strlen(t[0])*sizeof(char));
	min = strdup(t[0]);
	free(t[0]);
	t[0] = (char*)malloc(strlen(t[i-1])*sizeof(char));
	t[0] = strdup(t[i-1]);
	int k = 0;
	while( k < (i-1)/2 && (strcmp(t[k],t[2*k+1]) > 0 || strcmp(t[k],t[2*k+2]) > 0))
	{
		if (strcmp(t[2*k+1],t[2*k+2]) < 0)
		{
			permuter(t , k , 2*k+1);
			k = 2*k+1;
		}
		else
		{
			permuter(t , k , 2*k + 2);
			k = 2*k + 2;
		}
	}
	t[i-1] = NULL;
	return min;
}
// extraire_min(char** t) comme dans le cours.
char** LireToTas(char* file_name)
{
	char** Tas = (char**)malloc(sizeof(char*));
	Tas[0] = (char*)malloc(sizeof(char));
	Tas[0] = NULL;
	FILE* F;
	F = fopen(file_name,"r");
	int i = 2;
	while(!feof(F))
	{
		Tas = (char**)realloc(Tas , i*sizeof(char*));
		i++;
		char *chaine = (char*)malloc(25*sizeof(char)); // on a utilisé chaine pour stocker les lignes de fichier ( comme temp).
		fscanf(F,"%s\n",chaine);
		ajout(Tas,chaine);
	}
	fclose(F);
	return Tas;
}

char** MappingToTable(char* file_name)
{
	char** Tas = LireToTas(file_name);
	char** Table_Trier = (char**)malloc(sizeof(char*));
	int j = 0;
	while(Tas[0])
	{
		Table_Trier=(char**)realloc(Table_Trier,(j+2)*sizeof(char*));
		Table_Trier[j] = strdup(extraire_min(Tas));
		j++;
	}
	Table_Trier[j] = NULL;
	return Table_Trier;
}
