// https://cses.fi/problemset/task/1617

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

void solve()
{
    lli n;
    cin >> n;
    cout << powermod(2, n) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli q = 1;
    //cin>>q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}