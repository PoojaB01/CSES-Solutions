// https://cses.fi/problemset/task/1745

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
    int dp[100006] = {0};
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 100005; j >= a[i]; j--)
        {
            dp[j] = dp[j] | dp[j - a[i]];
        }
    }
    int k = 0;
    for (int i = 1; i < 100006; i++)
    {
        if (dp[i])
            k++;
    }
    cout << k << endl;
    for (int i = 1; i < 100006; i++)
    {
        if (dp[i])
            cout << i << ' ';
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}