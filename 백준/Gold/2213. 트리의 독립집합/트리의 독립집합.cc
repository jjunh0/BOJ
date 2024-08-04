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
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> adj[10005], ans;
int A[10005];
int dp[10005][3];
int func(int cur, int p, bool flag) { // flag -> 1이면 내 위에꺼 선택
  int ret = 0;
  if(dp[cur][0] == -1) {
    for(auto nxt : adj[cur]) {
      if(nxt == p) continue;
      ret += func(nxt, cur, 0); // cur 선택 x
    }
    dp[cur][0] = ret;
  }
  if(flag) return dp[cur][0];

  int ret2 = 0;
  if(!flag && dp[cur][1] == -1) { // cur 선택 o
    ret2 = A[cur];
    for(auto nxt : adj[cur]) {
      if(nxt == p) continue;
      ret2 += func(nxt, cur, 1);
    }
    dp[cur][1] = ret2;
  }
  return max(dp[cur][0], dp[cur][1]);
}

void func2(int cur, int p, bool flag) { // cur 선택 여부
  if(!flag && dp[cur][1] >= dp[cur][0]) { 
    ans.pb(cur);
  }
  for(auto nxt : adj[cur]) {
    if(p == nxt) continue;
    func2(nxt, cur, !flag && dp[cur][1] >= dp[cur][0]);
  }
}

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i ++) {
    cin >> A[i];
    fill(dp[i], dp[i]+2, -1);
  }
  for(int i = 0; i < n-1; i ++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  cout << func(0, -1, 0) << nl;
  func2(0, -1, 0);
  sort(all(ans));
  for(auto e : ans) cout << e+1 << ' ';
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