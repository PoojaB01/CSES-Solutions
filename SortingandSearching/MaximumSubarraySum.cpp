// https://cses.fi/problemset/task/1643

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lli sum = a[0];
    lli ans = a[0];
    for (int i = 1; i < n; i++)
    {
        sum = max(0ll, sum);
        sum += a[i];
        ans = max(ans, sum);
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