// https://cses.fi/problemset/task/1069

#include <bits/stdc++.h>

using namespace std;

#define lli long long

int main()
{
    string s;
    cin >> s;

    int ans = 1;
    int k = 1;

    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == s[i + 1])
            k++;
        else
        {
            ans = max(ans, k);
            k = 1;
        }
    }
    
    cout << max(k, ans) << endl;

    return 0;
}