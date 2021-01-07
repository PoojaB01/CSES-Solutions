// https://cses.fi/problemset/task/2428

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int j = 0;
    lli ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (m.find(v[i]) == m.end())
            m[v[i]] = 0;
        m[v[i]]++;
        while (m.size() > k)
        {
            m[v[j]]--;
            if (m[v[j]] == 0)
                m.erase(m.find(v[j]));
            j++;
        }
        ans += i - j + 1;
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