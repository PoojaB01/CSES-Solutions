// https://cses.fi/problemset/task/1133

#include <bits/stdc++.h>

using namespace std;

#define lli long long

int calc_size(int x, vector<int> v[], vector<int> &vi, vector<int> &siz)
{
    vi[x] = 0;
    int t = 1;
    for (int i = 0; i < (int)v[x].size(); i++)
    {
        if (vi[v[x][i]])
        {
            t += calc_size(v[x][i], v, vi, siz);
        }
    }
    siz[x] = t;
    return t;
}

void assign(int x, vector<int> v[], vector<int> &vi, vector<int> &siz, vector<lli> &ans, int n)
{
    vi[x] = 0;
    for (int i = 0; i < (int)v[x].size(); i++)
    {
        if (vi[v[x][i]])
        {
            ans[v[x][i]] = ans[x] + n - 2 * siz[v[x][i]];
            assign(v[x][i], v, vi, siz, ans, n);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    int x, y;
    vector<int> v[n];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        v[x - 1].push_back(y - 1);
        v[y - 1].push_back(x - 1);
    }

    vector<int> vi(n, 1);
    vector<int> siz(n, 0);
    calc_size(0, v, vi, siz);

    vector<lli> ans(n, 0);
    for (int i = 1; i < n; i++)
    {
        ans[0] += siz[i];
    }
    vi.assign(n, 1);
    assign(0, v, vi, siz, ans, n);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
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