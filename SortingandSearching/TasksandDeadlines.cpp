// https://cses.fi/problemset/task/1630
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long
 
void solve()
{
    int n;
    cin >> n;
    lli a[n], d[n];
    lli ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> d[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        ans -= a[i] * (n - i);
        ans += d[i];
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