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
int vis[105];
vector<int> adj[105];

void solve() {
  int N, X, Y, M;
  cin >> N >> X >> Y >> M;
  for(int i = 0; i < M; i ++) {
    int x, y;
    cin >> x >> y; 
    adj[x].pb(y);
    adj[y].pb(x);
  }
  queue<int> q;
  q.push(X);
  vis[X] = 1;
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(auto nxt : adj[cur]) {
      if(vis[nxt]) continue;
      vis[nxt] = vis[cur] + 1;
      q.push(nxt);
    }
  }
  cout << (vis[Y] > 0 ? vis[Y]-1 : -1); 

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