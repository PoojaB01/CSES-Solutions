// https://cses.fi/problemset/task/1653

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n;
    cin >> n;
    lli x, sum = 0;
    cin >> x;
    vector<lli> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int m = pow(2, n);
    vector<pair<int,lli>> dp(m, {21, x+1});
    dp[0] = {0, x};
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & 1 << j)
            {
                pair<int, lli> p = dp[i - (1<<j)];
                if(p.second + a[j] <= x)
                {
                    p.second += a[j];
                }
                else {
                    p.first++;
                    p.second = a[j];
                }
                dp[i] = min(dp[i], p);
            }
        }
    }
    
    cout << dp[m - 1].first << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q = 1;
    // cin >> q;
    while (q--)
        solve();
    return 0;
}