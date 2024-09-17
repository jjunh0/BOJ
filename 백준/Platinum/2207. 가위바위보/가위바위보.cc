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
vector<int> adj[20005], inv[20005], vis(20005), p(20005);
vector<pi> pn;
int N, M, num, idx = 1;

int nt(int cur) {
  if(cur <= M) return cur + M;
  return cur - M;
}

void dfs1(int cur) {
  vis[cur] = 1;
  for(auto nxt : adj[cur]) {
    if(!vis[nxt]) {
      dfs1(nxt);
    }
  }
  pn.pb({num ++, cur});
}

void dfs2(int cur) {
  vis[cur] = 1;
  p[cur] = idx;
  for(auto nxt : inv[cur]) {
    if(!vis[nxt]) dfs2(nxt);
  }
}

void scc() {
  for(int i = 1; i <= 2*M; i ++) {
    if(vis[i]) continue;
    dfs1(i);
  }
  sort(rall(pn));
  fill(all(vis), 0);
  for(int i = 0; i < sz(pn); i ++) {
    auto [num, cur] = pn[i];
    if(vis[cur]) continue;
    dfs2(cur);
    idx ++;
  }
}

void solve() {
  cin >> N >> M;
  for(int i = 0; i < N; i ++) {
    int a, b;
    cin >> a >> b;
    if(a < 0) a = nt(-a);
    if(b < 0) b = nt(-b);
    adj[nt(a)].pb(b);
    adj[nt(b)].pb(a);
    inv[b].pb(nt(a));
    inv[a].pb(nt(b));    
  }
  scc();
  for(int i = 1; i <= M; i ++) {
    if(p[i] == p[nt(i)]) {
      cout << "OTL";
      return;
    }
  }
  cout << "^_^";
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