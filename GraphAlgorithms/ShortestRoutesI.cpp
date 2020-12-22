// https://cses.fi/problemset/task/1671

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli MAX = 1e17;

void solve()
{
    int n, m, x, y, z;
    cin >> n >> m;
    vector<pair<int, lli>> edge[n + 1];
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        edge[x].push_back({y, z});
        // edge[y].push_back({x, z});
    }
    vector<lli> d(n + 1, MAX);
    set<pair<lli, int>> s;

    d[1] = 0;
    s.insert({0, 1});

    while (!s.empty())
    {
        pair<lli, int> p = *s.begin();
        s.erase(s.begin());
        for (auto i : edge[p.second])
        {
            if (d[i.first] == MAX)
            {
                s.insert({p.first + i.second, i.first});
                d[i.first] = p.first + i.second;
            }
            else
            {
                if (d[i.first] > p.first + i.second)
                {
                    s.erase({d[i.first], i.first});
                    s.insert({p.first + i.second, i.first});
                    d[i.first] = p.first + i.second;
                }
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        cout << d[i] << ' ';
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