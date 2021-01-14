// https://cses.fi/problemset/task/2181

#include <bits/stdc++.h>

using namespace std;

#define lli long long
lli MOD = 1e9 + 7;

bool compatible(int x, int y, int n)
{
    for (int i = 0; i < n; i++)
    {
        int k = 1 << i;
        if ((x & k) == 0 && (y & k) == 0)
        {
            if ((x & (k * 2)) == 0 && (y & (k * 2)) == 0 && i != n - 1)
            {
                i++;
            }
            else
                return false;
        }
        else if ((x & k) == k && (y & k) == k)
            return false;
    }
    return true;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int s = pow(2, n);
    vector<int> v[s];
    int count = 0;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (compatible(i, j, n))
            {
                v[i].push_back(j);
                count++;
            }
        }
    }
    vector<vector<lli>> dp(s, vector<lli>(m + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < s; j++)
        {
            for (int p : v[j])
            {
                dp[p][i + 1] = (dp[p][i + 1] + dp[j][i]) % MOD;
            }
        }
    }
    cout << dp[0][m] << endl;
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