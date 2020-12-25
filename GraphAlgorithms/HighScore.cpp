// https://cses.fi/problemset/task/1673

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli MIN = -1e14;

void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    lli z;
    vector<pair<int, lli>> edge[n];
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        edge[x - 1].push_back({y - 1, z});
    }

    vector<bool> reachable_end(n, false), reachable_start(n, false);
    reachable_end[n - 1] = true;
    reachable_start[0] = true;

    vector<lli> dp(n, MIN);
    dp[0] = 0;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (auto e : edge[i])
            {
                dp[e.first] = max(dp[e.first], dp[i] + e.second);
                reachable_end[i] = reachable_end[e.first] | reachable_end[i];
                reachable_start[e.first] = reachable_start[i] | reachable_start[e.first]; 
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (auto e : edge[i])
        {
            if (dp[e.first] < dp[i] + e.second && reachable_end[e.first] && reachable_start[e.first])
            {
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << dp[n - 1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}