// https://cses.fi/problemset/task/1739

#include <bits/stdc++.h>

using namespace std;

#define lli long long
#define MAXN 5000

vector<vector<int>> tree(4 * MAXN, vector<int>(MAXN, 0));

void buildY(vector<vector<int>> &a, int sY, int eY, int tI, int iX, int index)
{
    if (sY == eY)
    {
        tree[tI][index] = a[iX][sY];
        return;
    }
    int mid = (sY + eY) / 2;

    buildY(a, sY, mid, tI, iX, 2 * index);
    buildY(a, mid + 1, eY, tI, iX, 2 * index + 1);

    tree[tI][index] = tree[tI][2 * index] + tree[tI][2 * index + 1];
}

void buildX(vector<vector<int>> &a, int sX, int eX, int m, int index)
{
    if (sX == eX)
    {
        buildY(a, 0, m - 1, index, sX, 1);
        return;
    }

    int mid = (sX + eX) / 2;
    buildX(a, sX, mid, m, 2 * index);
    buildX(a, mid + 1, eX, m, 2 * index + 1);

    for (int i = 0; i < tree[index].size(); i++)
    {
        tree[index][i] = tree[2 * index][i] + tree[2 * index + 1][i];
    }
}

int queryY(int lY, int rY, int sY, int eY, int tI, int index)
{
    if (rY < sY || lY > eY)
    {
        return 0;
    }
    if (sY >= lY and eY <= rY)
    {
        // cout << index << '*' << sY << '*' << eY << endl;
        // cout << tree[tI][index] << endl;
        return tree[tI][index];
    }
    int mid = (sY + eY) / 2;
    return queryY(lY, rY, sY, mid, tI, 2 * index) + queryY(lY, rY, mid + 1, eY, tI, 2 * index + 1);
}

int queryX(int lX, int rX, int lY, int rY, int sX, int eX, int m, int index)
{
    if (rX < sX || lX > eX)
    {
        return 0;
    }
    if (sX >= lX and eX <= rX)
    {
        // cout << index << ' ' << sX << ' ' << eX << endl;
        return queryY(lY, rY, 0, m - 1, index, 1);
    }
    int mid = (sX + eX) / 2;
    return queryX(lX, rX, lY, rY, sX, mid, m, 2 * index) + queryX(lX, rX, lY, rY, mid + 1, eX, m, 2 * index + 1);
}

void update(int X, int Y, int n, int m)
{
    int start = 0, end = n - 1, iX = 1, iY = 1, mid;
    while (start < end)
    {
        mid = (start + end) / 2;
        if (X > mid)
        {
            start = mid + 1;
            iX = 2 * iX + 1;
        }
        else
        {
            end = mid;
            iX = 2 * iX;
        }
    }
    start = 0, end = m - 1;
    while (start < end)
    {
        mid = (start + end) / 2;
        if (Y > mid)
        {
            start = mid + 1;
            iY = 2 * iY + 1;
        }
        else
        {
            end = mid;
            iY = 2 * iY;
        }
    }
    int d = 0;
    if (tree[iX][iY] == 1)
        d = -1;
    else
        d = 1;
    while (iX)
    {
        int t = iY;
        while (t)
        {
            tree[iX][t] += d;
            t /= 2;
        }
        iX /= 2;
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = s[i][j] == '*' ? 1 : 0;
        }
    }

    buildX(a, 0, n - 1, n, 1);

    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         cout << tree[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    int x1, x2, y1, y2, k;
    for (int i = 0; i < q; i++)
    {
        cin >> k;
        if (k == 1)
        {
            cin >> x1 >> y1;
            update(x1 - 1, y1 - 1, n, n);
        }
        else if (k == 2)
        {
            cin >> x1 >> y1 >> x2 >> y2;
            cout << queryX(x1 - 1, x2 - 1, y1 - 1, y2 - 1, 0, n - 1, n, 1) << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lli q = 1;
    // cin >> q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}