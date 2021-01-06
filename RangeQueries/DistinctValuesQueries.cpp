// https://cses.fi/problemset/task/1734
// Merge Sort Tree

#include <bits/stdc++.h>

using namespace std;

#define lli long long
#define MAXN 1000000

vector<int> tree[MAXN];

vector<int> merge(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    vector<int> v;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
            v.push_back(a[i++]);
        else
            v.push_back(b[j++]);
    }
    while (i < n)
    {
        v.push_back(a[i++]);
    }
    while (j < m)
    {
        v.push_back(b[j++]);
    }
    return v;
}

void build(vector<int> &a, int start, int end, int index)
{
    if (start == end)
    {
        tree[index].push_back(a[start]);
        return;
    }

    int mid = (start + end) / 2;

    build(a, start, mid, 2 * index);
    build(a, mid + 1, end, 2 * index + 1);

    tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
}

int query(int left, int right, int k, int start, int end, int index)
{
    if (right < start || left > end)
    {
        return 0;
    }
    if (start >= left and end <= right)
    {
        return (tree[index].end() - upper_bound(tree[index].begin(), tree[index].end(), k));
    }

    int mid = (start + end) / 2;
    return (query(left, right, k, start, mid, 2 * index) +
            query(left, right, k, mid + 1, end, 2 * index + 1));
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n, n + 1);
    int x, y;
    map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (m.find(x) != m.end())
        {
            a[m[x]] = i;
        }
        m[x] = i;
    }

    build(a, 0, n - 1, 1);

    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        cout << query(x, y, y, 0, n - 1, 1) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lli q = 1;
    // cin>>q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}