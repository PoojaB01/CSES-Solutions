// https://cses.fi/problemset/task/1688

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void dfs(int x, vector<int> v[], vector<int> &start, vector<int> &end, int &k)
{
    start[x] = k;
    k++;
    for (int i = 0; i < v[x].size(); i++)
    {
        dfs(v[x][i], v, start, end, k);
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
    p[0][0] = 0;
    p[0][1] = 0;
    vector<int> v[n + 1];

    for (int i = 0; i < n - 1; i++)
    {
        cin >> x;
        p[0][i + 2] = x;
        v[x].push_back(i + 2);
    }
    v[0].push_back(1);

    vector<int> start(n + 1, 0), end(n + 1, 0);
    y = 1;

    dfs(0, v, start, end, y);

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
        for (int k = 23; k >= 0; k--)
        {
            if (!is_ancestor(p[k][x], y, start, end))
            {
                x = p[k][x];
            }
        }
        if (is_ancestor(x, y, start, end))
            cout << x << endl;
        else
            cout << p[0][x] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}