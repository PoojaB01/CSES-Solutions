// https://cses.fi/problemset/task/2079

#include <bits/stdc++.h>

using namespace std;

#define lli long long

int findcentroid(int x, vector<int> edge[], vector<int> &s, vector<int> &v, int n)
{
    v[x] = 1;
    for (int i : edge[x])
    {
        if (v[i] == 0)
        {
            if (s[i] > n / 2)
                return findcentroid(i, edge, s, v, n);
        }
    }
    return x + 1;
}

void dfs(int x, vector<int> edge[], vector<int> &s)
{
    s[x] = 1;
    for (int i : edge[x])
    {
        if (s[i] == 0)
        {
            dfs(i, edge, s);
            s[x] += s[i];
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    int x, y;
    vector<int> edge[n];

    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        edge[x - 1].push_back(y - 1);
        edge[y - 1].push_back(x - 1);
    }

    vector<int> s(n, 0);

    dfs(0, edge, s);

    vector<int> v(n, 0);
    cout << findcentroid(0, edge, s, v, n) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    // cin >> q;
    for (int tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}