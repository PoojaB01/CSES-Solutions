// https://cses.fi/problemset/task/1131/

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void dfs(int i, vector<int> v[], int s[], int d, int vi[])
{
    vi[i] = 1;
    for (int j = 0; j < v[i].size(); j++)
    {
        if (vi[v[i][j]] == 0)
            dfs(v[i][j], v, s, d + 1, vi);
    }
    s[i] = d;
}

void solve()
{
    int n;
    cin >> n;
    int x, y;
    vector<int> v[n];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        v[x - 1].push_back(y - 1);
        v[y - 1].push_back(x - 1);
    }
    int s[n] = {0};
    int vi[n] = {0};
    dfs(0, v, s, 0, vi);
    int p = -1;
    for (int i = 0; i < n; i++)
    {
        if (p == -1)
            p = i;
        else if (s[p] < s[i])
            p = i;
        vi[i] = 0;
    }
    dfs(p, v, s, 0, vi);
    for (int i = 0; i < n; i++)
    {
        if (p == -1)
            p = i;
        else if (s[p] < s[i])
            p = i;
        vi[i] = 0;
    }
    cout << s[p] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli q = 1;
    // cin>>q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}