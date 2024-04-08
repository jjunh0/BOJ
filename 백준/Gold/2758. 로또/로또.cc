#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define ll long long
#define X first
#define Y second

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';

ll n, m, cnt;
ll dp[15][2005];
ll func(ll k, ll val) {
    if (k == 0) {
        return 1;
    }
    if(dp[k][val] != -1) return dp[k][val];
    dp[k][val] = 0;
    for (int i = val; i > 0; i--) {
        dp[k][val] += func(k - 1, i/2);
    }
    return dp[k][val];
}

void solve() {
    cin >> n >> m;
    cout << func(n, m) << nl; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 15; i ++) fill(dp[i], dp[i]+2005, -1);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}