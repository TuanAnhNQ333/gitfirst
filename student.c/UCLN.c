#include<stdio.h>
int check (int a, int b)
{
    int UCLN;
    int r; // r la so du cua phep chia
    if (a < b)
    {
        int temp = b;
        b = a;
        a = temp;
    }
    int x = a /b ; // x la thuong cua phep chia
    r = a - (a / b)* b;
    if (r == 0)
    {
        return b;
    }
    else 
    {
        return check(b, r); // goi ham de quy voi b va r
    }
    return UCLN;
}
int main()
{
    int a, b;

    scanf("%d %d", &a, &b);
    int UCLN = check(a, b);    
    printf("%d\n", UCLN);
    return 0;
}