// https://cses.fi/problemset/task/2164

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli JosephusQueries(lli n, lli k, lli offset)
{
    int d = (n + offset) / 2;
    if (k > d)
    {
        if (n % 2 != offset)
            return 2 * JosephusQueries(n - d, k - d, 1) - 1 + offset;
        else
            return 2 * JosephusQueries(n - d, k - d, 0) - 1 + offset;
    }
    else
    {
        return 2 * k - offset;
    }
}

void solve()
{
    lli n, k;
    cin >> n >> k;
    cout << JosephusQueries(n, k, 0) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli q = 1;
    cin >> q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}