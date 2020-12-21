// https://cses.fi/problemset/task/1622

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    string s;
    cin >> s;
    vector<string> ans;
    sort(s.begin(), s.end());
    string t = s;
    while (1)
    {
        ans.push_back(t);
        next_permutation(t.begin(), t.end());
        if (t == s)
            break;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
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