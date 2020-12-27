// https://cses.fi/problemset/task/1112

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

void computeLPS(string &s, int n, vector<int> &lps)
{
    lps[0] = 0;
    int len = 0;
    for (int i = 1; i < n; i++)
    {
        len = lps[i - 1];
        while(1)
        {
            if (s[i] == s[len])
            {
                len++;
                break;
            }
            if (len)
                len = lps[len - 1];
            else
                break;
        }
        lps[i] = len;
    }
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;
    int m = s.length();
    vector<int> lps(m, 0);
    computeLPS(s, m, lps);

    vector<vector<lli>> dp(n, vector<lli>(m + 1, 0));
    dp[0][1] = 1;
    dp[0][0] = 25;
    int len;

    for (int i = 1; i < n; i++)
    {
        for (char c = 'A'; c <= 'Z'; c++)
        {
            for (int j = 0; j < m; j++)
            {
                len = j;
                while (1)
                {
                    if (c == s[len])
                    {
                        len++;
                        break;
                    }
                    if (len)
                        len = lps[len - 1];
                    else
                        break;
                }
                if (len < m)
                    dp[i][len] = (dp[i][len] + dp[i - 1][j]) % MOD;
            }
        }
    }

    lli total = powermod(26, n);
    lli ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans = (ans + dp[n - 1][i]) % MOD;
    }
    cout << (total - ans + MOD) % MOD << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}