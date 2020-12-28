// https://cses.fi/problemset/task/1713
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long
 
void preprocess(vector<int> &div, int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j += i)
        {
            div[j]++;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> div(1000010, 0);
    preprocess(div, 1000010);
    lli q = 1, n;
    cin >> q;
    for (lli tc = 1; tc <= q; tc++)
    {
        cin >> n;
        cout << div[n] << endl;
    }
    return 0;
}