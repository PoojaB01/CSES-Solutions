// https://cses.fi/problemset/task/1732

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli MOD = 1e9 + 7;

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
    string s;
    cin >> s;
    int n = s.length();

    vector<int> lps(n, 0);
    computeLPS(s, n, lps);

    int len = lps[n - 1];

    vector<int> ans;

    while (len != 0)
    {
        ans.push_back(len);
        len = lps[len - 1];
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans)
    {
        cout << i << ' ';
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}