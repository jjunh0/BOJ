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
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
ll pw(ll val, ll sq) {
  if(sq == 1) return val;
  ll ret = pw(val, sq/2);
  ret = ret * ret % MOD;
  if(sq%2 != 0) ret *= val % MOD;
  return ret % MOD;
}

void solve() {
  ll a, b;
  cin >> a >> b; 
  if(a == 1) cout << b%MOD;
  else cout << (pw(a, b)-1) * pw(a-1, MOD-2) % MOD;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}