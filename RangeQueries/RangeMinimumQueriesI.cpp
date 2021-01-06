// https://cses.fi/problemset/task/1647

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> t;
    vector<pair<pair<int, int>, int>> Q(q);
    for (int i = 0; i < q; i++)
    {
        cin >> Q[i].first.second >> Q[i].first.first;
        Q[i].second = i;
    }
    sort(Q.begin(), Q.end());
    int j = 0;
    vector<int> output(q);
    for (int i = 0; i < q; i++)
    {
        while (j < Q[i].first.first)
        {
            while (t.size())
            {
                if (a[t.back()] > a[j])
                {
                    t.pop_back();
                }
                else
                    break;
            }
            t.push_back(j);
            j++;
        }
        output[Q[i].second] = a[*(lower_bound(t.begin(), t.end(), Q[i].first.second - 1))];
    }
    for (int i = 0; i < q; i++)
    {
        cout << output[i] << endl;
    }
}

int main()
{
    lli q = 1;
    // cin >> q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}