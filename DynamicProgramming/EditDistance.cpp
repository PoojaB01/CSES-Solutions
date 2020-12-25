// https://cses.fi/problemset/task/1639

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    string s, t;
    int n, m;
    cin >> s >> t;
    n = s.length();
    m = t.length();
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = i;
    for (int i = 0; i < m + 1; i++)
        dp[0][i] = i;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
            else
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    cout << dp[n][m] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}