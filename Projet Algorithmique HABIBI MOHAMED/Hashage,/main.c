#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

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


typedef struct node{

    char *data;
    struct node *next;
}node;

typedef struct hash
{
    char *string;
    int key;
}hash;

int count_lines(char *filename){
    char c;
    int lines=0;
    FILE *fp=fopen(filename,"r");
    while(!feof(fp))
    {
        c=fgetc(fp);
        if(c=='\n')
        {
            lines++;
        }
    }
    lines+=1;
    return lines;
}

int mot_cle(char *string,char* filename)
{
    int i=0,sum=0,n = count_lines(filename);
    while(string[i]!='\0')
    {
        sum+=string[i];
        i++;
    }
    return sum%n;
}

void insert_node(node **head,char *string)
{
    node *nv_node = malloc(sizeof(node));
    //nv_node->data = malloc(sizeof(char)*strlen(string));
    nv_node->data=strdup(string);
    nv_node->next=NULL;

    if(*head==NULL)
    {
        *head=nv_node;
    }
    else
    {
        node *temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nv_node;
    }
}

void insert_into_table(node **hashtable ,char *string,char *filename)
{
    int index=mot_cle(string,filename);

    if(hashtable[index]==NULL)
    {
        hashtable[index]=malloc(sizeof(node));
        node *head=NULL;
        insert_node(&head,string);
        hashtable[index]=head;
    }
    else
    {
        node *head=hashtable[index];
        insert_node(&head,string);
        hashtable[index]=head;
    }
}

char **mappingtoset(char *filename)
{
    int i=0,lines=count_lines(filename);
    char **table=(char**)malloc(sizeof(*table)*lines);
    char *buffer=(char *)malloc(sizeof(char)*30);

    FILE *fp=fopen(filename,"r");
    if(fp!=NULL)
    {
        while(!feof(fp))
        {
            table[i]=strdup(fgets(buffer,30,fp));
            i++;
        }
    }
    else
    {
        printf("Impossible\n");
        EXIT_FAILURE;
    }
    fclose(fp);
    return table;
}
//for testing
node** insert_into_linked(char *file_name)
{
    int i,lines=count_lines(file_name);
    node **linked=calloc(lines,sizeof(node*));
    char **table=mappingtoset(file_name);

    for(i=0;i<lines;i++)
    {
        insert_into_table(linked,table[i],file_name);
    }

    return linked;
}

void displaytable(node** hashtable,char *filename)
{
    int i,n=count_lines(filename);
    for(i=0;i<n;i++)
    {
         node *temp=hashtable[i];
        printf("%d:",i);
        if(temp==NULL)
        {
            printf("NULL");
        }
        else
        {
            while(temp!=NULL)
           {
                printf("--->%s",temp->data);
                temp=temp->next;
           }
        }
        printf("\n");
    }
}

hash* mappingtohash(char *file_name)
{
    int i,j=0,lines=count_lines(file_name);
    node **linked_list=calloc(lines,sizeof(node *));
    hash *hashtable=malloc(sizeof(hash)*lines);

    linked_list=insert_into_linked(file_name);

    for(i=0;i<lines;i++)
    {
        if(linked_list[i]!=NULL)
        {
            hashtable[j].string=strdup(linked_list[i]->data);
            hashtable[j].key=i;
            j++;
            node *temp=linked_list[i]->next;
            while(temp!=NULL)
            {
                hashtable[j].string=strdup(temp->data);
                hashtable[j].key=i;
                j++;

                temp=temp->next;
            }
        }
    }

    return hashtable;
}

char** Purge(char *file_name)
{
    int i=0,j,t=1,key,lines=count_lines(file_name);
    char **Filtredtable=malloc(sizeof(char*));
    hash *hashtable=mappingtohash(file_name);

    for(i=0;i<lines;i++)
    {
        key=hashtable[i].key;
        for(j=i+1;j<lines;j++)
        {
            if(distanceFinal(hashtable[i].string,hashtable[j].string)>=0.8)
            {
                hashtable[j].key=-1;
            }
        }
    }

    for(i=0;i<lines;i++)
    {
        if(hashtable[i].key!=-1)
        {
            Filtredtable[t-1]=(char *)malloc(sizeof(char)*strlen(hashtable[i].string));
            strcpy(Filtredtable[t-1],hashtable[i].string);
            //Filtredtable[i]=strdup(hashtable[i].string);
            Filtredtable=realloc(Filtredtable,(t+1)*sizeof(char *));
            t++;
        }
    }

    Filtredtable[t-1]=NULL;
    free(hashtable);

    return Filtredtable;
}


int main()
{
    clock_t start , finish ;
    double la_dure ;
    char *File_To_Read = (char *)malloc(30*sizeof(char));
    puts("le nom de fichier existant");
    gets(File_To_Read);
    int i,lines=count_lines(File_To_Read);
    start = clock() ;
    char **tab=Purge(File_To_Read);
    finish = clock() ;
    FILE *file;
    printf("\n\t nous avons : %d mots \n\n",lines);
    printf(" \t************************ \n");
    la_dure = (double)(finish-start) / CLOCKS_PER_SEC ;
    printf("\n\n******************************************** ");
    printf(" \n\n ***  la duree est %f secondes *** \n\n" , la_dure);
    printf("******************************************** \n\n");
    printf(" Le tableau filtre est : \n\n");
    for(i=0;i<lines+1;i++)
    {
        printf("\t%d ** %s\n",i+1,tab[i]);
    }
    printf("*************************");

    return 0;
}
