// https://cses.fi/problemset/task/2194/

#include <bits/stdc++.h>

using namespace std;

#define lli long long
lli MAX = 9223372036854775807;

struct point
{
    lli x, y;
};

bool compareX(point &a, point &b)
{
    return a.x < b.x;
}

bool compareY(point &a, point &b)
{
    return a.y < b.y;
}

lli dist(point &a, point &b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

lli mindist(vector<point> &v, int start, int end)
{
    lli d = MAX;
    if (end - start <= 3)
    {
        for (int i = start; i <= end; i++)
        {
            for (int j = i + 1; j <= end; j++)
            {
                d = min(d, dist(v[i], v[j]));
            }
        }
        return d;
    }
    int mid = (start + end) / 2;
    d = min(mindist(v, start, mid), mindist(v, mid + 1, end));
    vector<point> t;
    for (int i = start; i <= end; i++)
    {
        if ((v[i].x - v[mid].x) * (v[i].x - v[mid].x) < d)
        {
            t.push_back(v[i]);
        }
    }
    sort(t.begin(), t.end(), compareY);
    for (int i = 0; i < t.size(); i++)
    {
        for (int j = i + 1; j < min(i + 8, (int)t.size()); j++)
        {
            d = min(d, dist(t[i], t[j]));
        }
    }
    return d;
}

void solve()
{
    int n;
    cin >> n;
    vector<point> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].x >> v[i].y;
    }
    sort(v.begin(), v.end(), compareX);
    cout << mindist(v, 0, n - 1) << endl;
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