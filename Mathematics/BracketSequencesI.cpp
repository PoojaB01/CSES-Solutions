// https://cses.fi/problemset/task/2064

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
    lli n;
    cin >> n;
    if (n % 2)
    {
        cout << 0 << endl;
        return;
    }
    n /= 2;
    lli ans = 1;
    // Catalan Number 2n C n / (n+1)
    for (int i = n + 2; i <= 2 * n; i++)
    {
        ans = (ans * i) % MOD;
    }
    for (int i = 1; i <= n; i++)
    {
        ans = (ans * modinv(i)) % MOD;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q = 1;
    // cin >> q;
    while (q--)
        solve();
    return 0;
}