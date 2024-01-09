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

vector<int> p(505);
vector<int> pre(505);
int dp[505][505];

int func(int x, int y) {
  if(dp[x][y] != mx) return dp[x][y];
  if(x == y) return 0;
  for(int i = x; i <= y-1; i ++) {
    dp[x][y] = min(dp[x][y], func(x, i) + func(i+1, y) + pre[y+1] - pre[x]);
  }
  return dp[x][y];
}

void solve() {
  int k;
  cin >> k;
  fill(all(pre), 0);
  for(int i = 0; i < k; i ++) {
    cin >> p[i];
    fill(dp[i], dp[i]+k+1, mx);
  }
  pre[1] = p[0];
  for(int i = 1; i < k; i ++) {
    pre[i+1] = p[i] + pre[i];
  }
  
  cout << func(0, k-1) << nl;

}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
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