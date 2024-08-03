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
int A[25][25], dp[25][(1<<20)];
int n;

int func(int cur, int bit) {
  if(n == cur) {
    return 0;
  }
  if(dp[cur][bit] != -1) return dp[cur][bit];
  int ret = MX;
  for(int i = 0; i < n; i ++) {
    if(bit & (1<<i)) continue;
    int nbit = bit;
    nbit = nbit | (1<<i);
    ret = min(ret, A[cur][i] + func(cur+1, nbit));
  }
  dp[cur][bit] = ret;
  return ret;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++) {
      cin >> A[i][j];
    }
  }
  for(int i = 0; i < 25; i ++) fill(dp[i], dp[i]+(1<<20), -1);
  cout << func(0, 0);
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