// https://cses.fi/problemset/task/1675

#include <bits/stdc++.h>

using namespace std;

#define lli long long

int findset(int x, vector<int> &p)
{
    if (x != p[x])
    {
        p[x] = findset(p[x], p);
    }
    return p[x];
}

void unionset(int a, int b, vector<int> &p, vector<int> &r)
{
    int x = findset(a, p);
    int y = findset(b, p);
    if (x != y)
    {
        if (r[x] < r[y])
            swap(x, y);
        p[y] = x;
        if (r[x] == r[y])
        {
            r[x]++;
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edge;
    int w, x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        edge.push_back({w, {x - 1, y - 1}});
    }

    sort(edge.begin(), edge.end());

    vector<int> p(n, 0), r(n, 0);
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }

    lli ans = 0;
    for (auto e : edge)
    {
        x = e.second.first;
        y = e.second.second;
        int f = findset(x, p), g = findset(y, p);
        if (f != g)
        {
            ans += e.first;
            unionset(f, g, p, r);
        }
    }
    x = findset(0, p);
    for (int i = 0; i < n; i++)
    {
        if (findset(i, p) != x)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
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