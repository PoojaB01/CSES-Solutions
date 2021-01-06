// https://cses.fi/problemset/view/1646/

#include <bits/stdc++.h>

using namespace std;

#define lli long long

int main()
{
    lli q = 1;
    // cin >> q;
    for (lli tc = 1; tc <= q; tc++)
    {
        lli n;
        cin >> n;
        lli Q;
        int l, r;
        cin >> Q;
        lli a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++)
        {
            a[i] += a[i - 1];
        }

        for (int i = 0; i < Q; i++)
        {
            cin >> l >> r;
            if (l != 1)
                cout << a[r - 1] - a[l - 2] << endl;
            else
                cout << a[r - 1] << endl;
        }
    }
    return 0;
}