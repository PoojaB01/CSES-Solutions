// https://cses.fi/problemset/task/1096

#include <bits/stdc++.h>

using namespace std;

#define lli long long

lli MOD = 1e9 + 7;

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
                ans[i][k] += (A[i][j] * B[j][k]) % MOD;
                ans[i][k] %= MOD;
            }
        }
    }
    return ans;
}

vector<vector<lli>> matrixexpo(vector<vector<lli>> &A, int n, lli pow)
{
    if (pow == 0)
    {
        return Identity(6);
    }
    vector<vector<lli>> B = matrixexpo(A, n, pow / 2);
    B = matrixmultiply(B, B, n, n, n);
    if (pow & 1)
    {
        B = matrixmultiply(A, B, n, n, n);
    }
    return B;
}

void solve()
{
    lli n;
    cin >> n;

    vector<vector<lli>> A = {
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0}};

    vector<vector<lli>> ans = matrixexpo(A, 6, n);
    vector<vector<lli>> f6 = {{16}, {8}, {4}, {2}, {1}, {1}};
    ans = matrixmultiply(ans, f6, 6, 6, 1);

    cout << ans[5][0] << endl;
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