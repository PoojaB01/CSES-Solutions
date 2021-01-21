// https://cses.fi/problemset/task/2195

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli anchor_x, anchor_y;

bool compare(pair<lli, lli> &a, pair<lli, lli> &b)
{
    lli cross = (a.second - anchor_y) * (b.first - a.first) -
                (a.first - anchor_x) * (b.second - a.second);
    if (cross < 0)
        return true;
    if (cross > 0)
        return false;
    return abs(a.first - anchor_x) + abs(a.second - anchor_y) <= abs(b.first - anchor_x) + abs(b.second - anchor_y);
}

lli valid(pair<lli, lli> &a, pair<lli, lli> &b, pair<lli, lli> &c)
{
    lli cross = (b.second - a.second) * (c.first - b.first) -
                (c.second - b.second) * (b.first - a.first);
    return cross;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<lli, lli>> v(n);
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        if (v[i].second < v[m].second)
            m = i;
        else if (v[i].second == v[m].second && v[i].first < v[m].first)
            m = i;
    }
    anchor_x = v[m].first, anchor_y = v[m].second;
    sort(v.begin(), v.end(), compare);

    vector<int> index;
    index.push_back(0);
    index.push_back(1);
    for (int i = 2; i < n; i++)
    {
        while (index.size() >= 2)
        {
            int i1 = index[index.size() - 2], i2 = index[index.size() - 1];
            if (valid(v[i1], v[i2], v[i]) > 0)
            {
                index.pop_back();
            }
            else
                break;
        }
        index.push_back(i);
    }

    vector<pair<lli, lli>> ans;
    int k = index[index.size() - 2] + 1;
    for (int i : index)
    {
        ans.push_back(v[i]);
    }
    while (k != index.back())
    {
        if (valid(v[k], v[index.back()], v[0]) == 0)
            ans.push_back(v[k++]);
        else
            break;
    }
    cout << ans.size() << endl;
    for (auto p : ans)
    {
        cout << p.first << ' ' << p.second << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q = 1;
    // cin >> q;
    while (q--)
        solve();
    return 0;
}