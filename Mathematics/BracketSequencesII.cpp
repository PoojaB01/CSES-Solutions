// https://cses.fi/problemset/task/2187/

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

lli ncr(lli n, lli r)
{
    if (r > n)
        return 0;
    lli ans = 1;
    for (lli i = r + 1; i <= n; i++)
    {
        ans = (ans * i) % MOD;
        ans = (ans * modinv(i - r)) % MOD;
    }
    return ans;
}

void solve()
{
    lli n;
    cin >> n;
    string s;
    cin >> s;
    int c = 0;
    for (int i = 0; i < s.length(); i++)
    {
        c += s[i] == '(' ? 1 : -1;
        if (c < 0)
        {
            cout << 0 << endl;
            return;
        }
    }
    if (n % 2 || c > n / 2)
    {
        cout << 0 << endl;
        return;
    }

    n -= s.length() - c;
    n /= 2;
    lli ob = n - c, cb = n;

    cout << (ncr(ob + cb, cb) - ncr(ob + cb, cb + 1) + MOD) % MOD << endl;
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