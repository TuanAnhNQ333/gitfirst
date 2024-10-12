#include<stdio.h>
#include<stdlib.h>
int count(int *a, int n, int k)
{
    int count = 0;
    for(int i = 0; i <= n - k; i ++)
    {
        int sum = 0;
        for(int j = i; j < i + k ; j ++)
        {
            sum += a[j];
        }
            
        if (sum % 2 == 0)
            {
                count ++;
            }
    }
    return count;
}
int main()
{
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    int a[n];
    for(int i = 0; i < n; i ++)
    {
        scanf("%d", &a[i]);
    }
    int result = count (a, n, k);
    printf("%d\n", result);
    return 0;

}