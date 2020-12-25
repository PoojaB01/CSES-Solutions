// https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>

using namespace std;

#define lli long long
lli MOD = 1e9 + 7;

int main()
{
    lli q = 1;
    time_t start, end;
    time(&start);
    for (lli tc = 1; tc <= q; tc++)
    {
        lli n;
        cin >> n;
        lli dp[n + 1] = {0};
        dp[0] = 1;
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 1; j < 7; j++)
            {
                if (i + j <= n)
                {
                    dp[i + j] = (dp[i + j] + dp[i]) % MOD;
                }
            }
        }
        cout << dp[n] << endl;
    }

    time(&end);
    return 0;
}