// https://cses.fi/problemset/task/1085

#include <bits/stdc++.h>

using namespace std;

#define lli long long

bool check(int a[], lli mid, int k, int n)
{
    lli sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mid)
        {
            return false;
        }
        else if (sum + a[i] > mid)
        {
            sum = a[i];
            k--;
        }
        else
            sum += a[i];
    }
    return k > 0;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lli start = 1, end = 2 * 1e14, mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        bool t = check(a, mid, k, n), f = check(a, mid - 1, k, n);
        if (t && !f)
        {
            cout << mid << endl;
            return;
        }
        else if (!t)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}