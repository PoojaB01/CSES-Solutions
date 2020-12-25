// https://cses.fi/problemset/task/1680
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long
 
lli MIN = -1e7;
 
bool dfs(int x, vector<int> edge[], vector<short> &v, vector<int> &order)
{
    v[x] = 2;
    bool ans = true;
    for (auto i : edge[x])
    {
        if (v[i] == 0)
        {
            ans = ans && dfs(i, edge, v, order);
        }
        else if (v[i] == 2)
        {
            return false;
        }
    }
    v[x] = 1;
    order.push_back(x);
    return ans;
}
 
void solve()
{
    int n, m, x, y;
    cin >> n >> m;
    vector<int> edge[n];
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        edge[x - 1].push_back(y - 1);
    }
    vector<short> v(n, 0);
    vector<int> order;
 
    bool ans = true;
 
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            ans = ans && dfs(i, edge, v, order);
        }
    }
 
    if (!ans)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<int> lfr(n, MIN);
        lfr[0] = 1;
        reverse(order.begin(), order.end());
        vector<int> par(n, -1);
        for (int i = 0; i < n; i++)
        {
            for (auto e : edge[order[i]])
            {
                if (lfr[order[i]] + 1 > lfr[e])
                {
                    lfr[e] = max(lfr[e], lfr[order[i]] + 1);
                    par[e] = order[i];
                }
            }
        }
        if (lfr[n - 1] < 0)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        cout << lfr[n - 1] << endl;
        x = n - 1;
        stack<int> path;
        for (int i = 0; i < lfr[n - 1]; i++)
        {
            path.push(x + 1);
            x = par[x];
        }
        while (!path.empty())
        {
            cout << path.top() << ' ';
            path.pop();
        }
        cout << endl;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
 
    return 0;
}