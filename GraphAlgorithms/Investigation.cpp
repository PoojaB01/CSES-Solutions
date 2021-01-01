// https://cses.fi/problemset/task/1202

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli MAX = 1e17;
lli MOD = 1e9 + 7;

struct query
{
    lli dist;
    lli n_routes;
    int max_edge;
    int min_edge;
};

void solve()
{
    int n, m, x, y, z;
    cin >> n >> m;
    vector<pair<int, lli>> edge[n + 1];
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        edge[x].push_back({y, z});
    }

    vector<pair<lli, vector<int>>> d(n + 1, {MAX, {}});
    set<pair<lli, int>> s;

    d[1] = {0, {}};
    s.insert({0, 1});

    while (!s.empty())
    {
        pair<lli, int> p = *s.begin();
        s.erase(s.begin());
        for (auto i : edge[p.second])
        {
            if (d[i.first].first == MAX)
            {
                s.insert({p.first + i.second, i.first});
                d[i.first] = {p.first + i.second, {p.second}};
            }
            else
            {
                if (d[i.first].first > p.first + i.second)
                {
                    s.erase({d[i.first].first, i.first});
                    s.insert({p.first + i.second, i.first});
                    d[i.first] = {p.first + i.second, {p.second}};
                }
                else if (d[i.first].first == p.first + i.second)
                {
                    d[i.first].second.push_back(p.second);
                }
            }
        }
    }
    
    query dp[n + 1];
    for (int i = 2; i < n + 1; i++)
    {
        s.insert({d[i].first, i});
        dp[i].dist = d[i].first;
        dp[i].n_routes = 0;
        dp[i].max_edge = 0;
        dp[i].min_edge = m + 1;
    }
    dp[1].dist = 0;
    dp[1].n_routes = 1;
    dp[1].max_edge = 0;
    dp[1].min_edge = 0;
    for (auto itr = s.begin(); itr != s.end(); itr++)
    {
        x = itr->second;
        for (int i : d[x].second)
        {
            dp[x].n_routes = (dp[i].n_routes + dp[x].n_routes) % MOD;
            dp[x].max_edge = max(dp[x].max_edge, dp[i].max_edge + 1);
            dp[x].min_edge = min(dp[x].min_edge, dp[i].min_edge + 1);
        }
    }
    cout << dp[n].dist << ' ' << dp[n].n_routes << ' ' << dp[n].min_edge << ' ' << dp[n].max_edge;
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}