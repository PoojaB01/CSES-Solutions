// https://cses.fi/problemset/task/1094

#include <bits/stdc++.h>

using namespace std;

#define lli long long

int main()
{
    int n;
    cin >> n;

    lli a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    lli m = a[0];
    lli ans = 0;

    for (int i = 1; i < n; i++)
    {
        ans += max(0ll, m - a[i]);
        m = max(m, a[i]);
    }

    cout << ans << endl;

    return 0;
}