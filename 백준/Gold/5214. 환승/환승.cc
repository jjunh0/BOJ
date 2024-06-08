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
vector<int> adj[101'005];
int vis[101'005];
void solve() {
  int n, k, m;
  cin >> n >> k >> m;
  for(int i = 0; i < m; i ++) {
    for(int j = 0; j < k; j ++) {
      int t; cin >> t;
      adj[n+1+i].pb(t);
      adj[t].pb(n+1+i);
    }
  }
  queue<int> q;
  q.push(1);
  vis[1] = 1;
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    for(auto nxt : adj[cur]) {
      if(vis[nxt] > 0) continue;
      vis[nxt] = vis[cur] + 1;
      q.push(nxt);
    }
  }

  cout << (vis[n] != 0 ? vis[n]/2 + 1 : -1)<< nl;
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