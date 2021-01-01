// https://cses.fi/problemset/task/1691

#include <bits/stdc++.h>

using namespace std;

#define lli long long

// Eulerian Circuit
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> edge[n + 1];
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        if (edge[i].size() % 2)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    set<pair<int, int>> s;
    int index[n + 1] = {0};
    int cur = 1;
    stack<int> cycle[n + 1];
    set<int> discover;
    discover.insert(1);

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
                s.insert({cur, y});
                cur = y;
                cycle[i].push(cur);
            }
        }
    }

    vector<int> ans;
    stack<int> st;
    st.push(1);

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

    if (ans.size() != m + 1)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    else
    {
        for (int i : ans)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}