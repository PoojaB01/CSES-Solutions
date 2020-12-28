// https://cses.fi/problemset/task/1712

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli powermod(lli x, lli y, lli MOD)
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    lli MOD = 1e9 + 7;
    while (q--)
    {
        lli a, b, c;
        cin >> a >> b >> c;
        cout << powermod(a, powermod(b, c, MOD-1), MOD) << endl;
    }
    return 0;
}