// https://cses.fi/problemset/task/1696

#include <bits/stdc++.h>

using namespace std;

#define lli long long
lli MAX = 1e9 + 7;

bool bfs(vector<int> edge[], vector<int> &pair, vector<int> &dist, int n)
{
    dist.assign(n, MAX);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (pair[i] == -1)
        {
            dist[i] = 0;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i : edge[x])
        {
            if (pair[i] != -1)
            {
                if (dist[pair[i]] == MAX)
                {
                    dist[pair[i]] = dist[x] + 1;
                    q.push(pair[i]);
                }
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}

int dfs(int x, vector<int> edge[], vector<int> &pair, vector<int> &dist)
{
    for (int i : edge[x])
    {
        if (pair[i] == -1)
        {
            pair[i] = x;
            pair[x] = i;
            return 1;
        }
        else if (dist[pair[i]] == dist[x] + 1)
        {
            if (dfs(pair[i], edge, pair, dist))
            {
                pair[i] = x;
                pair[x] = i;
                return 1;
            }
        }
    }
    dist[x] = MAX;
    return 0;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> edge[n + m]; // first n boys m girls
    int x, y;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        edge[x - 1].push_back(n + y - 1);
        edge[n + y - 1].push_back(x - 1);
    }

    vector<int> pair(n + m, -1);
    vector<int> dist(n, -1);
    int ans = 0;

    while (bfs(edge, pair, dist, n))
    {
        for (int i = 0; i < n; i++)
        {
            if (pair[i] == -1)
            {
                ans += dfs(i, edge, pair, dist);
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        if (pair[i] != -1)
        {
            cout << i + 1 << ' ' << pair[i] - n + 1 << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}