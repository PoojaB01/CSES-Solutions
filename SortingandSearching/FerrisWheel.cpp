// https://cses.fi/problemset/task/1090

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int i = 0, j = n - 1, ans = 0;
    while (i <= j)
    {
        if (a[i] + a[j] <= x)
        {
            ans++;
            i++;
            j--;
        }
        else
        {
            ans++;
            j--;
        }
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}