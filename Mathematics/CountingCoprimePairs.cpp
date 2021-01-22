// https://cses.fi/problemset/task/2417

#include <bits/stdc++.h>

using namespace std;

#define lli long long
#define MAXN 1000010

vector<lli> util(MAXN, 1);
vector<lli> prime;

void preprocess()
{
    for (lli i = 2; i < MAXN; i++)
    {
        if (util[i])
        {
            prime.push_back(i);
            for (lli j = 2 * i; j < MAXN; j += i)
            {
                util[j] = 0;
            }
        }
    }
    util.assign(MAXN, -1);
    for (lli p : prime)
    {
        for (lli i = p * p; i < MAXN; i += p * p)
            util[i] = 0;
        for (lli i = p; i < MAXN; i += p)
            util[i] *= -1;
    }
}

void solve()
{
    lli n;
    cin >> n;
    vector<lli> c(MAXN, 0);
    lli x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        c[x]++;
    }
    lli ans = (n * (n - 1)) / 2, sum = 0;
    for (lli i = 2; i < MAXN; i++)
    {
        if (util[i])
        {
            sum = 0;
            for (lli j = i; j < MAXN; j += i)
            {
                sum += c[j];
            }
            ans -= util[i] * (sum * (sum - 1)) / 2;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    preprocess();
    lli q = 1;
    // cin >> q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}