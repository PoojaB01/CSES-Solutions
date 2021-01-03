// https://cses.fi/problemset/task/1076

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, k;
    cin >> n >> k;
    set<pair<int, int>> mi, ma;
    int a[n + 1];
    a[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i + 1];
    }
    int m = 0;
    for (int i = 0; i < k; i++)
    {
        ma.insert({a[i], i});
    }
    for (int i = 0; i < n - k + 1; i++)
    {
        if (mi.find({a[i], i}) != mi.end())
        {
            auto itr = mi.find({a[i], i});
            mi.erase(itr);
        }
        if (ma.find({a[i], i}) != ma.end())
        {
            auto itr = ma.find({a[i], i});
            ma.erase(itr);
        }
        if (a[i + k] > m)
            ma.insert({a[i + k], i + k});
        else
            mi.insert({a[i + k], i + k});
        while (ma.size() > (k + 2) / 2)
        {
            auto itr = ma.begin();
            mi.insert(*itr);
            ma.erase(itr);
        }
        while (mi.size() > k - (k + 2) / 2)
        {
            auto itr = mi.end();
            itr--;
            ma.insert(*itr);
            mi.erase(itr);
        }
        m = ma.begin()->first;
        cout << m << ' ';
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli q = 1;
    // cin >> q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}