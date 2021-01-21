// https://cses.fi/problemset/task/2189

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    lli x[3], y[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> x[i] >> y[i];
    }

    lli cross = (y[2] - y[0]) * (x[1] - x[0]) - (y[1] - y[0]) * (x[2] - x[0]);

    if (cross == 0)
    {
        cout << "TOUCH" << endl;
    }
    else if (cross < 0)
    {
        cout << "RIGHT" << endl;
    }
    else
    {
        cout << "LEFT" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q = 1;
    cin >> q;
    while (q--)
        solve();
    return 0;
}