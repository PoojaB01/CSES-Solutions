// https://cses.fi/problemset/task/1753
// KMP Algorithm

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void computeLPS(string &s, int n, vector<int> &lps)
{
    lps[0] = 0;
    int len = 0;
    for (int i = 1; i < n; i++)
    {
        len = lps[i - 1];
        while(1)
        {
            if (s[i] == s[len])
            {
                len++;
                break;
            }
            if (len)
                len = lps[len - 1];
            else
                break;
        }
    
        lps[i] = len;
    }
}

void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    vector<int> t_lps(m, 0);
    computeLPS(t, m, t_lps);

    int len = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            if (s[i] == t[len])
            {
                len++;
                break;
            }
            if (len)
                len = t_lps[len - 1];
            else
                break;
        }
        if (len == m)
        {
            ans++;
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