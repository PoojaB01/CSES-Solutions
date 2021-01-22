// https://cses.fi/problemset/task/2185

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    lli n;
    cin >> n;
    int k;
    cin >> k;
    lli a[k];
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    lli ans = 0;
    for (int i = 1; i < pow(2, k); i++)
    {
        int count = 0;
        lli prod = 1;
        for (int j = 0; j < k; j++)
        {
            if (i & 1 << j)
            {
                count++;
                if (prod > n / a[j] + 1)
                {
                    prod = n + 1;
                    break;
                }
                prod = prod * a[j];
            }
        }
        ans += (lli)pow(-1, count + 1) * (n / prod);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli q = 1;
    // cin >> q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}