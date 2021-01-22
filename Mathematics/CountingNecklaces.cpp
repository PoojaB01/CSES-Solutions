// https://cses.fi/problemset/task/2209

#include <bits/stdc++.h>

using namespace std;

#define lli long long
#define MAXN 1000010
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

vector<lli> phi(MAXN, 1);

void preprocess()
{
    for (int i = 1; i < MAXN; i++)
    {
        phi[i] = i;
    }
    for (int i = 2; i < MAXN; i++)
    {
        if (phi[i] == i)
        {
            phi[i] = i - 1;
            lli fac = ((i - 1) * modinv(i)) % MOD;
            for (int j = 2 * i; j < MAXN; j += i)
            {
                phi[j] = (phi[j] * fac) % MOD;
            }
        }
    }
}

void findpower(vector<lli> &power, lli m)
{
    for (int i = 1; i < power.size(); i++)
    {
        power[i] = (power[i - 1] * m) % MOD;
    }
}

void solve()
{
    lli n, m;
    cin >> n >> m;
    vector<lli> power(n + 1, 1);
    findpower(power, m);
    lli ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            ans = (ans + (phi[n / i] * power[i] + MOD * MOD) % MOD) % MOD;
        }
    }
    ans = (ans * modinv(n)) % MOD;
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    preprocess();
    lli q = 1;
    // cin >> q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}