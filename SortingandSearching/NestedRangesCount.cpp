// https://cses.fi/problemset/task/2169

#include <bits/stdc++.h>

using namespace std;

#define lli long long
#define MAXN 2000006

bool compare(pair<pair<int, int>,int> &a, pair<pair<int, int>, int> &b)
{
    if (a.first.first < b.first.first)
        return true;
    else if (a.first.first == b.first.first)
        return b.first.second < a.first.second;
    else
        return false;
}

int tree[MAXN];

void buildTree(vector<int> a, int n)
{
    for (int i = 0; i < n; i++)
        tree[n + i] = a[i];
    for (int i = n - 1; i > 0; i--)
    {
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
}

void updateTree(int n, int p, int value)
{
    tree[p + n] += value;
    p += n;
    for (int i = p; i > 1; i >>= 1)
        tree[i >> 1] = tree[i] + tree[i ^ 1];
}

int queryTree(int n, int l, int r)
{
    r++;
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

void solve()
{
    int n;
    cin >> n;
    int x, y;
    vector<pair<pair<int, int>, int>> v;
    vector<int> values, m;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back({{x, y}, i});
        values.push_back(x);
        values.push_back(y);
    }
    sort(values.begin(), values.end());
    m.push_back(values[0]);
    for (int i = 1; i < values.size(); i++)
    {
        if (m.back() != values[i])
        {
            m.push_back(values[i]);
        }
    }
    int size = m.size();

    sort(v.begin(), v.end(), compare);

    vector<int> a(n, 0), b(n, 0);

    vector<int> count(size, 0);
    buildTree(count, size);
    for (int i = 0; i < n; i++)
    {
        x = lower_bound(m.begin(), m.end(), v[i].first.second) - m.begin();
        b[v[i].second] = queryTree(size, x, size - 1);
        updateTree(size, x, 1);
    }
    count.assign(size, 0);
    buildTree(count, size);
    for (int i = n - 1; i >= 0; i--)
    {
        x = lower_bound(m.begin(), m.end(), v[i].first.second) - m.begin();
        a[v[i].second] = queryTree(size, 0, x);
        updateTree(size, x, 1);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << ' ';
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