// https://cses.fi/problemset/task/1082

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli MOD = 1e9 + 7;
lli modI2;

lli powermod(lli x, lli y)
{
    if (x == 0 && y == 0)
        return 1;
    lli res = 1;
    x = x % MOD;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

lli modinv(lli x)
{
    return powermod(x, MOD - 2);
}

lli sum(lli n)
{
    n = n % MOD;
    return ((n * (n + 1)) % MOD * modI2) % MOD;
}

void solve()
{
    modI2 = modinv(2);
    lli n;
    cin >> n;

    lli ans = 0;

    lli k = 1;
    lli start = n;

    // O(sqrt(n)) iterations
    while (start)
    {
        k = n / start;
        ans = (ans + (k % MOD * (sum(start) - sum(n / (k + 1)) + MOD) % MOD) % MOD) % MOD;
        start = n / (k + 1);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli q = 1;
    // cin >> q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}