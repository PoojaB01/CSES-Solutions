// https://cses.fi/problemset/task/1711

#include <bits/stdc++.h>

using namespace std;

#define lli long long
int MAX = 1e9 + 7;

int computeMaxFlow(vector<set<int>> &edge, vector<vector<int>> &capacity, int source, int sink, int n)
{
    vector<int> parent(n, -1);
    int flow = 0;
    int maxflow = 0;
    do
    {
        flow = 0;
        parent.assign(n, -1);
        queue<pair<int, int>> q;
        q.push({source, MAX});
        parent[source] = source;
        while (!q.empty())
        {
            int x = q.front().first;
            int val = q.front().second;
            q.pop();
            for (int i : edge[x])
            {
                if (parent[i] == -1 && capacity[x][i])
                {
                    parent[i] = x;
                    if (i == sink)
                    {
                        flow = min(val, capacity[x][i]);
                        goto end;
                    }
                    q.push({i, min(capacity[x][i], val)});
                }
            }
        }
    end:
        maxflow += flow;
        if (parent[sink] != -1)
        {
            int x = sink;
            while (x != source)
            {
                capacity[x][parent[x]] += flow;
                capacity[parent[x]][x] -= flow;
                x = parent[x];
            }
        }
    } while (flow);
    return maxflow;
}

bool dfs(int x, vector<int> edge[], vector<vector<int>> &capacity, vector<bool> &visited, vector<int> &path, int sink)
{
    visited[x] = true;
    if (x == sink)
    {
        path.push_back(x);
        return true;
    }
    for (int i : edge[x])
    {
        if (!visited[i] && capacity[x][i] == 0)
        {
            if (dfs(i, edge, capacity, visited, path, sink))
            {
                path.push_back(x);
                capacity[x][i] = 1;
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    vector<vector<int>> capacity(n, vector<int>(n, 0));
    vector<set<int>> edge(n);
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        edge[x].insert(y);
        edge[y].insert(x);
        adj[x].push_back(y);
        capacity[x][y] += 1;
    }

    int distinctRoutes = computeMaxFlow(edge, capacity, 0, n - 1, n);
    cout << distinctRoutes << endl;

    for (int i = 0; i < distinctRoutes; i++)
    {
        vector<int> path;
        vector<bool> visited(n, false);
        dfs(0, adj, capacity, visited, path, n - 1);
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (int p : path)
        {
            cout << p + 1 << ' ';
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