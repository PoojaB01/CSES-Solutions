// https://cses.fi/problemset/task/1195

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli MAX = 1e17;

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

    vector<vector<lli>> v(n, vector<lli>(2, MAX));

    set<pair<lli, pair<int, int>>> s;
    v[0][0] = 0;
    s.insert({0, {0, 0}});

    while (s.size())
    {
        pair<lli, pair<int, int>> p = *s.begin();
        s.erase(p);
        for (auto i : edge[p.second.first])
        {
            if (p.second.second == 0)
            {
                if (v[i.first][1] > v[p.second.first][p.second.second] + i.second / 2)
                {
                    s.erase({v[i.first][1], {i.first, 1}});
                    v[i.first][1] = v[p.second.first][p.second.second] + i.second / 2;
                    s.insert({v[p.second.first][p.second.second] + i.second / 2, {i.first, 1}});
                }
            }
            if (v[i.first][p.second.second] > v[p.second.first][p.second.second] + i.second)
            {
                s.erase({v[i.first][p.second.second], {i.first, p.second.second}});
                v[i.first][p.second.second] = v[p.second.first][p.second.second] + i.second;
                s.insert({v[p.second.first][p.second.second] + i.second, {i.first, p.second.second}});
            }
        }
    }
    cout << min(v[n - 1][0], v[n - 1][1]) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}