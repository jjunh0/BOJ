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
const int INF = 0x3f3f3f3f;
int dis[505][505];
void solve() {
  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= n; i ++) fill(dis[i], dis[i]+n+1, INF);

  while(m--) {
    int x, y;
    cin >> x >> y;
    dis[x][y] = 1;
  }
  for(int k = 1; k <= n; k ++) {
    for(int i = 1; i <= n; i ++) {
      for(int j = 1; j <= n; j ++) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i ++) {
    int cnt = 0;
    for(int j = 1; j <= n; j ++) {
      if(j == i) continue;
      if(dis[j][i] != INF) cnt ++;
    }
    for(int j = 1; j <= n; j ++) {
      if(j == i) continue;
      if(dis[i][j] != INF) cnt ++;
    }
    if(cnt == n-1) ans ++;
  }
  cout << ans;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
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