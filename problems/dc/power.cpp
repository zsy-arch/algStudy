#include <iostream>

int power(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        int a = power(m, n / 2);
        return a * a;
    }
    else
    {
        int a = power(m, n / 2);
        return a * a * m;
    }
}

int main(int argc, const char *argv[])
{
    int m, n;
    scanf("%d %d", &m, &n);
    int res = power(m, n);
    printf("%d\n", res);
    return 0;
}