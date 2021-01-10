// https://cses.fi/problemset/task/1736
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long
#define MAXN 1000000
 
struct node
{
    lli sum;
    pair<lli, lli> update;
};
 
vector<node> tree(MAXN);
 
node op(node a, node b)
{
    return {a.sum + b.sum, {0, 0}};
}
 
lli sum(lli a)
{
    return (a * (a + 1)) / 2;
}
 
void push(lli start, lli end, lli index)
{
    if (start == end)
    {
        return;
    }
    lli mid = (start + end) / 2;
 
    tree[2 * index].update.first += tree[index].update.first;
    tree[2 * index].update.second += tree[index].update.second;
    tree[2 * index].sum += tree[index].update.first * (sum(mid) - sum(start - 1)) -
                           (mid - start + 1) * (tree[index].update.second);
 
    tree[2 * index + 1].update.first += tree[index].update.first;
    tree[2 * index + 1].update.second += tree[index].update.second;
    tree[2 * index + 1].sum += tree[index].update.first * (sum(end) - sum(mid)) -
                               (end - mid) * (tree[index].update.second);
 
    tree[index] = op(tree[2 * index], tree[2 * index + 1]);
}
 
void build(vector<lli> &a, lli start, lli end, lli index)
{
    if (start == end)
    {
        tree[index] = {a[start], {0, 0}};
        return;
    }
 
    lli mid = (start + end) / 2;
 
    build(a, start, mid, 2 * index);
    build(a, mid + 1, end, 2 * index + 1);
 
    tree[index] = op(tree[2 * index], tree[2 * index + 1]);
}
 
lli query(lli left, lli right, lli start, lli end, lli index)
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
    lli mid = (start + end) / 2;
    return (query(left, right, start, mid, 2 * index) +
            query(left, right, mid + 1, end, 2 * index + 1));
}
 
void update(lli left, lli right, lli start, lli end, lli index)
{
    push(start, end, index);
    if (right < start || left > end)
    {
        return;
    }
    if (start >= left and end <= right)
    {
        tree[index].update.first += 1;
        tree[index].update.second += left - 1;
        tree[index].sum += (sum(end) - sum(start - 1)) -
                           (end - start + 1) * (left - 1);
        return;
    }
    lli mid = (start + end) / 2;
    update(left, right, start, mid, 2 * index);
    update(left, right, mid + 1, end, 2 * index + 1);
    tree[index] = op(tree[2 * index], tree[2 * index + 1]);
}
 
void solve()
{
    lli n, q;
    cin >> n >> q;
    vector<lli> c(n), a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        if (i)
            c[i] += c[i - 1];
    }
    build(a, 0, n - 1, 1);
    lli k, x, y;
    for (int i = 0; i < q; i++)
    {
        cin >> k;
        switch (k)
        {
        case 1:
            cin >> x >> y;
            update(x - 1, y - 1, 0, n - 1, 1);
            break;
        case 2:
            cin >> x >> y;
            cout << c[y - 1] + query(x - 1, y - 1, 0, n - 1, 1) - (x > 1 ? c[x - 2] : 0) << endl;
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