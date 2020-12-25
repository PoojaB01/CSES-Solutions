// https://cses.fi/problemset/task/1196

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli MAX = 1e17;

void solve()
{
    int n, m, x, y, z, k;
    cin >> n >> m >> k;
    vector<pair<int, lli>> edge[n + 1];
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        edge[x].push_back({y, z});
        // edge[y].push_back({x, z});
    }
    multiset<lli> d[n + 1];
    multiset<pair<lli, int>> s;

    d[1].insert(0);
    s.insert({0, 1});

    while (!s.empty())
    {
        pair<lli, int> p = *s.begin();
        s.erase(s.begin());
        for (auto i : edge[p.second])
        {
            s.insert({p.first + i.second, i.first});
            d[i.first].insert(p.first + i.second);
            if (d[i.first].size() > k)
            {
                auto itr = d[i.first].end();
                itr--;
                d[i.first].erase(itr);
                s.erase(s.find({*itr, i.first}));
            }
        }
    }
    for (auto itr = d[n].begin(); itr != d[n].end(); itr++)
    {
        cout << *itr << ' ';
        k--;
        if (k == 0)
            break;
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}