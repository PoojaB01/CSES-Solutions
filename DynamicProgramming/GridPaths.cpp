// https://cses.fi/problemset/task/1638

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int dp[n][n];
    if (s[0][0] == '*')
        dp[0][0] = 0;
    else
        dp[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i][0] == '.')
            dp[i][0] = dp[i - 1][0];
        else
            dp[i][0] = 0;
        if (s[0][i] == '.')
            dp[0][i] = dp[0][i - 1];
        else
            dp[0][i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            if (s[i][j] == '*')
            {
                dp[i][j] = 0;
            }
        }
    }
    cout << dp[n - 1][n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}