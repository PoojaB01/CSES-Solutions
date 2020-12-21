// https://cses.fi/problemset/task/1623

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n;
    cin >> n;
    set<lli> s;
    set<lli> t;
    s.insert(0);
    lli x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        for (auto itr = s.begin(); itr != s.end(); itr++)
        {
            t.insert(abs(*itr + x));
            t.insert(abs(*itr - x));
        }
        s = t;
        t.erase(t.begin(), t.end());
    }
    cout << *s.begin() << endl;
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