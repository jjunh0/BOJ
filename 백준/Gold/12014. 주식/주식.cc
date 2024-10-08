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
  int N, K;
  cin >> N >> K;
  vector<int> lis;
  for(int i = 0; i < N; i ++) {
    int t;
    cin >> t;
    if(lis.empty() || lis.back() < t) lis.pb(t);
    else {
      auto it = lower_bound(all(lis), t);
      *it  = t;
    }
  }
  if(sz(lis) >= K) cout << 1 << nl;
  else cout << 0 << nl;

}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    for(int test = 1; test <= tests; test ++) {
        cout << "Case #" << test << nl;      
        solve();
    }
}