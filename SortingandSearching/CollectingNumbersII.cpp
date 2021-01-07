// https://cses.fi/problemset/task/2217

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> index(n), a(n);
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a[i] = x - 1;
        index[x - 1] = i;
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (index[i] < index[i - 1])
            ans++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--;
        y--;

        if (a[x] != 0)
            ans -= index[a[x]] < index[a[x] - 1] ? 1 : 0;
        if (a[x] != n - 1)
            ans -= index[a[x] + 1] < index[a[x]] ? 1 : 0;
        if (a[y] != 0 && a[y] - 1 != a[x])
            ans -= index[a[y]] < index[a[y] - 1] ? 1 : 0;
        if (a[y] != n - 1 && a[y] + 1 != a[x])
            ans -= index[a[y] + 1] < index[a[y]] ? 1 : 0;

        swap(a[x], a[y]);
        index[a[y]] = y;
        index[a[x]] = x;

        if (a[x] != 0)
            ans += index[a[x]] < index[a[x] - 1] ? 1 : 0;
        if (a[x] != n - 1)
            ans += index[a[x] + 1] < index[a[x]] ? 1 : 0;
        if (a[y] != 0 && a[y] - 1 != a[x])
            ans += index[a[y]] < index[a[y] - 1] ? 1 : 0;
        if (a[y] != n - 1 && a[y] + 1 != a[x])
            ans += index[a[y] + 1] < index[a[y]] ? 1 : 0;

        cout << ans << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}