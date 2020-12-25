// https://cses.fi/problemset/task/1197

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli MAX = 1e15;

void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    lli z;
    vector<pair<int, lli>> edge[n];
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        edge[x - 1].push_back({y - 1, z});
    }

    vector<lli> dp(n, MAX);
    dp[0] = 0;
    vector<int> p(n, -1);

    for (int k = 0; k < 2 * n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (auto e : edge[i])
            {
                if (dp[e.first] > dp[i] + e.second)
                {
                    dp[e.first] = dp[i] + e.second;
                    p[e.first] = i;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (auto e : edge[i])
        {
            if (dp[e.first] > dp[i] + e.second)
            {
                cout << "YES" << endl;
                x = e.first;

                vector<int> path;
                set<int> s;
                path.push_back(e.first + 1);

                while (s.find(x) == s.end())
                {
                    s.insert(x);
                    x = p[x];
                    path.push_back(x + 1);
                }
                
                reverse(path.begin(), path.end());

                for (int i = 0; i < path.size(); i++)
                {
                    cout << path[i] << ' ';
                    if (path[i] == x + 1 && i)
                        break;
                }
                cout << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}