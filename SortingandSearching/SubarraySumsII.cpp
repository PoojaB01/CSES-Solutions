// https://cses.fi/problemset/task/1661

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, x;
    cin >> n >> x;
    lli sum = 0, a, ans = 0;
    map<lli, int> m;
    m[0] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        sum += a;
        if (m.find(sum - x) != m.end())
        {
            ans += m[sum - x];
        }
        if (m.find(sum) == m.end())
        {
            m[sum] = 0;
        }
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