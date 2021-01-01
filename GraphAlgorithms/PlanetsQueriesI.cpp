// https://cses.fi/problemset/task/1750

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, q;
    cin >> n >> q;
    int next[n][32];
    for (int i = 0; i < n; i++)
    {
        cin >> next[i][0];
        next[i][0]--;
    }
    for (int i = 1; i < 32; i++)
    {
        for (int j = 0; j < n; j++)
        {
            next[j][i] = next[next[j][i - 1]][i - 1];
        }
    }
    for (int i = 0; i < q; i++)
    {
        int x, k;
        cin >> x >> k;
        x--;
        for (int j = 0; j < 32; j++)
        {
            if (k & 1)
            {
                x = next[x][j];
            }
            k /= 2;
        }
        cout << x + 1 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}