// https://cses.fi/problemset/task/1674

#include <bits/stdc++.h>

using namespace std;

#define lli long long

int dfs(int i, vector<int> v[], int s[])
{
    for (int j = 0; j < v[i].size(); j++)
    {
        s[i] += dfs(v[i][j], v, s);
    }
    return s[i] + 1;
}

void solve()
{
    int n;
    cin >> n;
    int x;
    vector<int> v[n];

    for (int i = 0; i < n - 1; i++)
    {
        cin >> x;
        v[x - 1].push_back(i + 1);
    }

    int s[n] = {0};
    dfs(0, v, s);

    for (int i = 0; i < n; i++)
    {
        cout << s[i] << ' ';
    }
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