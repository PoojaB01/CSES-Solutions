// https://cses.fi/problemset/task/1681

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli MOD = 1e9 + 7;

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
        vector<lli> ways(n, 0);
        ways[0] = 1;
        reverse(order.begin(), order.end());
        for (int i = 0; i < n; i++)
        {
            for (auto e : edge[order[i]])
            {
                ways[e] = (ways[e] + ways[order[i]]) % MOD;
            }
        }
        cout << ways[n - 1] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}