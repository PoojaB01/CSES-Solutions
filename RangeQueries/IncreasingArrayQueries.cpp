// https://cses.fi/problemset/task/2416

#include <bits/stdc++.h>

using namespace std;

#define lli long long

struct node
{
    lli sum;
    vector<pair<lli, int>> q;
    vector<lli> ipsum;
};

struct query
{
    lli m;
    lli sum;
};

node tree[1000000];

node op(node a, node b)
{
    node ans;
    ans.sum = a.sum + b.sum;
    for (auto p : a.q)
    {
        ans.q.push_back(p);
    }
    int i = upper_bound(b.q.begin(), b.q.end(), make_pair(a.q.back().first, 0)) - b.q.begin();
    if (i > 0)
        ans.q.back().second += b.q[i - 1].second;
    for (; i < b.q.size(); i++)
    {
        ans.q.push_back({b.q[i].first, b.q[i].second + a.q.back().second});
    }
    lli sum = 0;
    lli isum = 0;
    for (auto p : ans.q)
    {
        sum += p.first * (p.second - isum);
        ans.ipsum.push_back(sum);
        isum = p.second;
    }
    return ans;
}

void buildTree(vector<lli> &a, lli start, lli end, lli index)
{
    if (start == end)
    {
        tree[index].sum = a[start];
        tree[index].q = {{a[start], 1}};
        tree[index].ipsum = {a[start]};
        return;
    }
    lli mid = (start + end) / 2;
    buildTree(a, start, mid, 2 * index);
    buildTree(a, mid + 1, end, 2 * index + 1);
    tree[index] = op(tree[2 * index], tree[2 * index + 1]);
}

query queryTree(lli start, lli end, lli index, lli left, lli right, lli k)
{
    if (right < start || left > end)
    {
        return {0, 0};
    }
    if (start >= left and end <= right)
    {
        lli i = upper_bound(tree[index].q.begin(), tree[index].q.end(), make_pair(k, 0)) - tree[index].q.begin();
        i--;
        lli sum = tree[index].ipsum.back();
        if (i >= 0)
        {
            sum -= tree[index].ipsum[i];
            sum += k * tree[index].q[i].second;
        }
        return {max(k, tree[index].q.back().first), sum - tree[index].sum};
    }

    lli mid = (start + end) / 2;

    query q = queryTree(start, mid, 2 * index, left, right, k);
    query p = queryTree(mid + 1, end, 2 * index + 1, left, right, q.m);

    return {p.m, q.sum + p.sum};
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
    buildTree(a, 0, n - 1, 1);
    for (int i = 1; i < n; i++)
    {
        a[i] += a[i - 1];
    }
    int x, y;
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        query ans = queryTree(0, n - 1, 1, x, y, 0);
        cout << ans.sum << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}