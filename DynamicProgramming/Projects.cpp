// https://cses.fi/problemset/task/1140

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n;
    cin >> n;
    vector<pair<pair<int, int>, lli>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first.second >> v[i].first.first >> v[i].second;
    }
    sort(v.begin(), v.end());
    vector<pair<int, lli>> dp;
    dp.push_back({0, 0});
    for (int i = 0; i < n; i++)
    {
        int l = lower_bound(dp.begin(), dp.end(), make_pair(v[i].first.second, 0ll)) - dp.begin();
        l--;
        lli t = dp[l].second + v[i].second;
        if (dp.back().first == v[i].first.first)
        {
            t = max(t, dp.back().second);
            dp.pop_back();
        }
        t = max(t, dp.back().second);
        dp.push_back({v[i].first.first, t});
    }
    lli ans = 0;
    for (int i = 0; i < dp.size(); i++)
    {
        ans = max(dp[i].second, ans);
    }
    cout << ans << endl;
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