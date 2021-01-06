// https://cses.fi/problemset/task/2205
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long
 
void solve()
{
    int n;
    cin >> n;
    vector<string> s, v;
    v.push_back("");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            s.push_back(v[j] + '0');
        }
        for (int j = v.size() - 1; j >= 0; j--)
        {
            s.push_back(v[j] + '1');
        }
        v = s;
        s.clear();
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli q = 1;
    // cin>>q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}