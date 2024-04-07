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

vector<int> adj[3005];
bool vis[3005], cycle[3005];

bool check_cycle(int st, int en, int p) {
  if(st == en) return 1;
  for(auto nxt : adj[st]) {
    if(p == nxt) continue;
    if(check_cycle(nxt, en, st)) {
      cycle[nxt] = 1;
      return 1;
    }
  }
  return 0;
}

bool flag = false;
void func(int cur, int p) {
  if(flag) return;
  for(auto nxt : adj[cur]) {
    if(nxt == p) continue;
    if(vis[nxt]) {
      check_cycle(cur, nxt, -1);
      cycle[cur] = 1;
      cycle[nxt] = 1;
      flag = true;
      return;
    }
    vis[nxt] = 1;
    func(nxt, cur);
  }
}
void solve() {
  int N;
  cin >> N;
  int u, v;
  for(int i = 0; i < N; i ++) {
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  vis[1] = 1;
  func(1, -1);
  for(int i = 1; i <= N; i ++) {
    queue<int> q;
    vector<int> cnt(N+1);
    q.push(i);
    cnt[i] = 1;
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      if(cycle[cur]) {
        cout << cnt[cur]-1 << ' ';
        break;
      }
      for(auto nxt : adj[cur]) {
        if(cnt[nxt]) continue;
        q.push(nxt);
        cnt[nxt] = cnt[cur] + 1;
        
      }
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