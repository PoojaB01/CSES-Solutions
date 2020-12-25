// https://cses.fi/problemset/task/1145

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> dp(n, MOD);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int index = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[index] = min(dp[index], a[i]);
        ans = max(ans, index + 1);
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