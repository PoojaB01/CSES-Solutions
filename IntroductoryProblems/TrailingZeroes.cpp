// https://cses.fi/problemset/task/1618

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    lli n;
    cin >> n;
    lli ans = 0;
    while (n)
    {
        ans += n / 5;
        n /= 5;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli q = 1;
    //cin>>q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}