// https://cses.fi/problemset/task/1737

#include <bits/stdc++.h>

using namespace std;

#define lli long long
#define MAXN 1000000

struct node
{
    node *l, *r;
    lli sum;

    node(lli v) : l(nullptr), r(nullptr), sum(v) {}
    node(node *a, node *b) : l(a), r(b), sum(0)
    {
        if (l)
            sum += l->sum;
        if (r)
            sum += r->sum;
    }
};

node *buildTree(vector<lli> &a, int start, int end)
{
    if (start == end)
    {
        return new node(a[start]);
    }
    int mid = (start + end) / 2;
    return new node(buildTree(a, start, mid), buildTree(a, mid + 1, end));
}

lli queryTree(node *a, int left, int right, int start, int end)
{
    if (!a)
        return 0;
    if (right < start || left > end)
    {
        return 0;
    }
    if (start >= left and end <= right)
    {
        return a->sum;
    }
    int mid = (start + end) / 2;
    return (queryTree(a->l, left, right, start, mid) +
            queryTree(a->r, left, right, mid + 1, end));
}

node *updateTree(node *a, int pos, lli v, lli start, lli end)
{
    if (!a)
        return NULL;
    if (pos < start || pos > end)
    {
        return a;
    }
    if(start == end)
    {
        return new node(v);
    }
    int mid = (start + end) / 2;
    return new node(updateTree(a->l, pos, v, start, mid),
                    updateTree(a->r, pos, v, mid + 1, end));
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
    vector<node *> root(MAXN, NULL);
    root[1] = buildTree(a, 0, n - 1);
    lli c, k, x, y;
    int size = 2;
    for (int i = 0; i < q; i++)
    {
        cin >> c >> k;
        switch (c)
        {
        case 1:
            cin >> x >> y;
            root[k] = updateTree(root[k], x - 1, y, 0, n - 1);
            break;
        case 2:
            cin >> x >> y;
            cout << queryTree(root[k], x - 1, y - 1, 0, n - 1) << endl;
            break;
        case 3:
            root[size++] = root[k];
            break;
        }
    }
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