// https://cses.fi/problemset/task/1077

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, k;
    cin >> n >> k;
    set<pair<int, int>> mi, ma;
    lli sum_ma = 0, sum_mi = 0;
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
        sum_ma += a[i];
    }
    for (int i = 0; i < n - k + 1; i++)
    {
        if (mi.find({a[i], i}) != mi.end())
        {
            auto itr = mi.find({a[i], i});
            mi.erase(itr);
            sum_mi -= a[i];
        }
        if (ma.find({a[i], i}) != ma.end())
        {
            auto itr = ma.find({a[i], i});
            ma.erase(itr);
            sum_ma -= a[i];
        }
        if (a[i + k] > m)
        {
            ma.insert({a[i + k], i + k});
            sum_ma += a[i + k];
        }
        else
        {
            mi.insert({a[i + k], i + k});
            sum_mi += a[i + k];
        }
        while (ma.size() > (k + 2) / 2)
        {
            auto itr = ma.begin();
            sum_ma -= itr->first;
            sum_mi += itr->first;
            mi.insert(*itr);
            ma.erase(itr);
        }
        while (mi.size() > k - (k + 2) / 2)
        {
            auto itr = mi.end();
            itr--;
            sum_ma += itr->first;
            sum_mi -= itr->first;
            ma.insert(*itr);
            mi.erase(itr);
        }
        m = ma.begin()->first;
        cout << sum_ma - ma.size() * m + mi.size() * m - sum_mi << ' ';
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