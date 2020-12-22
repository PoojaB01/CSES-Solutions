// https://cses.fi/problemset/task/1672

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli MAX = 1e15;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    int x, y;
    lli z;
    vector<vector<lli>> dist(n, vector<lli>(n, MAX));

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        dist[x - 1][y - 1] = min(dist[x - 1][y - 1], z);
        dist[y - 1][x - 1] = min(dist[y - 1][x - 1], z);
    }

    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

    while (q--)
    {
        cin >> x >> y;
        cout << (dist[x - 1][y - 1] == MAX ? -1 : dist[x - 1][y - 1]) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}