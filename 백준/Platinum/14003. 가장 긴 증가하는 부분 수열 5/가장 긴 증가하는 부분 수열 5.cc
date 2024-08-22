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

void solve() {
  int n;
  cin >> n;
  vector<int> A(n), lis, dp(n), ans;

  for(auto &e : A) cin >> e;
  for(int i = 0; i < n; i ++) {
    if(lis.empty() || lis.back() < A[i]) {
      lis.pb(A[i]);
      dp[i] = sz(lis);
    }
    else {
      auto it = lower_bound(all(lis), A[i]) - lis.begin();
      lis[it] = A[i];
      dp[i] = it+1;
    }
  }
  int cur = sz(lis);
  for(int i = n-1; i >= 0; i--) {
    if(dp[i] == cur) {
      ans.pb(A[i]);
      cur --;
    }
  }
  cout << sz(ans) << nl;
  reverse(all(ans));
  for(auto e : ans) cout << e << ' ';
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