// https://cses.fi/problemset/task/1694
// Maximum flow
// Edmonds-Karp Algorithm

#include <bits/stdc++.h>

using namespace std;

#define lli long long
lli MAX = 1e9 + 7;

lli computeMaxFlow(vector<set<int>> &edge, vector<vector<lli>> &capacity, int source, int sink, int n)
{
    vector<int> parent(n, -1);
    lli flow = 0;
    lli maxflow = 0;
    do
    {
        flow = 0;
        parent.assign(n, -1);
        queue<pair<int, lli>> q;
        q.push({source, MAX});
        parent[source] = source;
        while (!q.empty())
        {
            int x = q.front().first;
            lli val = q.front().second;
            q.pop();
            for (int i : edge[x])
            {
                // cout << x << ' ' << i << endl;
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

void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    lli c;
    vector<vector<lli>> capacity(n, vector<lli>(n, 0));
    vector<set<int>> edge(n);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> c;
        x--;
        y--;
        edge[x].insert(y);
        edge[y].insert(x);
        capacity[x][y] += c;
    }

    cout << computeMaxFlow(edge, capacity, 0, n - 1, n) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}