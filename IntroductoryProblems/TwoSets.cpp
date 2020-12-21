// https://cses.fi/problemset/task/1092

#include <bits/stdc++.h>

using namespace std;

#define lli long long

void solve()
{
    int n;
    cin >> n;
    if (n % 4 == 1 || n % 4 == 2)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        if (n % 4)
        {
            vector<int> v1, v2;
            v1.push_back(1);
            v1.push_back(2);
            v2.push_back(3);
            for (int i = 4; n - i + 4 > i; i++)
            {
                if (i % 2)
                {
                    v1.push_back(i);
                    v1.push_back(n - i + 4);
                }
                else
                {
                    v2.push_back(i);
                    v2.push_back(n - i + 4);
                }
            }
            cout << v1.size() << endl;
            for (int i = 0; i < v1.size(); i++)
            {
                cout << v1[i] << ' ';
            }
            cout << endl;
            cout << v2.size() << endl;
            for (int i = 0; i < v2.size(); i++)
            {
                cout << v2[i] << ' ';
            }
            cout << endl;
        }
        else
        {
            vector<int> v1, v2;
            for (int i = 1; n - i + 1 > i; i++)
            {
                if (i % 2)
                {
                    v1.push_back(i);
                    v1.push_back(n - i + 1);
                }
                else
                {
                    v2.push_back(i);
                    v2.push_back(n - i + 1);
                }
            }
            cout << v1.size() << endl;
            for (int i = 0; i < v1.size(); i++)
            {
                cout << v1[i] << ' ';
            }
            cout << endl;
            cout << v2.size() << endl;
            for (int i = 0; i < v2.size(); i++)
            {
                cout << v2[i] << ' ';
            }
            cout << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli q = 1;
    // cin>>q;
    for (lli tc = 1; tc <= q; tc++)
    {
        solve();
    }
    return 0;
}