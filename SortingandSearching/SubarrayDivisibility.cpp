// https://cses.fi/problemset/task/1662

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    lli n;
    cin >> n;
    lli sum = 0, a, ans = 0;
    int m[n] = {0};
    m[0] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        sum += (a + n * 10000000000) % n;
        sum = (sum + n) % n;
        ans += m[sum];
        m[sum]++;
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