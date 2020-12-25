// https://cses.fi/problemset/task/1194

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli MAX = 1e7;

void insert_A(int x, int y, int n, int m, queue<pair<int, int>> &q, vector<vector<pair<char, int>>> &dir, vector<vector<int>> &dist, string s[], char c, int d)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;
    if (dir[x][y].first != '?')
        return;
    if (dist[x][y] < d + 1)
        return;
    dir[x][y] = {c, d + 1};
    q.push({x, y});
}

void process_A(int x, int y, vector<vector<pair<char, int>>> &dir, vector<vector<int>> &dist, string s[], int n, int m, queue<pair<int, int>> &q)
{
    insert_A(x - 1, y, n, m, q, dir, dist, s, 'U', dir[x][y].second);
    insert_A(x + 1, y, n, m, q, dir, dist, s, 'D', dir[x][y].second);
    insert_A(x, y - 1, n, m, q, dir, dist, s, 'L', dir[x][y].second);
    insert_A(x, y + 1, n, m, q, dir, dist, s, 'R', dir[x][y].second);
    q.pop();
}

void insert_M(int x, int y, int n, int m, queue<pair<int, int>> &q, vector<vector<int>> &dist, string s[], int p1, int p2)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;
    if (dist[x][y] != MAX)
        return;
    dist[x][y] = dist[p1][p2] + 1;
    q.push({x, y});
}

void process_M(int x, int y, vector<vector<int>> &dist, string s[], int n, int m, queue<pair<int, int>> &q)
{
    insert_M(x - 1, y, n, m, q, dist, s, x, y);
    insert_M(x + 1, y, n, m, q, dist, s, x, y);
    insert_M(x, y - 1, n, m, q, dist, s, x, y);
    insert_M(x, y + 1, n, m, q, dist, s, x, y);
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

    vector<vector<int>> dist(n, vector<int>(m, MAX));
    queue<pair<int, int>> q;
    int x = -1, y = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '#')
            {
                dist[i][j] = 0;
            }
            if (s[i][j] == 'M')
            {
                dist[i][j] = 0;
                q.push({i, j});
            }
            if (s[i][j] == 'A')
            {
                x = i;
                y = j;
            }
        }
    }
    while (!q.empty())
    {
        process_M(q.front().first, q.front().second, dist, s, n, m, q);
    }

    vector<vector<pair<char, int>>> dir_A(n, vector<pair<char, int>>(m, {'?', 0}));
    dir_A[x][y] = {'.', 1};
    q.push({x, y});

    while (!q.empty())
    {
        process_A(q.front().first, q.front().second, dir_A, dist, s, n, m, q);
    }

    x = -1, y = -1;
    for (int i = 0; i < n; i++)
    {
        if (dir_A[i][0].first != '?')
        {
            x = i, y = 0;
        }
        else if (dir_A[i][m - 1].first != '?')
        {
            x = i, y = m - 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (dir_A[0][i].first != '?')
        {
            x = 0, y = i;
        }
        else if (dir_A[n - 1][i].first != '?')
        {
            x = n - 1, y = i;
        }
    }

    if (x == -1)
    {
        cout << "NO" << endl;
        return;
    }
    
    cout << "YES" << endl;
    vector<char> path;
    while (dir_A[x][y].first != '.')
    {
        path.push_back(dir_A[x][y].first);
        switch (dir_A[x][y].first)
        {
        case 'R':
            y--;
            break;
        case 'L':
            y++;
            break;
        case 'U':
            x++;
            break;
        case 'D':
            x--;
            break;
        }
    }
    cout << path.size() << endl;
    reverse(path.begin(), path.end());
    for (char i : path)
    {
        cout << i;
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