#include "tas.h"

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

int LevenshteinDistance(char *string1 , char *string2 );
double dis (char *string1 , char *string2 );
void permuter(char**table , int index1  , int index2 );
int Count_Lines(char *filename);
