// https://cses.fi/problemset/task/1724

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli MAX = 1e18 + 1e10;

vector<vector<lli>> Identity(int n)
{
    vector<vector<lli>> I(n, vector<lli>(n, MAX));
    for (int i = 0; i < n; i++)
    {
        I[i][i] = 0;
    }
    return I;
}

vector<vector<lli>> matrixmultiply(vector<vector<lli>> &A, vector<vector<lli>> &B, int n, int m, int p)
{
    vector<vector<lli>> ans(n, vector<lli>(p, MAX));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < p; k++)
            {
                if (A[i][j] != MAX && B[j][k] != MAX)
                    ans[i][k] = min(ans[i][k], (A[i][j] + B[j][k]));
            }
        }
    }
    return ans;
}

vector<vector<lli>> matrixexpo(vector<vector<lli>> &A, int n, lli pow)
{
    if (pow == 0)
    {
        return Identity(n);
    }
    vector<vector<lli>> B = Identity(n);
    while (pow > 0)
    {
        if (pow & 1)
            B = matrixmultiply(A, B, n, n, n);
        pow = pow >> 1;
        A = matrixmultiply(A, A, n, n, n);
    }
    return B;
}

void solve()
{
    lli n, m, k, x, y, z;
    cin >> n >> m >> k;
    vector<vector<lli>> path(n, vector<lli>(n, MAX));
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        path[x - 1][y - 1] = min(z, path[x - 1][y - 1]);
    }
    path = matrixexpo(path, n, k);
    cout << (path[0][n - 1] == MAX ? -1 : path[0][n - 1]) << endl;
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