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
vector<int> adj[20005];
vector<int> inv[20005], vis(20005), p(20005);
vector<pi> pn;
int num, idx=0;
int N, M;

int notX(int x) {
  if(x <= N) {
    return x + N;
  }
  else {
    return x - N;
  }
}

void dfs1(int cur) {
  vis[cur] = 1;
  for(auto nxt : adj[cur]) {
    if(vis[nxt]) continue;
    dfs1(nxt);
  }
  pn.pb({num ++, cur});
}

void dfs2(int cur) {
  vis[cur] = 1;
  p[cur] = idx;
  for(auto nxt : inv[cur]) {
    if(vis[nxt]) continue;
    dfs2(nxt);
  }
}

void scc() {
  for(int i = 1; i <= 2*N; i ++) {
    if(vis[i]) continue;
    dfs1(i);
  } 
  sort(rall(pn));
  fill(all(vis), 0);
  for(int i = 0; i < sz(pn); i ++) {
    if(vis[pn[i].Y]) continue;
    dfs2(pn[i].Y);
    idx ++;
  }
}

void solve() {
  cin >> N >> M;
  for(int i = 0; i < M; i ++) {
    int x, y;
    cin >> x >> y;
    if(x < 0) x = -x + N;
    if(y < 0) y = -y + N;
    adj[notX(x)].pb(y);
    adj[notX(y)].pb(x);
    inv[y].pb(notX(x));
    inv[x].pb(notX(y));
  }
  scc();
  for(int i = 1; i <= N; i ++) {
    if(p[i] == p[notX(i)]) {
      cout << 0;
      return;
    }
  }
  cout << 1 << nl;
  vector<int> bol(2*N+1, -1);
  vector<pi> sn;
  for(int i = 1; i <= 2*N; i ++) {
    sn.pb({p[i], i});
  } 
  
  sort(all(sn));
  for(int i = 0; i < 2*N; i ++) {
    int val = sn[i].Y;
    if(bol[val] == -1) {
      bol[val] = 0;
      bol[notX(val)] = 1;
    }
  }
  for(int i = 1; i <= N; i ++) cout << bol[i] << ' ';
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