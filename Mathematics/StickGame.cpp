// https://cses.fi/problemset/task/1729

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, m;
    cin >> n >> m;
    int a[m];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    vector<bool> dp(n + 1, false);
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i - a[j] >= 0)
            {
                dp[i] = dp[i] | !dp[i - a[j]];
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        cout << (dp[i] ? 'W' : 'L');
    }
    cout << endl;
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