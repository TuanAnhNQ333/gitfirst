#include<stdio.h>
#include<string.h>
#define MAX_STRING 50
void sort(int *s, int n)
{
    for(int i = 0; i < n; i ++)
    {
        for(int j = i + 1; j < n; j ++)
        {
            if(s[i] > s[j])
            {
                int temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
int main()
{
    int s[MAX_STRING];
    int n;
    int i;
    scanf("%d\n", &n);
    for(int i = 0; i < n; i ++)
    {
        scanf("%d", &s[i]);
    }
    sort(s, n);
    for(int i = 0; i < n; i ++)
    {
        printf("%d ", s[i]);
    }
    return 0;
}