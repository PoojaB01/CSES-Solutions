// https://cses.fi/problemset/task/1689

#include <bits/stdc++.h>

using namespace std;

#define lli long long

vector<vector<int>> steps = {
    {1, 2},
    {1, -2},
    {2, 1},
    {2, -1},
    {-1, 2},
    {-1, -2},
    {-2, 1},
    {-2, -1}};

bool valid(int x, int y, int n)
{
    return x >= 0 && y >= 0 && x < n && y < n;
}

bool solve(vector<vector<int>> &grid, vector<vector<int>> degree, int x, int y, int k, int n, int start)
{
    int next_x = -1, next_y = -1;
    int min = 10;
    for (int i = 0; i < n; i++)
    {
        int X = x + steps[(i + start) % n][0], Y = y + steps[(i + start) % n][1];
        if (valid(X, Y, n))
        {
            if (degree[X][Y] < min && grid[X][Y] == 0)
            {
                next_x = X, next_y = Y;
                min = degree[X][Y];
            }
        }
    }
    if (next_x == -1)
        return false;
    grid[next_x][next_y] = k + 1;
    for (int i = 0; i < n; i++)
    {
        int X = next_x + steps[i][0], Y = next_y + steps[i][1];
        if (valid(X, Y, n))
        {
            if (grid[X][Y] == 0)
            {
                degree[X][Y]--;
            }
        }
    }
    if (k + 1 == n * n)
        return true;
    start = 0;
    for (int i = 0; i < n; i++)
        if (solve(grid, degree, next_x, next_y, k + 1, n, i))
            return true;
    grid[next_x][next_y] = 0;
    for (int i = 0; i < n; i++)
    {
        int X = next_x + steps[i][0], Y = next_y + steps[i][1];
        if (valid(X, Y, n))
        {
            if (grid[X][Y] == 0)
            {
                degree[X][Y]++;
            }
        }
    }
    return false;
}

void solve()
{
    int n = 8;
    int x, y;
    cin >> x >> y;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<vector<int>> degree(n, vector<int>(n, 0));
    grid[y - 1][x - 1] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                int X = i + steps[k][0], Y = j + steps[k][1];
                if (valid(X, Y, n))
                {
                    degree[X][Y]++;
                }
            }
        }
    }
    int start = 0;
    while (!solve(grid, degree, y - 1, x - 1, 1, n, start++))
        ;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << grid[i][j] << ' ';
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