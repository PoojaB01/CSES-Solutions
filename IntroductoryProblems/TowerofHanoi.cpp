// https://cses.fi/problemset/task/2165

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void towerofhanoi(vector<pair<int, int>> &v, int n, int A, int C, int B)
{
    if (n == 0)
    {
        return;
    }
    towerofhanoi(v, n - 1, A, B, C);
    v.push_back({A, C});
    towerofhanoi(v, n - 1, B, C, A);
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    towerofhanoi(v, n, 1, 3, 2);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << ' ' << v[i].second << endl;
    }
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