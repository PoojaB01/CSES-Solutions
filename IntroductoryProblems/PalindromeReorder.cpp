// https://cses.fi/problemset/task/1755

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    string s;
    cin >> s;
    string ans = s;
    int j = 0;
    int n = s.length();
    set<char> t;
    for (int i = 0; i < n; i++)
    {
        if (t.find(s[i]) == t.end())
        {
            t.insert(s[i]);
        }
        else
        {
            ans[j] = s[i];
            ans[n - j - 1] = s[i];
            j++;
            t.erase(s[i]);
        }
    }
    if (t.size() > 1)
        cout << "NO SOLUTION";
    else
    {
        if (t.size())
            ans[j] = *t.begin();
        cout << ans;
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