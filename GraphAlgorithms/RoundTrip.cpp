// https://cses.fi/problemset/task/1669

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n, m, x, y;
    cin >> n >> m;
    vector<int> edge[n + 1];
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    vector<int> p(n + 1, -1);
    queue<int> q;

    vector<int> path1, path2;

    int flag = 0;

    for (int i = 1; i < n + 1; i++)
    {
        if (p[i] == -1)
        {
            q.push(i);
            p[i] = 0;

            while (!q.empty())
            {
                for (auto i : edge[q.front()])
                {
                    if (p[i] == -1)
                    {
                        q.push(i);
                        p[i] = q.front();
                    }
                    else if (i != p[q.front()])
                    {
                        x = q.front(), y = i;
                        while (x > 0)
                        {
                            path1.push_back(x);
                            x = p[x];
                        }
                        while (y > 0)
                        {
                            path2.push_back(y);
                            y = p[y];
                        }
                        int k = 0;
                        reverse(path1.begin(), path1.end());
                        reverse(path2.begin(), path2.end());
                        for (; k < min(path1.size(), path2.size()); k++)
                        {
                            if (path1[k] != path2[k])
                                break;
                        }
                        k--;
                        cout << path1.size() + path2.size() - 2 * k << endl;
                        for (int i = k; i < path1.size(); i++)
                        {
                            cout << path1[i] << ' ';
                        }
                        for (int i = path2.size() - 1; i >= k; i--)
                        {
                            cout << path2[i] << ' ';
                        }
                        cout << endl;
                        flag = 1;
                        goto end;
                    }
                }
                q.pop();
            }
        }
    }
end:
    if (flag == 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}