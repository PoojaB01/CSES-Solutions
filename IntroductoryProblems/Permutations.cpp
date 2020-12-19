// https://cses.fi/problemset/task/1070

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    if (n == 4)
    {
        cout << "2 4 1 3" << endl;
        return;
    }
    if (n < 5)
    {
        cout << "NO SOLUTION" << endl;
        return;
    }
    int a[n];
    if (n % 2)
    {
        a[0] = n / 2 + 1;
        for (int i = 0; i < n / 2; i++)
        {
            a[2 * i + 1] = n - i;
            a[2 * i + 2] = n - i - n / 2 - 1;
        }
    }
    else
    {
        for (int i = 0; i < n / 2; i++)
        {
            a[2 * i] = n - i;
            a[2 * i + 1] = n - i - n / 2;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli q = 1;
    // cin>>q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}