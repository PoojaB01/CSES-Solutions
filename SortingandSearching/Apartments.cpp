// https://cses.fi/problemset/task/1084

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int b[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    int i = 0, j = 0, ans = 0;
    while (i < n && j < m)
    {
        if (b[j] <= a[i] + k && b[j] >= a[i] - k)
        {
            i++;
            j++;
            ans++;
        }
        else if (b[j] > a[i] + k)
        {
            i++;
        }
        else
        {
            j++;
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