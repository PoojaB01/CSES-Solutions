// https://cses.fi/problemset/task/1130/

#include <bits/stdc++.h>

using namespace std;

#define lli long long

int dfs(int x, vector<int> v[], int vi[], int s[], int n)
{
    vi[x] = 1;
    int sum = 0;
    vector<int> t;
    for (int i = 0; i < v[x].size(); i++)
    {
        if (vi[v[x][i]] == 0)
        {
            dfs(v[x][i], v, vi, s, n);
            sum += s[v[x][i]];
            t.push_back(v[x][i]);
        }
    }
    s[n + x] = sum;
    int m = sum;
    for (int i = 0; i < t.size(); i++)
    {
        m = max(sum - s[t[i]] + s[t[i] + n] + 1, m);
    }
    s[x] = m;
    return m;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v[n];
    int x, y;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        v[x - 1].push_back(y - 1);
        v[y - 1].push_back(x - 1);
    }
    int vi[n] = {0};
    int s[2 * n] = {0};
    dfs(0, v, vi, s, n);
    cout << s[0] << endl;
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