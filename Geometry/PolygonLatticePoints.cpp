// https://cses.fi/problemset/task/2193

#include <bits/stdc++.h>

using namespace std;

#define lli long long

// Pick's Theorem
void solve()
{
    int n;
    cin >> n;
    lli x[n], y[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    lli area = 0;
    lli B = 0;
    for (int i = 1; i < n - 1; i++)
    {
        area += x[0] * (y[i] - y[i + 1]) + x[i] * (y[i + 1] - y[0]) + x[i + 1] * (y[0] - y[i]);
    }
    area = abs(area);
    for (int i = 0; i < n; i++)
    {
        B += __gcd(abs(x[i] - x[(i + 1) % n]), abs(y[i] - y[(i + 1) % n]));
    }
    cout << (area - B) / 2 + 1 << ' ' << B << endl;
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