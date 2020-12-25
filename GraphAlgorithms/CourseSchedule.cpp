// https://cses.fi/problemset/task/1679

#include <bits/stdc++.h>

using namespace std;

#define lli long long

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
        edge[y - 1].push_back(x - 1);
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
        for (int i = 0; i < n; i++)
        {
            cout << order[i] + 1 << ' ';
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