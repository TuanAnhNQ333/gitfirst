#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STRING 50
void replace (char *s1, char read, char rep)
{
    for(int i = 0; i < strlen(s1); i++)
    {
        if (s1[i] == read)
        {
            s1[i] = rep;
        }
    }
}
int main(){
    char s1[MAX_STRING];
    char read;
    char rep;
    scanf("%s %c %c",s1, &read, &rep);
    replace(s1, read, rep);
    printf("%s", s1);
    return 0;
}


