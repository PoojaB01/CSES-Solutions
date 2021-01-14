// https://cses.fi/problemset/task/2413/

#include <bits/stdc++.h>

using namespace std;

#define lli long long

int MOD = 1e9 + 7;

vector<lli> cnt(1000010, 0);

void preprocess()
{
    cnt[0] = 1;
    lli sum = 1, sum1 = 1;
    for (int i = 1; i < 1000010; i++)
    {
        cnt[i] = (sum1 + sum) % MOD;
        sum = (sum + cnt[i]) % MOD;
        sum1 = (3 * sum1 + cnt[i]) % MOD;
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << cnt[n] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    preprocess();
    int q;
    cin >> q;
    while (q--)
        solve();
    return 0;
}
