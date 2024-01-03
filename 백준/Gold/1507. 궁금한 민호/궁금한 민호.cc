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

int dist[25][25];
int adj[25][25];
void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= n; j ++) {
      cin >> dist[i][j];
      adj[i][j] = dist[i][j];
    }
  }

  for(int k = 1; k <= n; k ++) {
    for(int i = 1; i <= n; i ++) {
      for(int j = 1; j <= n; j ++) {
        if(i == k || j == k) continue;
        if(dist[i][j] == dist[i][k] + dist[k][j]) adj[i][j] = mx;
        if(dist[i][k] + dist[k][j] < dist[i][j]) {
          cout << -1;
          return;
        }
      }
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; i ++) {
    for(int j = i+1; j <= n; j ++) {
      if(adj[i][j] != mx) ans += dist[i][j];
    }
  }
  cout << ans;

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