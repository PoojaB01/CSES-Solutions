// https://cses.fi/problemset/task/2190/

#include <bits/stdc++.h>

using namespace std;

#define lli long long

int side(lli x0, lli y0, lli x1, lli y1, lli x, lli y)
{
    lli cross = (y - y0) * (x1 - x0) - (y1 - y0) * (x - x0);
    if (cross != 0)
        cross /= abs(cross);
    return cross;
}

void solve()
{
    lli x[4], y[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> x[i] >> y[i];
    }

    if ((y[3] - y[2]) * (x[1] - x[0]) == (x[3] - x[2]) * (y[1] - y[0]))
    {
        if ((y[3] - y[0]) * (x[1] - x[0]) == (x[3] - x[0]) * (y[1] - y[0]))
        {
            if (min(x[0], x[1]) > max(x[2], x[3]) || min(y[0], y[1]) > max(y[2], y[3]) ||
                min(x[2], x[3]) > max(x[0], x[1]) || min(y[2], y[3]) > max(y[0], y[1]))
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
        return;
    }

    if (side(x[0], y[0], x[1], y[1], x[2], y[2]) * side(x[0], y[0], x[1], y[1], x[3], y[3]) <= 0 &&
        side(x[2], y[2], x[3], y[3], x[0], y[0]) * side(x[2], y[2], x[3], y[3], x[1], y[1]) <= 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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