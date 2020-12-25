// https://cses.fi/problemset/task/1746

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli MOD = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lli dp[m + 2][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m + 2; j++)
        {
            dp[j][i] = 0;
        }
    }
    if (a[0] == 0)
    {
        for (int i = 1; i < m + 1; i++)
            dp[i][0] = 1;
    }
    else
    {
        dp[a[0]][0] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] == 0)
        {
            for (int j = 1; j < m + 1; j++)
            {
                dp[j][i] = dp[j - 1][i - 1] + dp[j][i - 1] + dp[j + 1][i - 1];
                dp[j][i] %= MOD;
            }
        }
        else
        {
            dp[a[i]][i] = dp[a[i] - 1][i - 1] + dp[a[i]][i - 1] + dp[a[i] + 1][i - 1];
            dp[a[i]][i] %= MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i < m + 1; i++)
    {
        ans += dp[i][n - 1];
        ans %= MOD;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}