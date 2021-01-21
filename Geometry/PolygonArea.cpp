// https://cses.fi/problemset/task/2191

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n;
    cin >> n;
    lli x[n], y[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    lli ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        ans += x[0] * (y[i] - y[i + 1]) + x[i] * (y[i + 1] - y[0]) + x[i + 1] * (y[0] - y[i]);
    }
    cout << abs(ans) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q = 1;
    // cin >> q;
    while (q--)
        solve();
    return 0;
}