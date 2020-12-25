// https://cses.fi/problemset/task/1097

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n;
    cin >> n;
    lli c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    lli dp[n][n][2];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
        }
        dp[i][i][0] = c[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j + i < n; j++)
        {
            dp[j][j + i][0] = max(c[j] + dp[j + 1][j + i][1], c[j + i] + dp[j][j + i - 1][1]);
            dp[j][j + i][1] = min(dp[j + 1][j + i][0], dp[j][j + i - 1][0]);
        }
    }
    cout << dp[0][n - 1][0] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}