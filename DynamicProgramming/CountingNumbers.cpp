// https://cses.fi/problemset/task/2220

#include <bits/stdc++.h>

using namespace std;

#define lli unsigned long long

lli MOD = 9223372036854775807;

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

lli calc(lli x)
{
    if (x == -1)
    {
        return 0;
    }
    lli t = 1;
    int i = 0;
    lli ans = 1;
    while (t * 10 <= x)
    {
        i++;
        ans = ans + powermod(9, i);
        t *= 10;
    }
    string s = to_string(x);
    s = '0' + s;
    for (int i = 1; i < s.length(); i++)
    {
        int k = s[i] - '0';
        if (s[i - 1] < s[i])
            k--;
        ans = ans + max(0, k) * powermod(9, s.length() - i - 1);
        if (s[i - 1] == s[i])
        {
            ans--;
            break;
        }
    }
    return ans + 1;
}

void solve()
{
    lli a, b;
    cin >> a >> b;
    cout << calc(b) - calc(a - 1) << endl;
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