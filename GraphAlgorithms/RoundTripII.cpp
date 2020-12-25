// https://cses.fi/problemset/task/1678

#include <bits/stdc++.h>

using namespace std;

#define lli long long

bool dfs(int x, vector<int> edge[], vector<short> &v, vector<int> &cycle, int &end_point)
{
    v[x] = 2;
    bool ans = true;
    for (auto i : edge[x])
    {
        if (v[i] == 0)
        {
            ans = ans && dfs(i, edge, v, cycle, end_point);
            if (!ans)
            {
                if (cycle.back() != end_point)
                    cycle.push_back(x);
                return false;
            }
        }
        else if (v[i] == 2)
        {
            cycle.push_back(x);
            end_point = i;
            return false;
        }
    }
    v[x] = 1;
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
    vector<int> cycle;

    bool ans = true;

    int end_point = -1;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            ans = ans && dfs(i, edge, v, cycle, end_point);
        }
    }

    if (!ans)
    {
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() + 1 << endl;
        cout << cycle.back() + 1 << ' ';

        for (int i = 0; i < cycle.size(); i++)
        {
            cout << cycle[i] + 1 << ' ';
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}