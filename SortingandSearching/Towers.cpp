// https://cses.fi/problemset/task/1073

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n;
    cin >> n;
    int a;
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        auto itr = s.upper_bound(a);
        if (itr != s.end())
        {
            s.erase(itr);
        }
        s.insert(a);
    }
    cout << s.size() << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}