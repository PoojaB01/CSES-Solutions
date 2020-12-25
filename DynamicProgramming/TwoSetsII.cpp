// https://cses.fi/problemset/task/1093

#include <bits/stdc++.h>

using namespace std;

#define lli long long

int MOD = 1e9 + 7;

#define MAXN 2000006

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
    int k = (n * (n + 1)) / 2;
    vector<vector<int>> dp(k + 503, vector<int>(n, 0));
    dp[1][0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < ((i + 1) * (i + 2)) / 2 + 1; j++)
        {
            dp[j][i] = (dp[j + i + 1][i - 1] + dp[abs(j - i - 1)][i - 1]) % MOD;
        }
    }
    cout << (dp[0][n - 1] * modinv(2)) % MOD << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}