// https://cses.fi/problemset/task/1652

#include <bits/stdc++.h>

using namespace std;

#define lli long long

int main()
{
    lli q = 1;
    // cin >> q;

    for (lli tc = 1; tc <= q; tc++)
    {
        int n, t;
        cin >> n >> t;
        int m = n;
        int a[n + 1][m + 1];
        for (int i = 0; i < n + 1; i++)
        {
            a[i][0] = 0;
        }
        for (int i = 0; i < m + 1; i++)
        {
            a[0][i] = 0;
        }
        char c;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> c;
                a[i + 1][j + 1] = c == '*' ? 1 : 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i + 1][j + 1] += a[i + 1][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i + 1][j + 1] += a[i][j + 1];
            }
        }
        int x, y, z, w;
        for (int i = 0; i < t; i++)
        {
            cin >> x >> y >> z >> w;
            cout << a[z][w] - a[z][y - 1] - a[x - 1][w] + a[x - 1][y - 1] << endl;
        }
    end:;
    }
    return 0;
}