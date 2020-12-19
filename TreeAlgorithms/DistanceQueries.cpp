// https://cses.fi/problemset/task/1135

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void dfs(int x, vector<int> v[], vector<int> &start, vector<int> &end, vector<int> &dist, vector<int> &parent, int &k, int d)
{
    start[x] = k;
    dist[x] = d;

    k++;

    for (int i = 0; i < v[x].size(); i++)
    {
        if (v[x][i] != parent[x])
        {
            parent[v[x][i]] = x;
            dfs(v[x][i], v, start, end, dist, parent, k, d + 1);
        }
    }

    end[x] = k;
}

bool is_ancestor(int x, int y, vector<int> &start, vector<int> &end)
{
    return start[x] <= start[y] && end[x] >= end[y];
}

void solve()
{
    int n, q;
    cin >> n >> q;
    int x, y;
    int p[24][n + 1];
    vector<int> v[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    v[0].push_back(1);

    vector<int> start(n + 1, 0), end(n + 1, 0);
    vector<int> dist(n + 1, 0), parent(n + 1, 0);
    y = 1;

    dfs(0, v, start, end, dist, parent, y, 0);

    for (int i = 0; i < n + 1; i++)
    {
        p[0][i] = parent[i];
    }

    for (int k = 1; k < 24; k++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            p[k][j] = p[k - 1][p[k - 1][j]];
        }
    }

    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        int ans = dist[x] + dist[y];
        for (int k = 23; k >= 0; k--)
        {
            if (!is_ancestor(p[k][x], y, start, end))
            {
                x = p[k][x];
            }
        }

        if (is_ancestor(x, y, start, end))
            ans -= 2 * dist[x];
        else
            ans -= 2 * dist[p[0][x]];

        cout << ans << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}