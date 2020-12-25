// https://cses.fi/problemset/task/1637

#include <bits/stdc++.h>

using namespace std;

#define lli long long

vector<int> dp(1000002, 10000000);
void preprocess()
{
    dp[0] = 0;
    for (int i = 1; i < 1000002; i++)
    {
        int t = i;
        while (t)
        {
            dp[i] = min(dp[i], dp[i - t % 10] + 1);
            t /= 10;
        }
    }
}
void solve()
{
    preprocess();
    int n;
    cin >> n;
    cout << dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}