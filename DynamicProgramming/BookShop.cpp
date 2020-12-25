// https://cses.fi/problemset/task/1158

#include <bits/stdc++.h>

using namespace std;

#define lli long longg

void solve()
{
    int n, x;
    cin >> n >> x;
    int h[n], s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int dp[x + 1005] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= 0; j--)
        {
            dp[j + h[i]] = max(dp[j + h[i]], dp[j] + s[i]);
        }
    }
    cout << dp[x] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}