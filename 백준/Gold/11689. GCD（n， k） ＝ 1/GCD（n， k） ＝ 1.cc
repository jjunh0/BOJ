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
  ll ret = pw(val, sq/2);
  ret = ret * ret;
  if(sq%2) ret = ret * val;
  return ret;
}

void solve() {
  ll n;
  cin >> n;
  ll i = 2;
  ll ans = 1;
  while(i*i <= n) {
    ll cnt = 0;
    while(n%i == 0) {
      cnt ++;
      n /= i;
    }
    if(cnt > 0)
      ans *= pw(i, cnt) - pw(i, cnt-1);
    i ++;
  }
  if(n != 1) ans *= (n-1);
  cout << ans;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests = 1;
    while(tests--) {
        solve();
    }
}