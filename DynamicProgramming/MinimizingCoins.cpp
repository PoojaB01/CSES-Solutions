// https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n;
    cin >> n;
    int c;
    cin >> c;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> dp(c + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j + a[i] <= c; j++)
        {
            if (dp[j] != INT_MAX)
                dp[j + a[i]] = min(dp[j + a[i]], dp[j] + 1);
        }
    }
    if (dp[c] == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
        cout << dp[c] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli q = 1;
    // cin>>q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}