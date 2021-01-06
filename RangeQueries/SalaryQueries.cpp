// https://cses.fi/problemset/task/1144

#include <bits/stdc++.h>

using namespace std;

#define lli int
lli tree[1500000];

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
    tree[p + n] += value;
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
    int n, q;
    cin >> n >> q;
    vector<int> p(n, 0), values, m;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        values.push_back(p[i]);
    }
    char c;
    lli a, b;
    vector<pair<char, pair<int, int>>> queries;
    for (int i = 0; i < q; i++)
    {
        cin >> c;
        cin >> a >> b;
        if (c == '!')
        {
            values.push_back(b);
        }
        else
        {
            values.push_back(a);
            values.push_back(b);
        }
        queries.push_back({c, {a, b}});
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

    vector<lli> count(size, 0);
    int index;
    for (int i = 0; i < n; i++)
    {
        index = lower_bound(m.begin(), m.end(), p[i]) - m.begin();
        count[index]++;
    }

    buildTree(count, size);
    int x, y;
    for (int i = 0; i < q; i++)
    {
        if (queries[i].first == '!')
        {
            x = lower_bound(m.begin(), m.end(), p[queries[i].second.first - 1]) - m.begin();
            updateTree(size, x, -1);
            p[queries[i].second.first - 1] = queries[i].second.second;
            x = lower_bound(m.begin(), m.end(), p[queries[i].second.first - 1]) - m.begin();
            updateTree(size, x, 1);
        }
        else
        {
            x = lower_bound(m.begin(), m.end(), queries[i].second.first) - m.begin();
            y = lower_bound(m.begin(), m.end(), queries[i].second.second) - m.begin();
            cout << queryTree(size, x, y)
                 << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}