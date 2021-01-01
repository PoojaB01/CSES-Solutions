// https://cses.fi/problemset/task/1683

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void dfs(int x, vector<int> edge[], vector<int> &v, vector<int> &order, int k)
{
    v[x] = k;
    for (auto i : edge[x])
    {
        if (v[i] == 0)
        {
            dfs(i, edge, v, order, k);
        }
    }
    order.push_back(x);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> edge[n], edge_rev[n];
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        edge[x - 1].push_back(y - 1);
        edge_rev[y - 1].push_back(x - 1);
    }
    vector<int> v(n, 0);
    vector<int> order;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            dfs(i, edge, v, order, 1);
        }
    }
    v.assign(n, 0);
    int k = 0;
    vector<int> component;
    for (auto i = n - 1; i >= 0; i--)
    {
        if (v[order[i]] == 0)
        {
            k++;
            dfs(order[i], edge_rev, v, component, k);
        }
    }
    cout << k << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ' ';
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