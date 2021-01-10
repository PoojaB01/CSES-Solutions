// https://cses.fi/problemset/task/2206

#include <bits/stdc++.h>

using namespace std;

#define lli long long
lli MAX = 1e10;

struct node
{
    lli right, left;
};

node tree[1000000];

node op(node a, node b)
{
    node res = {min(a.right, b.right), min(a.left, b.left)};
    return res;
}

void buildTree(vector<lli> a, lli n)
{
    for (lli i = 0; i < n; i++)
        tree[n + i] = {a[i] + i, a[i] - i};
    for (lli i = n - 1; i > 0; i--)
    {
        tree[i] = op(tree[i << 1], tree[i << 1 | 1]);
    }
}

void updateTree(lli n, lli p, lli value)
{
    tree[p + n] = {value + p, value - p};
    p += n;
    for (lli i = p; i > 1; i >>= 1)
        tree[i >> 1] = op(tree[i], tree[i ^ 1]);
}

node queryTree(lli n, lli l, lli r)
{
    r++;
    node res = {MAX, MAX};
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = op(res, tree[l++]);
        if (r & 1)
            res = op(res, tree[--r]);
    }
    return res;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<lli> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    buildTree(a, n);
    lli c, x, y;
    for (int i = 0; i < q; i++)
    {
        cin >> c;
        if (c == 1)
        {
            cin >> x >> y;
            updateTree(n, x - 1, y);
        }
        else
        {
            cin >> x;
            cout << min(queryTree(n, 0, x - 1).left + x - 1, queryTree(n, x - 1, n - 1).right - (x - 1)) << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}