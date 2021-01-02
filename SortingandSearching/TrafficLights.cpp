// https://cses.fi/problemset/task/1163

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int x, n;
    cin >> x >> n;
    int a, u, l;
    set<int> s;
    s.insert(0);
    s.insert(x);
    multiset<int> m;
    m.insert(x);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        
        auto itr = s.upper_bound(a);
        u = *itr;
        itr--;
        l = *itr;
        s.insert(a);

        m.insert(u - a);
        m.insert(a - l);
        m.erase(m.find(u - l));

        itr = m.end();
        itr--;
        cout << *itr << ' ';
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