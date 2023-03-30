#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("INPUT.txt", "r", stdin);
        freopen("OUTPUT.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<char> s(n);
    for (int i = 0; i < (n - 1); i++)
    {
        cin >> s[i];
    }

    vector<int> tmp;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        tmp.push_back(a[i]);
        if (s[i] == '0')
        {
            sort(tmp.begin(), tmp.end());
            v.push_back(tmp);
            tmp.clear();
        }
    }

    vector<int> b;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            b.push_back(v[i][j]);
        }
    }

    if (is_sorted(b.begin(), b.end()))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}