// https://cses.fi/problemset/task/1649

#include <bits/stdc++.h>

using namespace std;

#define lli long long

#define MAXN 2000006

lli tree[MAXN];

void buildTree(vector<lli> a, int n)
{
    for (int i = 0; i < n; i++)
        tree[n + i] = a[i];
    for (int i = n - 1; i > 0; i--)
    {
        tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    }
}

void updateTree(int n, int p, lli value)
{
    tree[p + n] = value;
    p += n;
    for (int i = p; i > 1; i >>= 1)
        tree[i >> 1] = min(tree[i], tree[i ^ 1]);
}

lli queryTree(int n, int l, int r)
{
    lli res = INT_MAX;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = min(res, tree[l++]);
        if (r & 1)
            res = min(res, tree[--r]);
    }
    return res;
}


int main()
{
    lli q = 1;
    // cin >> q;

    for (lli tc = 1; tc <= q; tc++)
    {
        int n, t;
        cin >> n >> t;
        vector<lli> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        buildTree(a, n);
        lli c, A, B;
        for (int i = 0; i < t; i++)
        {
            cin >> c >> A >> B;
            if (c == 2)
                cout << queryTree(n, A - 1, B) << endl;
            if (c == 1)
                updateTree(n, A - 1, B);
        }

    end:;
    }
    return 0;
}