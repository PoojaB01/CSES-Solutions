// https://cses.fi/problemset/task/1074

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    lli n;
    cin >> n;
    lli a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    lli t = a[(n - 1) / 2];
    lli ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(a[i] - t);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}