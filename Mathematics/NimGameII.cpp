// https://cses.fi/problemset/task/1098

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x = x ^ a[i];
    }
    if ((x & 3) == 0)
        cout << "second" << endl;
    else
        cout << "first" << endl;
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