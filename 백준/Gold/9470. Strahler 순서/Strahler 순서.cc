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
int deg[1005];
pi val[1005];
void solve() {
  int k, m, p;
  cin >> k >> m >> p;
  for(int i = 1; i <= m; i ++) val[i] = {-1, -1};
  fill(deg, deg+1005, 0);
  vector<int> adj[1005];
  
  for(int i = 0; i < p; i ++) {
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    deg[b] ++;
  }
  queue<int> q;
  for(int i = 1; i <= m; i ++) {
    if(deg[i] == 0) {
      q.push(i);
      val[i] = {1, 0};
    }
  } 
  while(!q.empty()) {
    int cur = q.front();
    if(val[cur].Y >= 2) val[cur].X ++;
    q.pop();
    for(auto nxt : adj[cur]) {
      deg[nxt] --;
      if(!deg[nxt]) q.push(nxt);
      if(val[nxt].X == val[cur].X) val[nxt].Y ++;
      else if(val[nxt].X < val[cur].X)val[nxt] = {val[cur].X, 1};
    }
  }
  cout << k << ' ' << val[m].X << nl;

}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}