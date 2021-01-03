// https://cses.fi/problemset/task/1641

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back({a, i + 1});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int start = j + 1, end = n - 1, mid, req = x - v[i].first - v[j].first;
            while (start <= end)
            {
                mid = (start + end) / 2;
                if (v[mid].first == req)
                {
                    cout << v[i].second << ' ' << v[j].second << ' ' << v[mid].second << endl;
                    return;
                }
                else if (v[mid].first < req)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
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