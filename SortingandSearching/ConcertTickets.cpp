// https://cses.fi/problemset/task/1091

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, m;
    cin >> n >> m;
    int x;
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        auto itr = s.upper_bound(x);
        if (itr == s.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            itr--;
            cout << *itr << endl;
            s.erase(itr);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}