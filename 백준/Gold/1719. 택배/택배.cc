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

int dist[205][205];
int nxt[205][205]; 

void solve() {

  int n, m;
  cin >> n >> m;

  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++) { 
        dist[i+1][j+1] = mx;
    } 
  }

  for(int i = 1; i <= n; i ++) dist[i][i] = 0;

  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    dist[a][b] = c;
    dist[b][a] = c;
    nxt[a][b] = b;
    nxt[b][a] = a;
  }

  for(int k = 1; k <= n; k ++) {
    for(int i = 1; i <= n; i ++) {
      for(int j = 1; j <= n; j ++) { 
        if(dist[i][k]+dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          nxt[i][j] = nxt[i][k];
        }
      } 
    }
  }
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= n; j ++) {
      if(dist[i][j] == mx || dist[i][j] == 0) cout << "- ";
      else cout << nxt[i][j] << ' ';
    }
    cout << nl;
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