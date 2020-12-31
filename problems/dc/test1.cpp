#include <cstdio>

const int minn = -19260817;

int arr[200200];
int n;

inline int max(int a, int b)
{
    return (a > b ? a : b);
}

int max_sum(int left, int right)
{
    if (left == right) return arr[left];
    int mid = (left + right) >> 1;
    int sum = 0, sum1 = minn, sum2 = minn;
    for (int i = mid; i >= left; i--)
    {
        sum += arr[i];
        sum1 = max(sum1, sum);
    }
    sum = 0;
    for (int i = mid + 1; i <= right; i++)
    {
        sum += arr[i];
        sum2 = max(sum2, sum);
    }
    return max(max( max_sum(left, mid), max_sum(mid + 1, right)), sum1 + sum2);
}


int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    printf("%d", max_sum(1, n));
}