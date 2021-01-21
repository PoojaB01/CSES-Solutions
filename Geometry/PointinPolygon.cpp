// https://cses.fi/problemset/task/2192

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

void check(lli x[], lli y[], int n, lli X, lli Y)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        lli x1 = x[i], x2 = x[(i + 1) % n];
        lli y1 = y[i], y2 = y[(i + 1) % n];
        if (y1 > y2)
        {
            swap(y1, y2);
            swap(x1, x2);
        }
        lli cross = side(x1, y1, x2, y2, X, Y);
        if (min(y1, y2) <= Y && max(y1, y2) >= Y)
        {
            if (cross == 0 && min(x1, x2) <= X && max(x1, x2) >= X)
            {
                cout << "BOUNDARY" << endl;
                return;
            }
            else
            {
                if (cross > 0)
                {
                    if (y1 == Y)
                        continue;
                    count++;
                }
            }
        }
    }
    if (count % 2)
    {
        cout << "INSIDE" << endl;
    }
    else
        cout << "OUTSIDE" << endl;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    lli x[n], y[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    lli X, Y;
    for (int i = 0; i < m; i++)
    {
        cin >> X >> Y;
        check(x, y, n, X, Y);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q = 1;
    // cin >> q;
    while (q--)
        solve();
    return 0;
}