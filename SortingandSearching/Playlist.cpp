// https://cses.fi/problemset/task/1141

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n;
    cin >> n;
    int a;
    map<int, int> m;
    int start = -1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (m.find(a) != m.end())
        {
            start = max(start, m[a]);
        }
        ans = max(ans, i - start);
        m[a] = i;
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