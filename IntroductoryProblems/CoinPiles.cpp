// https://cses.fi/problemset/task/1754

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    lli a, b;
    cin >> a >> b;

    if ((2 * a - b) % 3 == 0 && 2 * a >= b && 2 * b >= a && (2 * b - a) % 3 == 0)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli q = 1;
    cin >> q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}