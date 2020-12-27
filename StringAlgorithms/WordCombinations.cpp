// https://cses.fi/problemset/task/1731

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli MOD = 1e9 + 7;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int k;
    cin >> k;
    vector<bool> present(1000010, false);
    vector<vector<int>> next(1000010, vector<int>(26, 0));
    int index = 2, x;
    string t;
    for (int i = 0; i < k; i++)
    {
        cin >> t;
        x = 1;
        for (int j = 0; j < t.length(); j++)
        {
            if (!next[x][t[j] - 'a'])
            {
                next[x][t[j] - 'a'] = index++;
            }
            x = next[x][t[j] - 'a'];
        }
        present[x] = true;
    }

    vector<lli> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        x = 1;
        for (int j = i; j < n; j++)
        {
            x = next[x][s[j] - 'a'];
            if (present[x])
            {
                dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
            }
        }
    }
    cout<<dp[n]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}