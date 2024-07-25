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
vector<pi> adj[105];
vector<int> pri;
int dp[105][105];

int dfs(int cur, int dest) {
  if(cur == dest) return 1;
  if(dp[cur][dest] != -1) return dp[cur][dest];
  dp[cur][dest] = 0;
  for(auto nxt: adj[cur]) {
      dp[cur][dest] += dfs(nxt.X, dest) * nxt.Y;
  }
  return dp[cur][dest];
}

void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i ++) {
    int x, y, k;
    cin >> x >> y >> k;
    adj[x].pb({y, k});
  }
  for(int i = 0; i < 105; i ++) fill(dp[i], dp[i] + 105, -1);
  for(int i = 1; i <= n; i ++) {
    if(!sz(adj[i])) {
      cout << i << ' ' << dfs(n, i) << nl;
      
    }
  }
  
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