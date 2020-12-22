// https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void insert(int x, int y, int n, int m, queue<pair<int, int>> &q, vector<vector<int>> &v, string s[])
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;
    if (s[x][y] == '#' || v[x][y] == 1)
        return;
    v[x][y] = 1;
    q.push({x, y});
}

void process(int x, int y, vector<vector<int>> &v, string s[], int n, int m, queue<pair<int, int>> &q)
{
    insert(x - 1, y, n, m, q, v, s);
    insert(x + 1, y, n, m, q, v, s);
    insert(x, y - 1, n, m, q, v, s);
    insert(x, y + 1, n, m, q, v, s);
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
    vector<vector<int>> v(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 0 && s[i][j] == '.')
            {
                insert(i, j, n, m, q, v, s);
                while (!q.empty())
                {
                    process(q.front().first, q.front().second, v, s, n, m, q);
                }
                count++;
            }
        }
    }
    cout << count << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}