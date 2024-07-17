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
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> adj[10005];
vector<int> canVis(10005); // 방문 가능한곳인지 여부
vector<int> light(10005); // 불 킨곳인지 여부
void solve() {
  int n, m;
  cin >> n >> m;
  while(m--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 --; y1 --; x2 --; y2 --;
    adj[x1*n + y1].pb(x2*n+y2);
  }
  canVis[0] = 1;
  light[0] = 1;
  while(1) {
    bool flag = false;
    for(int i = 0; i < n; i ++) {
      for (int j = 0; j < n; j++) {
        if(canVis[i*n+j] == 0) continue;
        for(int nxt : adj[i*n+j]) {
          if(light[nxt]) continue;
          light[nxt] = 1;
          flag = true;
        }
      }
    }
    if(!flag) break;
    vector<int> vis(10005);
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while(sz(q)) {
      int cur = q.front();
      q.pop();
      for(int dir = 0; dir < 4; dir ++) {
        int nx = cur/n + dx[dir];
        int ny = cur%n + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(light[nx*n+ny] == 0 || vis[nx*n+ny]) continue;
        canVis[nx*n+ny] = 1;
        vis[nx*n+ny] = 1;
        q.push(nx*n+ny);
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < n*n; i ++) if(light[i]) ans ++;
  cout << ans;
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