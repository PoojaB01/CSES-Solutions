// https://cses.fi/problemset/task/1143

#include <bits/stdc++.h>

using namespace std;

#define lli long long
#define MAXN 2000006

lli tree[MAXN];

void buildTree(vector<lli> a, lli n)
{
    for (lli i = 0; i < n; i++)
        tree[n + i] = a[i];
    for (lli i = n - 1; i > 0; i--)
    {
        tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }
}

void updateTree(lli n, lli p, lli value)
{
    tree[p + n] = tree[p + n] - value;
    p += n;
    for (lli i = p; i > 1; i >>= 1)
        tree[i >> 1] = max(tree[i], tree[i ^ 1]);
}

lli queryTree(lli n, lli l, lli r)
{
    lli res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = max(res, tree[l++]);
        if (r & 1)
            res = max(res, tree[--r]);
    }
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<lli> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    buildTree(a, n);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        int start = 0, end = n - 1, mid, ans = 0;
        while (start <= end)
        {
            mid = start + end;
            mid /= 2;
            if (queryTree(n, 0, mid + 1) < b[i])
            {
                start = mid + 1;
            }
            else
            {
                ans = mid + 1;
                end = mid - 1;
            }
        }
        cout << ans << ' ';
        if (ans)
            updateTree(n, ans - 1, b[i]);
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli q = 1;
    // cin >> q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}