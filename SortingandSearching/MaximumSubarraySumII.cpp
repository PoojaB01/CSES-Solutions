// https://cses.fi/problemset/task/1644

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    lli p[n + 1];
    p[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i + 1];
    }
    for (int i = 1; i <= n; i++)
    {
        p[i] += p[i - 1];
    }
    set<pair<lli, int>> s;
    s.insert({0, 0});
    lli ans = -1e15;
    for (int i = a; i <= n; i++)
    {
        ans = max(p[i] - s.begin()->first, ans);
        s.insert({p[i - a + 1], i - a + 1});
        if (i - b >= 0)
        {
            s.erase({p[i - b], i - b});
        }
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