// https://cses.fi/problemset/task/1624

#include <bits/stdc++.h>

using namespace std;

#define lli long long

vector<bool> c(8, true), d1(15, true), d2(15, true);

int count(string s[], int x)
{
    if (x == 8)
        return 1;
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        if (s[x][i] == '.')
        {
            if (c[i] && d1[i + x] && d2[i - x + 7])
            {
                c[i] = false;
                d1[i + x] = false;
                d2[i - x + 7] = false;
                cnt += count(s, x + 1);
                c[i] = true;
                d1[i + x] = true;
                d2[i - x + 7] = true;
            }
        }
    }
    return cnt;
}

void solve()
{
    string s[8];
    for (int i = 0; i < 8; i++)
    {
        cin >> s[i];
    }
    cout << count(s, 0);
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