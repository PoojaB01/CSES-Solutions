// https://cses.fi/problemset/task/1642

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            v.push_back({a[i] + a[j], {i + 1, j + 1}});
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        int j = lower_bound(v.begin(), v.end(), make_pair(x - v[i].first, make_pair(0, 0))) - v.begin();
        if (j >= v.size())
            continue;
        while (v[j].first + v[i].first == x)
        {
            if (v[i].second.first == v[j].second.first ||
                v[i].second.first == v[j].second.second ||
                v[i].second.second == v[j].second.first ||
                v[i].second.second == v[j].second.second)
            {
                if (j + 1 < n && v[j + 1].first == v[j].first)
                    j++;
                else
                    break;
            }
            else
            {
                cout << v[i].second.first << ' ' << v[i].second.second
                     << ' ' << v[j].second.first << ' ' << v[j].second.second << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}