// https://cses.fi/problemset/task/1684/

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
    vector<int> edge[2 * m], edge_rev[2 * m];
    int x, y;
    char cx, cy;
    for (int i = 0; i < n; i++)
    {
        cin >> cx >> x >> cy >> y;
        x--;
        y--;
        int ox = cx == '+' ? 0 : 1;
        int oy = cy == '+' ? 0 : 1;
        edge[2 * x + 1 - ox].push_back(2 * y + oy);
        edge[2 * y + 1 - oy].push_back(2 * x + ox);
        edge_rev[2 * y + oy].push_back(2 * x + 1 - ox);
        edge_rev[2 * x + ox].push_back(2 * y + 1 - oy);
    }
    vector<int> v(2 * m, 0);
    vector<int> order;
    for (int i = 0; i < 2 * m; i++)
    {
        if (v[i] == 0)
        {
            dfs(i, edge, v, order, 1);
        }
    }
    v.clear();
    int k = 0;
    vector<int> component(2 * m, 0);
    for (auto i = 2 * m - 1; i >= 0; i--)
    {
        if (component[order[i]] == 0)
        {
            k++;
            dfs(order[i], edge_rev, component, v, k);
        }
    }

    vector<bool> ans(m);

    for (int i = 0; i < m; i++)
    {
        if (component[2 * i] == component[2 * i + 1])
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        ans[i] = component[2 * i] > component[2 * i + 1];
    }

    for (int i = 0; i < m; i++)
    {
        cout << (ans[i] ? '+' : '-') << ' ';
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