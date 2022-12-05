#include <stdio.h>
#include <algorithm>
int dp[185], sum[190], n, a[185], k;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = n - 1; i >= 0; i--)
        sum[i] = sum[i + 1] + a[i];
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
    {
        for (int j = n - i; j >= 0; j--)
            dp[j] = std::max(sum[j] - dp[j + i], dp[j]);
    }
    printf("%d\n", dp[0]);
    return 0;
}