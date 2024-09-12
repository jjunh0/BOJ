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

ll f(ll v) {
  ll ret = 0;
  while(v>0) {
    ret += v%10;
    v /= 10;
  }
  return ret;
}

void solve() {
  ll l, r;
  cin >> l >> r;
  ll ans = 0;
  vector<ll> pre(100);
  for(int i = 1; i <= 100; i ++) pre[i] = pre[i-1] + i;
  if(l == 0) l ++;
  while(l <= r && l%100 != 0) {
    ans += f(l);
    l ++;
  }
  ll i;
  for(i = l; i <= r; i += 100) {
    ll cur = f(i);
    if(i+100 > r) {
      for(int j = i; j <= r; j ++) ans += f(j);
      break;
    }
    else {
      ll val = pre[cur+9] - pre[cur-1];
      ans += 5LL * (2 * val + 90);
    }
  }
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