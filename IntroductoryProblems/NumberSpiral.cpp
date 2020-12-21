// https://cses.fi/problemset/task/1071

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    lli x, y;
    cin >> x >> y;
    lli t = max(x, y);
    if (t % 2)
        swap(x, y);
    if (x > y)
    {
        t = t * t;
        t -= y - 1;
    }
    else
    {
        t--;
        t = t * t;
        t += x;
    }
    cout << t << endl;
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