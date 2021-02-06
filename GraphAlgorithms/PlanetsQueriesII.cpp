// https://cses.fi/problemset/task/1160

#include <bits/stdc++.h>

using namespace std;

#define lli long long

class LCA
{
    vector<vector<int>> p;
    vector<int> start, end, size;
    bool is_ancestor(int x, int y, vector<int> &start, vector<int> &end)
    {
        return start[x] <= start[y] && end[x] >= end[y];
    }
    int dfs(int x, vector<int> v[], int &k)
    {
        start[x] = k;
        size[x] = 1;

        k++;
        for (auto itr = v[x].begin(); itr != v[x].end(); itr++)
        {
            int j = *itr;
            p[0][j] = x;
            size[x] += dfs(j, v, k);
        }
        end[x] = k;
        return size[x];
    }

public:
    LCA(vector<int> edge[], int n)
    {
        p = vector<vector<int>>(24, vector<int>(n));
        start = end = size = vector<int>(n, -1);
        int k = 0;
        dfs(0, edge, k);
        p[0][0] = 0;
        for (int k = 1; k < 24; k++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                p[k][j] = p[k - 1][p[k - 1][j]];
            }
        }
    }
    // modified
    int getLCA(int x, int y)
    {
        for (int k = 23; k >= 0; k--)
        {
            if (!is_ancestor(p[k][x], y, start, end))
            {
                x = p[k][x];
                if (x == y)
                    return x;
            }
        }
        if (is_ancestor(x, y, start, end))
            return x;
        else
            return p[0][x];
    }

    int getSize(int x)
    {
        return size[x];
    }
    int getParent(int x)
    {
        return p[0][x];
    }
};

void bfs(vector<int> edge[], queue<pair<int, int>> q, vector<int> &dist, vector<int> &root)
{
    while (!q.empty())
    {
        int x = q.front().first;
        int p = q.front().second;
        q.pop();
        for (int i : edge[x])
        {
            if (dist[i] == -1)
            {
                dist[i] = dist[x] + 1;
                q.push({i, p});
                root[i] = p;
            }
        }
    }
}

void solve()
{
    int n, q;
    scanf("%d %d", &n, &q);
    vector<int> next(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &next[i]);
    }

    vector<int> vis(n + 1, 0);
    vector<int> cycle(n + 1, -1);
    vector<int> stack;

    for (int i = 1; i <= n; i++)
    {
        int x = i;
        while (!vis[x])
        {
            vis[x] = 1;
            stack.push_back(x);
            x = next[x];
        }
        if (vis[x] == 1)
        {
            int k = stack.size() - 1;
            do
            {
                cycle[stack[k]] = i + n;
            } while (stack[k--] != x);
        }
        while (stack.size())
        {
            vis[stack.back()] = 2 + stack.size();
            stack.pop_back();
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cycle[i] = cycle[i] == -1 ? i : cycle[i];
    }

    vector<int> edge[2 * n + 1];
    queue<pair<int, int>> qu;
    vector<int> dist(2 * n + 1, -1);
    vector<int> root(2 * n + 1, -1);
    vector<int> cyclesize(2 * n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (cycle[next[i]] != cycle[i])
            edge[next[i]].push_back(cycle[i]);
        if (cycle[next[i]] > n)
        {
            if (dist[next[i]] == -1)
                qu.push({next[i], next[i]});
            dist[next[i]] = 0;
        }
        cyclesize[cycle[i]]++;
    }

    bfs(edge, qu, dist, root);

    for (int i = 1; i <= n; i++)
    {
        if (cycle[i] > n)
        {
            edge[cycle[i]].insert(edge[cycle[i]].end(), edge[i].begin(), edge[i].end());
            edge[i].clear();
        }
    }
    for (int i = n + 1; i <= 2 * n; i++)
    {
        edge[0].push_back(i);
        dist[i] = 0;
    }
    LCA lca(edge, 2 * n + 1);

    // for (int i = 0; i <= 2 * n; i++)
    // {
    //     cout << i << " -> ";
    //     for (int j : edge[i])
    //     {
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }

    // for (int i = 1; i <= 2 * n; i++)
    // {
    //     cout << dist[i] << ' ' << root[i] << ' ' << vis[i] << endl;
    // }

    int x, y;
    while (q--)
    {
        scanf("%d %d", &x, &y);
        int anc = lca.getLCA(cycle[x], cycle[y]);
        if (anc != cycle[y])
        {
            printf("%d \n", -1);
        }
        else if (cycle[x] > n)
        {
            printf("%d \n", (vis[y] - vis[x] + cyclesize[cycle[y]]) % cyclesize[cycle[y]]);
        }
        else if (cycle[y] <= n)
        {
            printf("%d \n", dist[x] - dist[y]);
        }
        else
        {
            int ans = abs(dist[x] - dist[root[x]]);
            printf("%d \n", (vis[y] - vis[root[x]] + cyclesize[cycle[y]]) % cyclesize[cycle[y]] + ans);
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
