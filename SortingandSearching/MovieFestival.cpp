// https://cses.fi/problemset/task/1629

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    int m = v.back().second;
    for (int i = n - 1; i >= 0; i--)
    {
        m = min(v[i].second, m);
        v[i].second = m;
    }
    int start = 1, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].first >= start)
        {
            ans++;
            start = v[i].second;
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