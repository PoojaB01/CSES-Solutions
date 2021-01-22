// https://cses.fi/problemset/task/2208

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n;
    cin >> n;
    lli x;
    bool odd = false;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        odd = odd | (x % 2);
    }
    cout << (odd ? "first" : "second") << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q = 1;
    cin >> q;
    while (q--)
        solve();
    return 0;
}