// https://cses.fi/problemset/task/1625

#include <bits/stdc++.h>

using namespace std;

#define lli long long

int count(string &s, int i, int x, int y, vector<vector<bool>> &v)
{
    if (x < 1 || x > 7 || y < 1 || y > 7)
        return 0;
    if (v[x][y])
        return 0;
    if (x == 1 && y == 7 && i != 48)
        return 0;
    if (i == 48)
    {
        if (x == 1 && y == 7)
            return 1;
        else
            return 0;
    }
    int cnt = 0;
    v[x][y] = true;
    switch (s[i])
    {
    case 'R':
        cnt += (((!v[x - 1][y] && v[x][y + 1] && v[x][y - 1]) || v[x + 1][y]) ? 0 : count(s, i + 1, x + 1, y, v));
        break;
    case 'L':
        cnt += (((!v[x + 1][y] && v[x][y + 1] && v[x][y - 1]) || v[x - 1][y]) ? 0 : count(s, i + 1, x - 1, y, v));
        break;
    case 'U':
        cnt += (((!v[x][y + 1] && v[x - 1][y] && v[x + 1][y]) || v[x][y - 1]) ? 0 : count(s, i + 1, x, y - 1, v));
        break;
    case 'D':
        cnt += (((!v[x][y - 1] && v[x - 1][y] && v[x + 1][y]) || v[x][y + 1]) ? 0 : count(s, i + 1, x, y + 1, v));
        break;
    case '?':
        cnt += (((!v[x - 1][y] && v[x][y + 1] && v[x][y - 1]) || v[x + 1][y]) ? 0 : count(s, i + 1, x + 1, y, v));
        cnt += (((!v[x + 1][y] && v[x][y + 1] && v[x][y - 1]) || v[x - 1][y]) ? 0 : count(s, i + 1, x - 1, y, v));
        cnt += (((!v[x][y + 1] && v[x - 1][y] && v[x + 1][y]) || v[x][y - 1]) ? 0 : count(s, i + 1, x, y - 1, v));
        cnt += (((!v[x][y - 1] && v[x - 1][y] && v[x + 1][y]) || v[x][y + 1]) ? 0 : count(s, i + 1, x, y + 1, v));
        break;
    }
    v[x][y] = false;
    return cnt;
}

void solve()
{
    string s;
    cin >> s;
    vector<vector<bool>> v(9, vector<bool>(9, false));
    for (int i = 0; i < 9; i++)
    {
        v[0][i] = true;
        v[i][0] = true;
        v[8][i] = true;
        v[i][8] = true;
    }
    cout << count(s, 0, 1, 1, v) << endl;
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