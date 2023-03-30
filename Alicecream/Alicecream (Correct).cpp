#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    set<pair<ll, ll>> bad;
    for (ll i = 0; i < M; i++) {
        ll x, y;
        cin >> x >> y;
        bad.insert({x, y});
    }

    set<ll> ST;
    map<ll, ll> frequency;
    map<ll, bool> visited;
    map<ll, set<ll, greater<ll>>> mp;
    for (auto x : A) {
        frequency[x]++;
    }
    for (ll i = 0; i < N; i++) {
        if (!visited[A[i]]) {
            mp[frequency[A[i]]].insert(A[i]);
            visited[A[i]] = true;
        }
    }
    for (auto x : mp) {
        ST.insert(x.first);
    }

    ll ans = INT_MIN;
    for (auto fx : ST) {
        for (auto x : mp[fx]) {
            for (auto fy : ST) {
                if (fy > fx) {
                    break;
                }

                bool flag = false;
                for (auto y : mp[fy]) {
                    if (x == y or bad.count({x, y}) or bad.count({y, x})) {
                        continue;
                    }
                    ans = max(ans, (fx + fy) * (x + y));
                    flag = true;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}