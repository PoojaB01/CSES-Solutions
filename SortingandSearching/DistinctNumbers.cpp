// https://cses.fi/problemset/task/1621

#include <bits/stdc++.h>

using namespace std;

#define lli long long

int main()
{
    lli q = 1;
    time_t start, end;
    time(&start);
    for (lli tc = 1; tc <= q; tc++)
    {
        lli n, x;
        cin >> n;
        set<lli> m;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            m.insert(x);
        }
        cout << m.size() << endl;
    }

    return 0;
}