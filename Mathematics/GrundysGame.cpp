// https://cses.fi/problemset/task/2207

#include <bits/stdc++.h>

using namespace std;

#define lli long long
#define MAXN 2001

vector<int> G(MAXN, -1);

int grundy(int n)
{
    if (G[n] != -1)
        return G[n];
    vector<bool> vis(n + 1, false);
    for (int i = 1; i < (n + 1) / 2; i++)
    {
        vis[grundy(i) ^ grundy(n - i)] = true;
    }
    int ans = 0;
    while (vis[ans])
        ans++;
    G[n] = ans;
    return G[n];
}

void solve()
{
    int n;
    cin >> n;
    if (n < MAXN)
        cout << (G[n] ? "first" : "second") << endl;
    else
        cout << "first" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    grundy(MAXN - 1);
    int q = 1;
    cin >> q;
    while (q--)
        solve();
    return 0;
}