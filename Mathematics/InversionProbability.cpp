// https://cses.fi/problemset/task/1728

#include <bits/stdc++.h>

using namespace std;

#define lli long long
#define ldb long double

void solve()
{
    int n;
    cin >> n;
    int r[n];
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    ldb ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int x = 1; x <= r[i]; x++)
            {
                ans += min(x - 1, r[j]) / (ldb)(r[i] * r[j]);
            }
        }
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