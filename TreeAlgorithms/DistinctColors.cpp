// https://cses.fi/problemset/task/1139

#include <bits/stdc++.h>

using namespace std;

#define lli long long

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

bool cmp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
{
    if (a.first.first / d == b.first.first / d)
    {
        return a.first.second < b.first.second;
    }
    else
        return a.first.first / d < b.first.first / d;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> c(n);
    unordered_map<int, int> m;
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        if (m.find(c[i]) == m.end())
        {
            m[c[i]] = k++;
        }
        c[i] = m[c[i]];
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

    vector<int> cc(k, 0);
    vector<pair<pair<int, int>, int>> q;
    vector<int> pre(n);

    k = 0;
    preorder(0, 0, e, q, pre, k);

    sort(q.begin(), q.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        pre[i] = c[pre[i]];
    }

    int start = 0, end = 0;
    cc[c[0]]++;
    k = 1;
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        while (end < q[i].first.second)
        {
            end++;
            if (++cc[pre[end]] == 1)
                k++;
        }
        while (start > q[i].first.first)
        {
            start--;
            if (++cc[pre[start]] == 1)
                k++;
        }
        while (start < q[i].first.first)
        {
            if (--cc[pre[start]] == 0)
                k--;
            start++;
        }
        while (end > q[i].first.second)
        {
            if (--cc[pre[end]] == 0)
                k--;
            end--;
        }
        ans[q[i].second] = k;
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