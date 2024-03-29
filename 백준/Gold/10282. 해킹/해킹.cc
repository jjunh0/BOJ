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

void solve() {
  int N, D, C;
  cin >> N >> D >> C;
  vector<pi> adj[N+1];
  int a, b, c;
  for(int i = 0; i < D; i ++) {
    cin >> a >> b >> c;
    adj[b].pb({c, a});
  }
  vector<int> d(N+1, mx);
  priority_queue<pi, vector<pi>, greater<pi>> pq;
  pq.push({0, C});
  d[C] = 0;
  while(!pq.empty()) {
    int c, cur;
    tie(c, cur) = pq.top();
    pq.pop();
    for(auto e : adj[cur]) {
      if(e.X + c < d[e.Y]) {
        d[e.Y] = e.X + c;
        pq.push({e.X+ c, e.Y});
      }
    }
  }
  int ans = 0, cnt = 0;
    for(int i = 1; i <= N; i ++) {
      if(d[i] != mx) {
        ans = max(ans, d[i]);
        cnt ++;
      }
    }
    cout << cnt << ' ' << ans << nl;

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