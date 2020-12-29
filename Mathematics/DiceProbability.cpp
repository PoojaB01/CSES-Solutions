// https://cses.fi/problemset/task/1725

#include <bits/stdc++.h>

using namespace std;

#define lli long long
#define ldb long double

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<ldb>> dp(b + 1, vector<ldb>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < b + 1; j++)
        {
            for (int k = 1; k <= 6 && j - k >= 0; k++)
            {
                dp[j][i] += dp[j - k][i - 1];
            }
            dp[j][i] /= 6;
        }
    }
    ldb ans = 0;
    for (int i = a; i < b + 1; i++)
        ans += dp[i][n];
    cout << fixed << setprecision(6) << ans << endl;
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