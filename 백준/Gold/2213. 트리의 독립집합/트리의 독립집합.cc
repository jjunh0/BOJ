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
int dp[10005][3]; // dp[i][0] -> i번째를 선택하지 않았을 때의 최대값
void func(int cur, int p) { 
  dp[cur][1] = A[cur];
  for(auto nxt : adj[cur]) {
    if(p == nxt) continue;
    func(nxt, cur);
    dp[cur][1] += dp[nxt][0];
    dp[cur][0] += max(dp[nxt][1], dp[nxt][0]);
  }
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
  }
  for(int i = 0; i < n-1; i ++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  func(0, -1);
  func2(0, -1, 0);
  sort(all(ans));
  cout << max(dp[0][0], dp[0][1]) << nl;
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