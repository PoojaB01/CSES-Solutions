// https://cses.fi/problemset/task/1636

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, x;
    cin >> n >> x;
    int c[n];
    int MOD = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    int count[x + 1] = {0};
    count[0] = 1;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i <= x; i++)
        {
            if (c[j] <= i)
            {
                count[i] += count[i - c[j]];
                count[i] %= MOD;
            }
        }
    }
    cout << count[x] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}