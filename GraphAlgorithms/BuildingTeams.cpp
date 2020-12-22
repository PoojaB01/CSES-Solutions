// https://cses.fi/problemset/task/1668

#include <bits/stdc++.h>

using namespace std;

#define lli long long

bool dfs(int x, vector<int> &v, vector<int> edge[], int t)
{
    v[x] = (t == 1) ? 2 : 1;
    bool ans = true;
    for (auto i : edge[x])
    {
        if (v[i] == 0)
        {
            ans = ans && dfs(i, v, edge, v[x]);
        }
        if (v[i] == v[x])
            return false;
    }
    return ans;
}

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

    vector<int> v(n + 1, 0);

    for (int i = 1; i < n + 1; i++)
    {
        if (v[i] == 0)
        {
            if(!dfs(i, v, edge, 2))
            {
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<v[i+1]<<' ';
    }
    cout<<endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}