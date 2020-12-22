// https://cses.fi/problemset/task/1667

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, m, x, y;
    cin >> n >> m;
    vector<int> edge[n + 1];
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    vector<int> p(n + 1, -1);
    queue<int> q;

    q.push(1);
    p[1] = 0;

    while (!q.empty())
    {
        for (auto i : edge[q.front()])
        {
            if (p[i] == -1)
            {
                q.push(i);
                p[i] = q.front();
            }
            if (i == n)
                break;
        }
        q.pop();
    }
    if (p[n] == -1)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    x = n;
    vector<int> path;
    while (x != 0)
    {
        path.push_back(x);
        x = p[x];
    }
    cout << path.size() << endl;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << ' ';
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}