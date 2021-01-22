// https://cses.fi/problemset/task/2182

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

void solve()
{
    int n;
    cin >> n;
    lli x, k;
    lli number = 1, sum = 1, product = 1, temp_number = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> k;
        product = (powermod(product, k + 1) * powermod(x, ((k * (k + 1)) / 2) % (MOD - 1) * temp_number)) % MOD;
        number = (number * (k + 1)) % MOD;
        temp_number = (temp_number * (k + 1)) % (MOD - 1);
        sum = ((sum * (powermod(x, k + 1) - 1 + MOD) % MOD) % MOD * modinv(x - 1)) % MOD;
    }
    cout << number << ' ' << sum << ' ' << product << endl;
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