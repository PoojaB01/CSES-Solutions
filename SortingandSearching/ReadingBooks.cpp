// https://cses.fi/problemset/task/1631

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n;
    cin >> n;
    lli a[n], sum = 0, m = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        m = max(m, a[i]);
    }
    if (sum - m > m)
        cout << sum << endl;
    else
        cout << 2 * m << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}