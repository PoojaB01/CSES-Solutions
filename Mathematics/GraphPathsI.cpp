// https://cses.fi/problemset/task/1723

#include <bits/stdc++.h>

using namespace std;

#define lli long long

const int MOD = 1e9 + 7;

vector<vector<lli>> Identity(int n)
{
    vector<vector<lli>> I(n, vector<lli>(n, 0));
    for (int i = 0; i < n; i++)
    {
        I[i][i] = 1;
    }
    return I;
}

vector<vector<lli>> matrixmultiply(vector<vector<lli>> &A, vector<vector<lli>> &B, int n, int m, int p)
{
    vector<vector<lli>> ans(n, vector<lli>(p, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < p; k++)
            {
                ans[i][k] = (ans[i][k] + (A[i][j] * B[j][k]) % MOD) % MOD;
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
    lli n, m, k, x, y;
    cin >> n >> m >> k;
    vector<vector<lli>> path(n, vector<lli>(n, 0));
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        path[x - 1][y - 1]++;
    }
    path = matrixexpo(path, n, k);
    cout << path[0][n - 1] << endl;
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