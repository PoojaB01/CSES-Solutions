// https://cses.fi/problemset/task/1164

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    int a, b;
    set<int> rooms;
    int k = 0;
    int r[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back({a, -(i + 1)});
        v.push_back({b, i + 1});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second < 0)
        {
            if (!rooms.size())
            {
                k++;
                rooms.insert(k);
            }
            r[abs(v[i].second) - 1] = *rooms.begin();
            rooms.erase(rooms.begin());
        }
        else
        {
            rooms.insert(r[v[i].second - 1]);
        }
    }
    cout << k << endl;
    for (int i = 0; i < n; i++)
    {
        cout << r[i] << ' ';
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