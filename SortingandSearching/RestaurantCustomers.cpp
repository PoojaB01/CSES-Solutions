// https://cses.fi/problemset/task/1619

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
        v.push_back({a, 1});
        v.push_back({b, -1});
    }
    sort(v.begin(), v.end());
    int ans = 1, sum = 1;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].first != v[i - 1].first)
        {
            ans = max(ans, sum);
        }
        sum += v[i].second;
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