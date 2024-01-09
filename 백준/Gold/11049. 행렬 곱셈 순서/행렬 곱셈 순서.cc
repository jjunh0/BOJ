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
const int mx = 0x7fffffff;
vector<pi> a(505);
int dp[505][505];
int func(int x, int y) {
  if(dp[x][y] != mx) return dp[x][y];
  if(x == y) return 0;
  for(int i = x; i <= y-1; i ++) {
    dp[x][y] = min(dp[x][y], func(x,i) + func(i+1, y) + a[x].X * a[i].Y * a[y].Y);
  }
  return dp[x][y];
}

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i ++) {
    cin >> a[i].X >> a[i].Y;
    fill(dp[i], dp[i]+n+1, mx);
  }  
  cout << func(0, n-1);
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