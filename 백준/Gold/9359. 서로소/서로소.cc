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

void solve() {
  ll N, A, B, ans = 0;
  cin >> A >> B >> N;
  vector<ll> cand;
  ll i = 2;
  while(i*i <= N) {
    if(N%i == 0) {
      cand.pb(i);
      N /= i;
    }
    else {
      i ++;
    }
  }
  if(N != 1) cand.pb(N);
  cand.erase(unique(all(cand)), cand.end());
  ll sz = (1<<sz(cand));
  for(int bit = 1; bit < sz; bit ++) {
    ll cnt = 0, cur_val = 1;
    for(int j = 0; j < sz(cand); j ++) {
      if(bit & (1 << j)) {
        cnt ++;
        cur_val *= cand[j];
      }
    }
    if(cnt & 1) {
      ans += B/cur_val - (A-1)/cur_val;
    }
    else {
      ans -= B/cur_val - (A-1)/cur_val;
    }
  }
  cout << B-A+1 - ans << nl;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    for(int test = 1; test <= tests; test ++) {
        cout << "Case #" << test << ": ";
        solve();
    }
}