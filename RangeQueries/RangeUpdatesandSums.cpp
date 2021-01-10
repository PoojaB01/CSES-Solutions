// https://cses.fi/problemset/task/1735

#include <bits/stdc++.h>

using namespace std;

#define lli long long
#define MAXN 1000000

struct node
{
    lli sum;
    pair<bool, lli> inc;
    pair<bool, lli> se;
};

vector<node> tree(MAXN);

node op(node a, node b)
{
    return {a.sum + b.sum, {false, 0}, {false, 0}};
}

void push(int start, int end, int index)
{
    if (start == end)
    {
        return;
    }
    int mid = (start + end) / 2;
    if (tree[index].inc.first)
    {
        if (tree[2 * index].se.first)
        {
            tree[2 * index].se.second += tree[index].inc.second;
            tree[2 * index].sum += tree[index].inc.second * (mid - start + 1);
        }
        else
        {
            tree[2 * index].inc.first = true;
            tree[2 * index].inc.second += tree[index].inc.second;
            tree[2 * index].sum += tree[index].inc.second * (mid - start + 1);
        }
        if (tree[2 * index + 1].se.first)
        {
            tree[2 * index + 1].se.second += tree[index].inc.second;
            tree[2 * index + 1].sum += tree[index].inc.second * (end - mid);
        }
        else
        {
            tree[2 * index + 1].inc.first = true;
            tree[2 * index + 1].inc.second += tree[index].inc.second;
            tree[2 * index + 1].sum += tree[index].inc.second * (end - mid);
        }
    }
    if (tree[index].se.first)
    {
        tree[2 * index].se.first = true;
        tree[2 * index].inc = {false, 0};
        tree[2 * index].se.second = tree[index].se.second;
        tree[2 * index].sum = (mid - start + 1) * tree[index].se.second;
        tree[2 * index + 1].se.first = true;
        tree[2 * index + 1].inc = {false, 0};
        tree[2 * index + 1].se.second = tree[index].se.second;
        tree[2 * index + 1].sum = (end - mid) * tree[index].se.second;
    }
    tree[index] = op(tree[2 * index], tree[2 * index + 1]);
}

void build(vector<int> &a, int start, int end, int index)
{
    if (start == end)
    {
        tree[index] = {a[start], {false, 0}, {false, 0}};
        return;
    }

    int mid = (start + end) / 2;

    build(a, start, mid, 2 * index);
    build(a, mid + 1, end, 2 * index + 1);

    tree[index] = op(tree[2 * index], tree[2 * index + 1]);
}

lli query(int left, int right, int start, int end, int index)
{
    push(start, end, index);
    if (right < start || left > end)
    {
        return 0;
    }
    if (start >= left and end <= right)
    {
        return tree[index].sum;
    }
    int mid = (start + end) / 2;
    return (query(left, right, start, mid, 2 * index) +
            query(left, right, mid + 1, end, 2 * index + 1));
}

void updateIncr(int left, int right, int start, int end, int index, lli k)
{
    push(start, end, index);
    if (right < start || left > end)
    {
        return;
    }
    if (start >= left and end <= right)
    {
        tree[index].sum += k * (end - start + 1);
        tree[index].inc = {true, k};
        return;
    }
    int mid = (start + end) / 2;
    updateIncr(left, right, start, mid, 2 * index, k);
    updateIncr(left, right, mid + 1, end, 2 * index + 1, k);
    tree[index] = op(tree[2 * index], tree[2 * index + 1]);
}

void updateSet(int left, int right, int start, int end, int index, lli k)
{
    push(start, end, index);
    if (right < start || left > end)
    {
        return;
    }
    if (start >= left and end <= right)
    {
        tree[index].sum = k * (end - start + 1);
        tree[index].se = {true, k};
        return;
    }
    int mid = (start + end) / 2;
    updateSet(left, right, start, mid, 2 * index, k);
    updateSet(left, right, mid + 1, end, 2 * index + 1, k);
    tree[index] = op(tree[2 * index], tree[2 * index + 1]);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(a, 0, n - 1, 1);
    lli k, x, y, z;
    for (int i = 0; i < q; i++)
    {
        cin >> k;
        switch (k)
        {
        case 1:
            cin >> x >> y >> z;
            updateIncr(x - 1, y - 1, 0, n - 1, 1, z);
            break;
        case 2:
            cin >> x >> y >> z;
            updateSet(x - 1, y - 1, 0, n - 1, 1, z);
            break;
        case 3:
            cin >> x >> y;
            cout << query(x - 1, y - 1, 0, n - 1, 1) << endl;
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