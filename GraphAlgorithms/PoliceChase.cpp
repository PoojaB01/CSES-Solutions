// https://cses.fi/problemset/task/1695
// Min Cut Problem

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

void dfs(int x, vector<set<int>> &edge, vector<vector<int>> &capacity, vector<bool> &visited)
{
    visited[x] = true;
    for (int i : edge[x])
    {
        if (!visited[i] && capacity[x][i])
        {
            dfs(i, edge, capacity, visited);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    vector<vector<int>> capacity(n, vector<int>(n, 0));
    vector<set<int>> edge(n);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        edge[x].insert(y);
        edge[y].insert(x);
        capacity[x][y] += 1;
        capacity[y][x] += 1;
    }

    cout << computeMaxFlow(edge, capacity, 0, n - 1, n) << endl;

    vector<bool> visited(n, false);
    dfs(0, edge, capacity, visited);

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            for (int j : edge[i])
            {
                if (!visited[j])
                {
                    cout << i + 1 << ' ' << j + 1 << endl;
                }
            }
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