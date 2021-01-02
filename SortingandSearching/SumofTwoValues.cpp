// https://cses.fi/problemset/task/1640
 
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
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (v[i].first + v[j].first == x)
        {
            cout << v[i].second << ' ' << v[j].second << endl;
            return;
        }
        else if (v[i].first + v[j].first < x)
        {
            i++;
        }
        else
        {
            j--;
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