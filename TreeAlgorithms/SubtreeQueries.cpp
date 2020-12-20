// https://cses.fi/problemset/task/1137

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli tree[1000000];

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
    tree[p + n] = value;
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

int dfs(int x, vector<int> edge[], int par, vector<lli> &eulerTour, int &k)
{
    eulerTour[k++] = x;

    for (int i = 0; i < edge[x].size(); i++)
    {
        if (edge[x][i] != par)
        {
            dfs(edge[x][i], edge, x, eulerTour, k);
        }
    }

    eulerTour[k++] = x;
}

void solve()
{
    int n, q, x, y;
    cin >> n >> q;
    int val[n];

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    vector<int> edge[n];

    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        edge[x - 1].push_back(y - 1);
        edge[y - 1].push_back(x - 1);
    }

    vector<lli> eulerTour(2 * n, 0);

    int k = 0;
    dfs(0, edge, 0, eulerTour, k);

    vector<int> start(n, 1000000), end(n, -1);

    for (int i = 0; i < 2 * n; i++)
    {
        start[eulerTour[i]] = min(i, start[eulerTour[i]]);
        end[eulerTour[i]] = max(i, end[eulerTour[i]]);

        eulerTour[i] = val[eulerTour[i]];
    }

    buildTree(eulerTour, 2 * n);

    for (int i = 0; i < q; i++)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            int s, x;
            cin >> s >> x;
            s--;
            updateTree(2 * n, start[s], x);
            updateTree(2 * n, end[s], x);
        }
        else
        {
            int s;
            cin >> s;
            s--;
            cout << queryTree(2 * n, start[s], end[s]) / 2 << endl;
        }
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