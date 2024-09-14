#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define ll long long
#define X first
#define Y second
using namespace std;

typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;
typedef pair<ll,ll> pl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

ll pw(ll val, ll sq) {
  if(sq == 0) return 1;
  ll ret = pw(val, sq/2) % MOD;
  ret = ret * ret % MOD;
  if(sq%2) {
    ret = ret * val % MOD;
  }
  return ret % MOD;
}

ll inv(int val) {
  return pw(val, MOD-2) % MOD;
}

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> fact(n+1);
  fact[0] = 1;
  for(ll i = 1; i <= n; i ++) {
    fact[i] = fact[i-1] * i % MOD;
  }
  cout << (fact[n] * inv(fact[m]))%MOD * inv(fact[n-m]) % MOD;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests = 1;
    // cin >> tests;
    while(tests--) {
        solve();
    }
}