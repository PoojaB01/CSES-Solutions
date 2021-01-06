// https://cses.fi/problemset/task/1650

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    t = 1;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n + 1];
        a[0] = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i + 1];
            a[i + 1] = a[i + 1] ^ a[i];
        }
        int l, r;
        for (int i = 0; i < k; i++)
        {
            cin >> l >> r;
            cout << (a[r] ^ a[l - 1]) << endl;
        }
    }
    return 0;
}