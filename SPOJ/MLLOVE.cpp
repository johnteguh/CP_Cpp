#include <cstdio>
#include <cmath>
#include <algorithm>
#define ull unsigned long long
#define gc getchar_unlocked

ull read()
{
    ull value = 0;
    bool ne = 0;
    char c = gc();
    while (c == ' ' or c == '\n')
        c = gc();
    if (c == '-')
    {
        ne = 1;
        c = gc();
    }
    while (c >= '0' and c <= '9')
    {
        value = (value << 3) + (value << 1) + c - '0';
        c = gc();
    }
    if (ne)
        value *= -1;
    return value;
}

ull count(ull n, ull k)
{
    ull sum;

    // sum = (n/2)(2a + (n-1)b) <- arithmetics sum
    // n = n input / gcd
    // gcd = b

    ull gcd = std::__gcd(n, k);
    if (gcd == 1)
        sum = (n * (n - 1)) / 2; // a = 0

    if (gcd > 1)
        sum = ((n / gcd) / 2) * (2 + ((n / gcd) - 1) * gcd); // a = 1

    return sum;
}

void solve()
{
    ull n, k;
    n = read();
    k = read();

    printf("%llu\n", count(n, k));
}

int main()
{
    solve();
    return 0;
}