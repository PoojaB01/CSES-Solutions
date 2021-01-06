// https://cses.fi/problemset/task/1749

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli tree[1000000];

lli op(lli a, lli b)
{
    return a + b;
}

void buildTree(vector<lli> a, lli n)
{
    for (lli i = 0; i < n; i++)
        tree[n + i] = a[i];
    for (lli i = n - 1; i > 0; i--)
    {
        tree[i] = op(tree[i << 1], tree[i << 1 | 1]);
    }
}

void updateTree(lli n, lli p, lli value)
{
    tree[p + n] = value;
    p += n;
    for (lli i = p; i > 1; i >>= 1)
        tree[i >> 1] = op(tree[i], tree[i ^ 1]);
}

lli queryTree(lli n, lli l, lli r)
{
    r++;
    lli res = 0;
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
    int n;
    cin >> n;
    vector<lli> index(n, 0);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    buildTree(index, n);
    int p, start, end, mid, removed, pos;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        p--;
        start = 0, end = n - 1;
        while (start <= end)
        {
            mid = (start + end) / 2;
            removed = queryTree(n, 0, mid);
            if (mid - removed == p)
                pos = mid;
            if (mid - removed >= p)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        cout << a[pos] << ' ';
        updateTree(n, pos, 1);
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