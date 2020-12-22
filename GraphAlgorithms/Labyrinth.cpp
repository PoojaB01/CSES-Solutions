// https://cses.fi/problemset/task/1193

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void insert(int x, int y, int n, int m, queue<pair<int, int>> &q, vector<vector<pair<int, int>>> &v, string s[], int p1, int p2)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;
    if (s[x][y] == '#' || v[x][y] != make_pair(-1, -1))
        return;
    v[x][y] = {p1, p2};
    q.push({x, y});
}

void process(int x, int y, vector<vector<pair<int, int>>> &v, string s[], int n, int m, queue<pair<int, int>> &q)
{
    insert(x - 1, y, n, m, q, v, s, x, y);
    insert(x + 1, y, n, m, q, v, s, x, y);
    insert(x, y - 1, n, m, q, v, s, x, y);
    insert(x, y + 1, n, m, q, v, s, x, y);
    q.pop();
}

void solve()
{
    int n, m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    vector<vector<pair<int, int>>> p(n, vector<pair<int, int>>(m, make_pair(-1, -1)));
    queue<pair<int, int>> q;
    int x = -1, y = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (p[i][j] == make_pair(-1, -1) && s[i][j] == 'A')
            {
                insert(i, j, n, m, q, p, s, -2, -2);
                while (!q.empty())
                {
                    process(q.front().first, q.front().second, p, s, n, m, q);
                }
            }
            if (s[i][j] == 'B')
            {
                x = i;
                y = j;
            }
        }
    }
    if (p[x][y] == make_pair(-1, -1))
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        cout << "YES" << endl;
        string path = "";
        while (make_pair(x, y) != make_pair(-2, -2))
        {
            int p1 = p[x][y].first;
            int p2 = p[x][y].second;
            if (x == p1 + 1)
                path += 'D';
            if (x == p1 - 1)
                path += 'U';
            if (y == p2 + 1)
                path += 'R';
            if (y == p2 - 1)
                path += 'L';
            x = p1, y = p2;
        }
        p.pop_back();
        reverse(path.begin(), path.end());
        cout << path.length() << endl;
        cout << path << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}