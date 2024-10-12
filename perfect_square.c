#include<stdio.h>
#include<math.h>
int count(int *a, int n)
{
    int count = 0;
    for(int i = 0; i < n; i ++)
    {
        int sqrt_val = sqrt(a[i]);
        // su dung so sanh gia tri sqrt la so nguyen de tranh viec xay ra sai so
        if(sqrt_val * sqrt_val == a[i])
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
    int a[n];
    for(int i = 0; i < n; i ++)
    {
        scanf("%d", &a[i]);
    }
    int result = count(a, n);
    printf("%d\n", result);
    return 0;
}