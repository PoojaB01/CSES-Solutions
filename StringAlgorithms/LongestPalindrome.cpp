// https://cses.fi/problemset/task/1111
// Manacher's Algorithm

#include <bits/stdc++.h>

using namespace std;

#define lli long long

string manacher(string s)
{
    int n = s.length();

    int center = -1, length = -1;

    // odd palindromes
    vector<int> op(n, 1);
    int c = 0, l = 1;
    for (int i = 0; i < n; i++)
    {
        if (i < c + l)
        {
            op[i] = min(op[c - (i - c)], l - (i - c));
        }
        while (i - op[i] >= 0 && i + op[i] < n && s[i + op[i]] == s[i - op[i]])
            op[i]++;
        if (i + op[i] > c + l)
        {
            c = i;
            l = op[i];
        }

        if (2 * op[i] - 1 > length)
        {
            length = 2 * op[i] - 1;
            center = i;
        }
    }

    // even palindromes
    vector<int> ep(n - 1, 0);
    c = 0;
    l = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (i < c + l)
        {
            ep[i] = min(ep[c - (i - c)], l - (i - c));
        }
        while (i - ep[i] >= 0 && i + ep[i] + 1 < n && s[i + ep[i] + 1] == s[i - ep[i]])
            ep[i]++;
        if (i + ep[i] > c + l)
        {
            c = i;
            l = ep[i];
        }

        if (2 * ep[i] > length)
        {
            length = 2 * ep[i];
            center = i;
        }
    }

    if (length % 2)
    {
        return s.substr(center - length / 2, length);
    }
    else
        return s.substr(center - length / 2 + 1, length);
}

void solve()
{
    string s;
    cin >> s;
    cout << manacher(s) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}