// https://cses.fi/problemset/task/1079

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli MOD = 1e9 + 7;

lli powermod(lli x, lli y)
{
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

vector<lli> f(1000003, 0);

void preprocess()
{
    f[0] = 1;
    for (int i = 1; i < 1000003; i++)
    {
        f[i] = (i * f[i - 1]) % MOD;
    }
}

void solve()
{
    preprocess();
    lli t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << (((f[a] * modinv(f[b])) % MOD) * modinv(f[a - b])) % MOD << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli q = 1;
    // cin>>q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}