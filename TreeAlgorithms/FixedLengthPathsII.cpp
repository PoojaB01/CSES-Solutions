// https://cses.fi/problemset/task/2081

#include <bits/stdc++.h>

using namespace std;

#define lli long long

int sizev(vector<lli> *t)
{
    return t->size();
}

vector<lli> *mergelist(vector<lli> *a, vector<lli> *b, lli &ans, int k)
{
    if (a == NULL)
        return b;
    if (a->size() > b->size())
    {
        swap(a, b);
    }
    for (int i = 0; i < a->size(); i++)
    {
        lli p = 0;
        if (k - i - 2 < sizev(b))
            p = (*b)[min(sizev(b) - 1, sizev(b) - 1 - (k - i - 2))];
        lli r = (*a)[sizev(a) - 1 - i];
        if (i + 1 < a->size())
            r -= (*a)[sizev(a) - 2 - i];
        ans += r * p;
    }
    for (int i = 0; i < a->size(); i++)
    {
        (*b)[b->size() - 1 - i] += (*a)[a->size() - 1 - i];
    }
    return b;
}

vector<lli> *dfs(int x, vector<int> edge[], vector<int> &v, lli &ans, int k)
{
    v[x] = 1;
    vector<lli> *t = NULL;
    for (int i : edge[x])
    {
        if (v[i] == 0)
        {
            t = mergelist(t, dfs(i, edge, v, ans, k), ans, k);
        }
    }
    if (t == NULL)
    {
        t = new vector<lli>();
        t->push_back(1);
    }
    else
        t->push_back(t->back() + 1);
    ans += (sizev(t) - 1 - k >= 0) ? (*t)[sizev(t) - 1 - k] : 0;
    return t;
}

void solve()
{
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int x, y;
    vector<int> edge[n];

    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        edge[x - 1].push_back(y - 1);
        edge[y - 1].push_back(x - 1);
    }
    lli ans1 = 0, ans2 = 0;
    vector<int> v(n, 0);
    dfs(0, edge, v, ans1, k1);
    v.assign(n, 0);
    dfs(0, edge, v, ans2, k2 + 1);
    cout << ans1 - ans2 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    // cin >> q;
    for (int tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}