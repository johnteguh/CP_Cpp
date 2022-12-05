#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAXK 1000

ll sieve[MAXK + 5], fact[MAXK + 5];

ll modex(ll b, ll e)
{
    if (b == 0)
        return 0;
    if (b == 1)
        return 1;
    if (b == -1)
        return (e & 1 ? -1 : 1);

    ll res = 1;
    while (e)
    {
        if (e & 1)
            res = (res * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return res;
}

void init()
{
    sieve[0] = sieve[1] = 1;

    for (int i = 2; i * i <= MAXK; ++i)
    {
        if (!sieve[i])
        {
            for (int j = i * i; j <= MAXK; j += i)
            {
                if (!sieve[j])
                    sieve[j] = i;
            }
        }
    }
    fact[0] = fact[1] = 1;
    for (ll i = 2; i <= MAXK; ++i)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

ll totient(ll x)
{
    ll res, temp, last = 1;
    res = temp = x;

    while (sieve[temp] > 0 && temp > 1)
    {
        if (sieve[temp] != last)
        {
            res /= sieve[temp];
            res *= (sieve[temp] - 1);
        }
        last = sieve[temp];
        temp /= sieve[temp];
    }
    if (temp > 1 && temp != last)
    {
        res /= temp;
        res *= (temp - 1);
    }
    return res;
}

ll kombin(ll n, ll k)
{
    ll res = 1;
    ll mn = min(n - k, k), mx = max(n - k, k);

    for (ll i = mx + 1; i <= n; ++i)
    {
        res = (res * i) % MOD;
    }
    res = (res * modex(fact[mn], MOD - 2)) % MOD;
    return res;
}

ll calc(ll n, ll k, ll s)
{
    ll res1 = ((k - k / s) & 1 ? -1 : 1), res2 = totient(s), res3 = kombin(n / s, k / s);
    ll res = (res1 * res2 * res3) % MOD;
    return res;
}

void solve(ll n, ll k)
{
    ll ans = 0, fpb = __gcd(n, k);

    for (ll s = 1; s * s <= fpb; ++s)
    {
        if (fpb % s == 0)
        {
            ans = (ans + calc(n, k, s)) % MOD;

            ll ss = fpb / s;
            if (ss != s)
            {
                ans = (ans + calc(n, k, ss)) % MOD;
            }
        }
    }
    ans = (ans * modex(n, MOD - 2)) % MOD;
    while (ans < 0)
        ans += MOD;
    printf("%lld\n", ans);
}

int main()
{
    init();
    int t;
    scanf("%d", &t);

    while (t--)
    {
        ll n, k;
        scanf("%lld %lld", &n, &k);
        solve(n, k);
    }
    return 0;
}