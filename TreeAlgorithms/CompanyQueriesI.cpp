// https://cses.fi/problemset/task/1687

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, q;
    cin >> n >> q;
    int x;
    int p[24][n + 1];
    p[0][0] = 0;
    p[0][1] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> x;
        p[0][i + 2] = x;
    }

    int k = 1;

    for (int k = 1; k < 24; k++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            p[k][j] = p[k - 1][p[k - 1][j]];
        }
    }

    for (int i = 0; i < q; i++)
    {
        cin >> x >> k;
        int j = 0;
        while (k)
        {
            if (k % 2)
            {
                x = p[j][x];
            }
            j++;
            k /= 2;
        }
        cout << (x ? x : -1) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}