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

const char nl = '\n';
const int mx = 0x3f3f3f3f;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int N, M, K;
int c[30005], dp[3005];
vector<int> p(30005, -1);
vector<int> X, Y;
int ans = 0;


int find(int x) {
  if(p[x] < 0) return x;
  p[x] = find(p[x]);
  return p[x];
}
void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if(a == b) return;
  c[a] += c[b];
  p[a] += p[b];
  p[b] = a;
  c[b] = 0;
}

void solve() {
  cin >> N >> M >> K;
  for(int i = 0; i <N; i ++) {
    cin >> c[i+1];
  }
  while(M--) {
    int a, b;
    cin >> a >> b;
    merge(a, b);
  }
  for(int i = 1; i <= N; i ++) {
    if(p[i] < 0) {
      X.pb(-p[i]);
      Y.pb(c[i]);
    }
  }
  for(int i = 0; i < sz(X); i ++) {
    for(int j = K-1; j >= X[i]; j --) {
      dp[j] = max(dp[j], dp[j-X[i]] + Y[i]);
      ans = max(ans, dp[j]);
    }
  }
  cout << ans << nl;
  
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