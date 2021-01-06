// https://cses.fi/problemset/task/1651

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
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
}

void updateTree(lli n, lli p, lli value)
{
    tree[p + n] += value;
    p += n;
    for (lli i = p; i > 1; i >>= 1)
        tree[i >> 1] = tree[i] + tree[i ^ 1];
}

lli queryTree(lli n, lli l, lli r)
{
    lli res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res += tree[l++];
        if (r & 1)
            res += tree[--r];
    }
    return res;
}

int main()
{
    lli q = 1;
    // cin >> q;

    for (lli tc = 1; tc <= q; tc++)
    {
        lli n, t;
        cin >> n >> t;
        vector<lli> a(n + 1, 0);
        buildTree(a, n + 1);
        lli b[n];
        for (lli i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        lli c, A, B, U;
        for (lli i = 0; i < t; i++)
        {
            cin >> c;
            if (c == 1)
            {
                cin >> A >> B >> U;
                updateTree(n + 1, A - 1, U);
                updateTree(n + 1, B, -U);
            }
            else
            {
                cin >> U;
                lli x = queryTree(n + 1, 0, U);
                cout << b[U - 1] + x << endl;
            }
        }

    end:;
    }
    return 0;
}