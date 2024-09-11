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
typedef tuple<int, int, int> ti;
typedef pair<ll,ll> pl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
string A[20];
int dp[20][10][(1<<15)];
int n;
// bit이 선택됐을때 cur에서 갈 수 있는 
int f(int cur, int price, int bit) {
  if(dp[cur][price][bit] != -1) return dp[cur][price][bit];
  int ret = 0;
  for(int i = 0; i < n; i ++) {
    if((bit >> i) & 1) continue;
    int nbit = (bit | (1<<i));
    int p = A[cur][i] - '0';
    if(p >= price) {
      ret = max(ret, 1+f(i, p, nbit));
    }
  }
  dp[cur][price][bit] =ret;
  return ret;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i ++) cin >> A[i];
  for(int i = 0; i < 20; i ++) for(int j = 0; j < 10; j ++) fill(dp[i][j], dp[i][j]+(1<<15), -1);
  cout << 1+f(0, 0, 1);
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests = 1;
    while(tests--) {
        solve();
    }
}