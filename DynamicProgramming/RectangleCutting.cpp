// https://cses.fi/problemset/task/1744

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int dp[501][501];
    for (int i = 0; i < 501; i++)
    {
        for (int j = 0; j < 501; j++)
        {
            dp[i][j] = 10000;
        }
    }
    for (int i = 0; i < 501; i++)
    {
        dp[i][i] = 0;
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for (int i = 1; i < 501; i++)
    {
        for (int j = 1; j < 501; j++)
        {
            for (int k = 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j - k] + dp[i][k] + 1, dp[i][j]);
            }
            for (int k = 1; k < i; k++)
            {
                dp[i][j] = min(dp[i - k][j] + dp[k][j] + 1, dp[i][j]);
            }
        }
    }
    int a, b;
    cin >> a >> b;
    cout << dp[a][b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}