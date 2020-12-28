// https://cses.fi/problemset/task/1081

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, x;
    cin >> n;
    vector<int> c(1000003, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        c[x]++;
    }
    for (int i = 1000003; i > 0; i--)
    {
        int cnt = 0;
        for (int j = i; j < 1000003; j += i)
        {
            cnt += c[j];
            if (cnt > 1)
            {
                cout << i << endl;
                return;
            }
        }
    }
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