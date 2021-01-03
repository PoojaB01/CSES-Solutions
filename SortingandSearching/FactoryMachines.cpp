// https://cses.fi/problemset/task/1620

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    lli n, t;
    cin >> n >> t;
    lli a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lli start = 1, end = t * a[0], mid;
    lli ans = 1;
    while (start <= end)
    {
        mid = (start + end) / 2;
        lli p = 0;
        for (lli i : a)
        {
            p += mid / i;
            if (p >= t)
                break;
        }
        if (p < t)
        {
            start = mid + 1;
        }
        else
        {
            ans = mid;
            end = mid - 1;
        }
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