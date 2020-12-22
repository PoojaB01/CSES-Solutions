// https://cses.fi/problemset/task/1666

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void dfs(int x, vector<int> &v, vector<int> edge[])
{
    v[x] = 1;
    for (auto i : edge[x])
    {
        if (v[i] == 0)
        {
            dfs(i, v, edge);
        }
    }
}

void solve()
{
    int n, m, x, y;
    cin >> n >> m;
    vector<int> edge[n + 1];
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    vector<int> rep;
    vector<int> v(n + 1, 0);

    for (int i = 1; i < n + 1; i++)
    {
        if (v[i] == 0)
        {
            rep.push_back(i);
            dfs(i, v, edge);
        }
    }
    cout << rep.size() - 1 << endl;
    for (int i = 0; i < rep.size() - 1; i++)
    {
        cout << rep[i] << ' ' << rep[i + 1] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}