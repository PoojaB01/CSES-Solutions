// https://cses.fi/problemset/task/2080

#include <bits/stdc++.h>

using namespace std;

#define lli long long

vector<lli> *mergelist(vector<lli> *a, vector<lli> *b, lli &ans, int k)
{
    if (a == NULL)
        return b;
    if (a->size() > b->size())
    {
        swap(a, b);
    }
    if (k > 1)
        for (int i = 0; i < a->size(); i++)
        {
            if ((k - i - 2) < b->size())
                ans += (*a)[a->size() - 1 - i] * (*b)[b->size() - 1 - (k - i - 2)];
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
        t = new vector<lli>();
    t->push_back(1);

    if (t->size() > k)
        ans += (*t)[t->size() - k - 1];

    return t;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int x, y;
    vector<int> edge[n];

    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        edge[x - 1].push_back(y - 1);
        edge[y - 1].push_back(x - 1);
    }
    lli ans = 0;
    vector<int> v(n, 0);
    dfs(0, edge, v, ans, k);
    cout << ans << endl;
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