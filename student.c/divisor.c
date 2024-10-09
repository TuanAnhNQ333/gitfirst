#include<stdio.h>
#define MAX_SIZE 200
int check(int n,int size, int q[])
{
    int count = 0; // luu bien dem
    // luu bien mang q boi ca 2 gia tri uoc duong va am cua n
    for(int i = 1; i <= n; i ++)
    {
        if(n % i == 0)
        {

            q[count++] = i;
            q[count++] = -i; 
        }
    }
    return count;
}
void sort(int size, int q[])
{
    for(int i = 0; i < size - 1; i ++)
    {
        for(int j = i + 1; j < size; j ++)
        {
            if (q[i] > q[j])
            {
                int temp = q[i];
                q[i] = q[j];
                q[j] = temp;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int q[MAX_SIZE];
    int size = check(n, MAX_SIZE, q);
    
    sort(size, q);
    for(int i = 0; i < size; i ++)
    {
        printf("%d ", q[i]);
    }

    return 0;
}