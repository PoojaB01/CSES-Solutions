// https://cses.fi/problemset/task/1110
// Booth's Algorithm

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    string s;
    cin >> s;
    int n = s.length();

    s = s + s;

    vector<int> f(2 * n, -1);

    int k = 0;

    for (int i = 1; i < 2 * n; i++)
    {
        char c = s[i];
        int j = f[i - k - 1];
        while (j != -1 && c != s[k + j + 1])
        {
            if (c < s[k + j + 1])
            {
                k = i - j - 1;
            }
            j = f[j];
        }
        if (c != s[k + j + 1])
        {
            if (c < s[k])
                k = i;
            f[i - k] = -1;
        }
        else
            f[i - k] = j + 1;
    }
    cout << s.substr(k % n, n) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}