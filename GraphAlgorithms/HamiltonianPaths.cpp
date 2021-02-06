// https://cses.fi/problemset/task/1690

#include <bits/stdc++.h>

using namespace std;

#define lli long long

const int MOD = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    vector<int> edge[n];
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        edge[x - 1].push_back(y - 1);
    }

    vector<int> power(n + 1, 0);
    power[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        power[i] = power[i - 1] << 1;
    }

    int k = power[n];
    vector<vector<int>> paths(k, vector<int>(n, 0));
    
    paths[power[n-1]][n - 1] = 1;

    for (int i = power[n-1]; i < k; i++)
    {
        for (int p = 0; p < n; p++)
        {
            if (i & power[p])
            {
                for (int v : edge[p])
                {
                    if (power[v] & i)
                        paths[i][p] = (paths[i][p] + paths[i - power[p]][v]) % MOD;
                }
            }
        }
    }
    cout << paths[k - 1][0] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}