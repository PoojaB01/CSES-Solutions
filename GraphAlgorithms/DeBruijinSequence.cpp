// https://cses.fi/problemset/task/1692

#include <bits/stdc++.h>

using namespace std;

#define lli long long

// Eulerian Circuit
void solve()
{
    int n, x, y;
    cin >> n;
    if (n == 1)
    {
        cout << "01" << endl;
        return;
    }
    int m = pow(2, n - 1);
    vector<int> edge[m];
    for (int i = 0; i < m; i++)
    {
        x = (i * 2) % m;
        edge[i].push_back(x + 1);
        edge[i].push_back(x);
    }

    set<pair<int, int>> s;
    int index[m] = {0};
    int cur;
    stack<int> cycle[m];
    set<int> discover;
    discover.insert(0);

    while (discover.size())
    {
        int i = *discover.begin();
        cur = i;
        while (1)
        {
            if (index[cur] == 0)
            {
                discover.insert(cur);
                cycle[cur].push(cur);
            }
            if (index[cur] == edge[cur].size())
            {
                discover.erase(cur);
                break;
            }
            y = edge[cur][index[cur]++];
            if (s.find({y, cur}) == s.end())
            {
                // s.insert({cur, y});
                cur = y;
                cycle[i].push(cur);
            }
        }
    }

    vector<int> ans;
    stack<int> st;
    st.push(0);

    while (!st.empty())
    {
        x = st.top();
        if (cycle[x].empty())
        {
            st.pop();
            continue;
        }
        if (cycle[x].top() != x && !cycle[cycle[x].top()].empty())
        {
            st.push(cycle[x].top());
            cycle[x].pop();
        }
        else
        {
            ans.push_back(cycle[x].top());
            cycle[x].pop();
        }
    }
    for (int i = 0; i < n - 2; i++)
        cout << 0;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << (ans[i] & 1);
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