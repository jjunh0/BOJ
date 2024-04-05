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

vector<int> adj[1000005];
int p[1000005];
int dp[1000005][2];
int n;
int dfs(int cur, int state) {
  if(dp[cur][state] != -1) return dp[cur][state];
  dp[cur][state] = 0;
  for(auto nxt : adj[cur]) {
    if(nxt == p[cur]) continue;
    p[nxt] = cur;
    if(state == 0) {
      dp[cur][state] += 1 + dfs(nxt, 1);
    }
    else {
      dp[cur][state] += min(1 + dfs(nxt, 1), dfs(nxt, 0));
    }
  }
  return dp[cur][state];
}

void solve() {
  cin >> n;
  for(int i = 0; i < n+1; i ++) fill(dp[i], dp[i]+2, -1);
  for(int i = 0; i <  n-1; i ++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  cout << min(dfs(1, 0), 1+dfs(1, 1));
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