// https://cses.fi/problemset/task/2216

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i].second < v[i - 1].second)
            ans++;
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}