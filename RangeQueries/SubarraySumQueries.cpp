// https://cses.fi/problemset/task/1190

#include <bits/stdc++.h>

using namespace std;

#define lli long long

struct node
{
    lli prefix;
    lli suffix;
    lli sum;
    lli ans;
};

node tree[1000000];

node op(node a, node b)
{
    node ans;
    ans.sum = a.sum + b.sum;
    ans.prefix = max(a.prefix, a.sum + b.prefix);
    ans.suffix = max(b.suffix, b.sum + a.suffix);
    ans.ans = max(max(a.ans, b.ans), a.suffix + b.prefix);
    return ans;
}

void buildTree(vector<lli> &a, lli start, lli end, lli index)
{
    if (start == end)
    {
        tree[index].sum = a[start];
        tree[index].ans = max(0ll, a[start]);
        tree[index].prefix = max(0ll, a[start]);
        tree[index].suffix = max(0ll, a[start]);
        return;
    }
    lli mid = (start + end) / 2;
    buildTree(a, start, mid, 2 * index);
    buildTree(a, mid + 1, end, 2 * index + 1);
    tree[index] = op(tree[2 * index], tree[2 * index + 1]);
}

void updateTree(lli pos, lli value, lli start, lli end, lli index)
{
    if (start == end)
    {
        tree[index].sum = value;
        tree[index].ans = max(0ll, value);
        tree[index].prefix = max(0ll, value);
        tree[index].suffix = max(0ll, value);
        return;
    }
    lli mid = (start + end) / 2;
    if (pos <= mid)
        updateTree(pos, value, start, mid, 2 * index);
    else
        updateTree(pos, value, mid + 1, end, 2 * index + 1);
    tree[index] = op(tree[2 * index], tree[2 * index + 1]);
}

node queryTree(lli start, lli end, lli index, lli left, lli right)
{
    if (right < start || left > end)
    {
        return {0, 0, 0, 0};
    }
    if (start >= left and end <= right)
    {
        return tree[index];
    }

    lli mid = (start + end) / 2;
    return op(queryTree(start, mid, 2 * index, left, right),
              queryTree(mid + 1, end, 2 * index + 1, left, right));
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<lli> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    buildTree(a, 0, n - 1, 1);
    lli k, x;
    for (int i = 0; i < m; i++)
    {
        cin >> k >> x;
        k--;
        updateTree(k, x, 0, n - 1, 1);
        cout << queryTree(0, n - 1, 1, 0, n - 1).ans << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}