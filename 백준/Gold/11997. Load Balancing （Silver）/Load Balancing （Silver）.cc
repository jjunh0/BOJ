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

int pre[1005][1005];
int val[1005][1005];
vector<int> x, y, px, py;
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i ++) {
    int xx, yy;
    cin >> xx >> yy;
    x.pb(xx);
    y.pb(yy);
  }
  px = x; py = y;
  sort(all(px)); 
  sort(all(py));
  px.erase(unique(all(px)), px.end());
  py.erase(unique(all(py)), py.end());

  for(int i = 0; i < n; i ++) {
    x[i] = lower_bound(all(px), x[i]) - px.begin();
    y[i] = lower_bound(all(py), y[i]) - py.begin();
    val[x[i]][y[i]] ++;
  }
  // for(int i = 1; i < n; i ++) {
  //   pre[0][i] += pre[0][i-1];
  // }
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++) {
      //pre[i+1][j+1] += pre[i+1][j] + pre[i][j+1] - pre[i][j] + val[i+1][j+1];
      pre[i+1][j+1] = pre[i+1][j] + pre[i][j+1] - pre[i][j] + val[i][j];
    }
  }

  int ans = 1000005;
  for(int i = 0; i <= n; i ++) {
    for(int j = 0; j <= n; j ++) {
      int a, b , c;
      a = pre[i][j];
      b = pre[n][j] - pre[i][j];
      c = pre[i][n] - pre[i][j];
      ans = min(ans, max({a, b, c, pre[n][n] - a - b - c}));
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