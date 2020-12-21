// https://cses.fi/problemset/task/1072

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    lli k;
    cin >> k;
    lli dp[k + 1];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;
    for (lli i = 3; i < k + 1; i++)
    {
        dp[i] = dp[i - 1];
        dp[i] += (2 * i - 1) * 4;
        dp[i] -= 12;
    }
    lli sum = 0;
    for (lli i = 1; i < k + 1; i++)
    {
        sum = i * i * (i * i - 1);
        sum /= 2;
        dp[i] = sum - dp[i];
        cout << dp[i] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli q = 1;
    // cin>>q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}