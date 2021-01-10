// https://cses.fi/problemset/task/1139

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

int d = 0;

int preorder(int x, int p, vector<int> e[], vector<pair<pair<int, int>, int>> &q, vector<int> &pre, int &k)
{
    pre[k++] = x;
    int t = 0;
    for (auto i : e[x])
    {
        if (i != p)
        {
            t += preorder(i, x, e, q, pre, k);
        }
    }
    q.push_back({{k - t - 1, k - 1}, x});
    return t + 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> c(n);
    map<int, int> m;
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    d = sqrt(n);

    vector<int> e[n];
    int x, y;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        e[x - 1].push_back(y - 1);
        e[y - 1].push_back(x - 1);
    }

    vector<pair<pair<int, int>, int>> q;
    vector<int> pre(n);
    vector<int> a(n, n + 1);
    m.clear();

    k = 0;
    preorder(0, 0, e, q, pre, k);
    for (int i = 0; i < n; i++)
    {
        x = c[pre[i]];
        if (m.find(x) != m.end())
        {
            a[m[x]] = i;
        }
        m[x] = i;
    }
    build(a, 0, n - 1, 1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        ans[q[i].second] = query(q[i].first.first, q[i].first.second, q[i].first.second, 0, n - 1, 1);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
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