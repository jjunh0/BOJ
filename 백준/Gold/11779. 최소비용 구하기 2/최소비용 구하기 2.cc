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

vector<pair<int, int>> adj[20005];
vector<int> d(20005, mx);
vector<int> pre(20005, -1);
void solve() {
  int v, e;
  cin >> v >> e;

  priority_queue<pair<int, int>, vector<pi>, greater<pi>> pq;

  for(int i = 0; i < e; i ++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].pb({w, v});
  }
  int a, b;
  cin >> a >> b;
  pq.push({0, a});
  d[a] = 0;

  while(!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if(d[cur.Y] != cur.X) continue;
    for(auto nxt : adj[cur.Y]) {
      if(nxt.X + d[cur.Y] < d[nxt.Y]) {
        d[nxt.Y] = nxt.X + d[cur.Y];
        pq.push({d[nxt.Y], nxt.Y});
        pre[nxt.Y] = cur.Y;
      }
    }
  }
  cout << d[b] << nl;
  vector<int> ans;
  int p = b;
  while(p != a) {
    ans.pb(p);
    p = pre[p];
  }
  ans.pb(p);
  cout << sz(ans) << nl;
  for(int i = sz(ans)-1; i >= 0; i --) {
    cout << ans[i] << ' ';
  }




}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++) {
  //#ifdef DEBUG
  //cout << "Case " << i << ":\n";
  //#endif
  solve();
  //#ifdef DEBUG
  //cout << "============\n";
  //#endif
  }
}