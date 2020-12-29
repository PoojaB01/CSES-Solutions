// https://cses.fi/problemset/task/1727

#include <bits/stdc++.h>

using namespace std;

#define lli long long
#define ldb long double

void solve()
{
    ldb n, k;
    cin >> n >> k;
    ldb ans = 0;
    ldb p1 = 0;
    for (ldb x = 1; x <= k; x++)
    {
        ldb p = 1;
        for (int i = 0; i < n; i++)
        {
            p *= x / k;
        }
        p -= p1;
        p1 += p;
        ans += x * p;
    }
    cout << fixed << setprecision(6) << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli q = 1;
    // cin >> q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}