// https://cses.fi/problemset/task/2168

#include <bits/stdc++.h>

using namespace std;

#define lli long long

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first < b.first)
        return true;
    else if (a.first == b.first)
        return b.second < a.second;
    else
        return false;
}

void solve()
{
    int n;
    cin >> n;
    int x, y;
    vector<pair<int, int>> v;
    map<pair<int, int>, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back({x, y});
        m[{x, y}] = i;
    }
    sort(v.begin(), v.end(), compare);
    int ma = 0;
    vector<int> a(n, 0), b(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (ma >= v[i].second)
            b[m[v[i]]] = 1;
        ma = max(ma, v[i].second);
    }
    int mi = 1e9 + 7;
    for (int i = n - 1; i >= 0; i--)
    {
        if (mi <= v[i].second)
            a[m[v[i]]] = 1;
        mi = min(mi, v[i].second);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << ' ';
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}