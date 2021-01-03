// https://cses.fi/problemset/task/1632

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back({b, a});
    }
    sort(v.begin(), v.end());
    multiset<int> s;

    for (int i = 0; i < k; i++)
    {
        s.insert(0);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto itr = s.upper_bound(v[i].second);
        if (itr != s.begin())
        {
            ans++;
            itr--;
            s.erase(itr);
            s.insert(v[i].first);
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