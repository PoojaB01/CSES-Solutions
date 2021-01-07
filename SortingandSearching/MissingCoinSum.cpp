// https://cses.fi/problemset/task/2183

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n;
    cin >> n;
    vector<lli> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    lli sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i] > sum + 1)
        {
            cout << sum + 1 << endl;
            return;
        }
        sum += c[i];
    }
    cout << sum + 1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}