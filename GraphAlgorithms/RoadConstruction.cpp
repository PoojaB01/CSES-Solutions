// https://cses.fi/problemset/task/1676

#include <bits/stdc++.h>

using namespace std;

#define lli long long

int findset(int x, vector<int> &p)
{
    if (x != p[x])
    {
        p[x] = findset(p[x], p);
    }
    return p[x];
}

void unionset(int a, int b, vector<int> &p, vector<int> &r)
{
    int x = findset(a, p);
    int y = findset(b, p);
    if (x != y)
    {
        if (r[x] < r[y])
            swap(x, y);
        p[y] = x;
        r[x] += r[y];
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    vector<int> p(n, 0), r(n, 1);
    int nc = n, sz = 1;
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        int f = findset(x, p), g = findset(y, p);
        if (f != g)
        {
            unionset(f, g, p, r);
            nc--;
            sz = max(sz, max(r[f], r[g]));
        }
        cout << nc << ' ' << sz << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}