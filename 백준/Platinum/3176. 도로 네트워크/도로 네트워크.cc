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
const int MAX_N = 100005;
vector<pi> adj[MAX_N];
int dp_mx[MAX_N][25], dp_mn[MAX_N][25], depth[MAX_N], par[MAX_N][25];
void dfs(int cur, int p) {
  for(auto [val, nxt] : adj[cur]) {
    if(p == nxt) continue;
    depth[nxt] = depth[cur] + 1;
    par[nxt][0] = cur;
    dp_mx[nxt][0] = val;
    dp_mn[nxt][0] = val;

    dfs(nxt, cur);
  }
}

void solve() {
  int N, K;
  cin >> N;
  for(int i = 0; i < N-1; i ++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].pb({c, b});
    adj[b].pb({c, a});
  }
  dfs(1, -1);
  for(int i = 1; i < 22; i ++) {
    for(int j = 1; j <= N; j++) {
      par[j][i] = par[par[j][i-1]][i-1];
      dp_mx[j][i] = max(dp_mx[j][i-1], dp_mx[par[j][i-1]][i-1]);
      dp_mn[j][i] = min(dp_mn[j][i-1], dp_mn[par[j][i-1]][i-1]);
    }
  }
  cin >> K;
  while(K --) {
    int u, v;
    cin >> u >> v;
    if(depth[u] < depth[v]) {
      swap(u, v); 
    }
    int a = u, b = v;
    int diff = depth[a] - depth[b];
    int ans_mx = 0, ans_mn = MX;
    for(int i = 0; diff; i ++) {
      if(diff % 2) {
        ans_mx = max(ans_mx, dp_mx[a][i]);
        ans_mn = min(ans_mn, dp_mn[a][i]);
        a = par[a][i];
      }
      diff /= 2;
    }
    if(a != b) {
      for(int j = 21; j >= 0; j --) {
        if(par[a][j] != 0 && par[a][j] != par[b][j]) {
          ans_mx = max({ans_mx, dp_mx[a][j], dp_mx[b][j]});
          ans_mn = min({ans_mn, dp_mn[a][j], dp_mn[b][j]});
          a = par[a][j];
          b = par[b][j];
        }
      }
      ans_mx = max({ans_mx, dp_mx[a][0], dp_mx[b][0]});
      ans_mn = min({ans_mn, dp_mn[a][0], dp_mn[b][0]});
    }
    cout << ans_mn << ' ' << ans_mx << nl;
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