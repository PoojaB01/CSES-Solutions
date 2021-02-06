// https://cses.fi/problemset/task/1693

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    vector<int> edge[n];
    vector<int> degree(n, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        edge[x - 1].push_back(y - 1);
        degree[x - 1]++;
        degree[y - 1]--;
    }
    vector<int> index(n, 0);
    vector<int> ans;
    stack<int> s;
    s.push(0);

    if (degree[0] != 1 || degree[n - 1] != -1)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (degree[i])
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    while (!s.empty())
    {
        if (index[s.top()] == edge[s.top()].size())
        {
            ans.push_back(s.top());
            s.pop();
        }
        else
        {
            s.push(edge[s.top()][index[s.top()]++]);
        }
    }
    reverse(ans.begin(), ans.end());

    if (ans.size() == m + 1 && ans.back() == n - 1)
    {
        for (int i : ans)
        {
            cout << i + 1 << ' ';
        }
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}