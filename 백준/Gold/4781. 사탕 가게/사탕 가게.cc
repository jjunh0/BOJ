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

int N, M;
int X[5005];
int Y[5005];
int dp[10005];

int func(int m) {
  if(m == 0) {
    return 0;
  }
  if(dp[m] != -1) return dp[m];
  dp[m] = 0;
  for(int i = 1; i <= N; i ++) {
    if(m - Y[i] >= 0)
      dp[m] = max(dp[m], X[i] + func(m - Y[i]));
  }
  return dp[m];
}

void solve() {
  for(int i = 1; i <= N; i ++) {
    double t;
    cin >> X[i] >> t;
    Y[i] = t*100 + 0.5;
  }
  for(int j = 0; j < 10005; j ++) dp[j] = -1;
  func(M);
  cout << dp[M] << nl;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt = 1;
  while(tt) {
    double t;
    cin >> N >> t;
    M = t*100;
    if(N == 0) break;
    solve();
  }
}