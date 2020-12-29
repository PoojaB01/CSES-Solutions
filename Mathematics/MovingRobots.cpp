// https://cses.fi/problemset/task/1726/

#include <bits/stdc++.h>

using namespace std;

#define lli long long
#define ldb long double

int inrange(int i, int j)
{
    return i >= 0 && j >= 0 && i < 8 && j < 8;
}
int index(int i, int j)
{
    return i * 8 + j;
}

vector<vector<ldb>> Identity(int n)
{
    vector<vector<ldb>> I(n, vector<ldb>(n, 0));
    for (int i = 0; i < n; i++)
    {
        I[i][i] = 1;
    }
    return I;
}

vector<vector<ldb>> matrixmultiply(vector<vector<ldb>> &A, vector<vector<ldb>> &B, int n, int m, int p)
{
    vector<vector<ldb>> ans(n, vector<ldb>(p, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < p; k++)
            {
                ans[i][k] += A[i][j] * B[j][k];
            }
        }
    }
    return ans;
}

vector<vector<ldb>> matrixexpo(vector<vector<ldb>> &A, int n, lli pow)
{
    if (pow == 0)
    {
        return Identity(n);
    }
    vector<vector<ldb>> B = matrixexpo(A, n, pow / 2);
    B = matrixmultiply(B, B, n, n, n);
    if (pow & 1)
    {
        B = matrixmultiply(A, B, n, n, n);
    }
    return B;
}

void solve()
{
    int k;
    cin >> k;
    vector<vector<ldb>> prob(64, vector<ldb>(64, 0));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            ldb c = 0;
            c += inrange(i - 1, j);
            c += inrange(i + 1, j);
            c += inrange(i, j - 1);
            c += inrange(i, j + 1);
            if (inrange(i - 1, j))
                prob[index(i, j)][index(i - 1, j)] += (ldb)1 / c;
            if (inrange(i + 1, j))
                prob[index(i, j)][index(i + 1, j)] += (ldb)1 / c;
            if (inrange(i, j - 1))
                prob[index(i, j)][index(i, j - 1)] += (ldb)1 / c;
            if (inrange(i, j + 1))
                prob[index(i, j)][index(i, j + 1)] += (ldb)1 / c;
        }
    }
    prob = matrixexpo(prob, 64, k);
    ldb ans = 0;
    for (int i = 0; i < 64; i++)
    {
        ldb p = 1;
        for (int j = 0; j < 64; j++)
        {
            p *= (1 - prob[j][i]);
        }
        ans += p;
    }
    cout << fixed << setprecision(6) << ans << endl;
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