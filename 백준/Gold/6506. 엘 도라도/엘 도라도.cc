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
ll A[105];
ll dp[105][105];
ll f(int cur, int len) {
  if(len == 0) return 1;
  if(dp[cur][len] != -1) return dp[cur][len];
  ll ret = 0;
  for(int i = cur-1; i >= 0; i --) {
    if(A[i] < A[cur]) {
      ret += f(i, len-1);
    }
  }
  dp[cur][len] = ret;
  return ret;
}

void solve() {
  int N, K;

  while(cin >> N >> K, N && K) {
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N; i ++) cin >> A[i];
    ll ans = 0;
    for(int i = K-1; i < N; i ++) {
      ans += f(i, K-1);
    }
    cout << ans << nl;

  }
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