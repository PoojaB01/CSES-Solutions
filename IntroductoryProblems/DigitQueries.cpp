// https://cses.fi/problemset/task/2431

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    lli k;
    cin >> k;
    lli t = 9;
    int d = 1;
    while (k > d * t)
    {
        k -= d * t;
        t *= 10;
        d++;
    }
    t /= 9;
    t = t + (k - 1) / d;
    k = (k - 1) % d;
    for (int i = 0; i < d - k - 1; i++)
    {
        t /= 10;
    }
    cout << t % 10 << endl;
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