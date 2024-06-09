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
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';
const int mx = 0x3f3f3f3f;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
ll dp[55];

ll func(ll x) {
  ll ret = 0;
  for(ll i = 54; i >= 0; i --) {
    if(x & (1LL << i)) {
      ret += dp[i] + (x - (1LL<<i) + 1);
      x -= (1LL<<i);
    }
  }
  return ret;
}

void solve() {
  ll a, b;
  cin >> a >> b;
  dp[1] = 1;
  for(ll i = 2; i <= 54; i ++) {
    dp[i] = 2*dp[i-1] + (1LL<<(i-1));
  }
  cout << func(b) - func(a-1);
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
        solve();
    }
}