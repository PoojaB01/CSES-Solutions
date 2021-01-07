// https://cses.fi/problemset/task/2162

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n;
    cin >> n;
    int next[n];
    for (int i = 0; i < n; i++)
    {
        next[i] = (i + 1) % n;
    }
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        cout << next[k] + 1 << ' ';
        next[k] = next[next[k]];
        k = next[k];
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