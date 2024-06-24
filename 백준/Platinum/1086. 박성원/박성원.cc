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
#define int ll
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, k;
string A[25];
int md10[55], mdA[25];
int dp[(1<<15)][105];

int fac(int n) {
  if(n == 1) return 1;
  return n * fac(n-1);
}

int func(int vis, int md) { // vis를 사용했고 사용할때까지 나머지가 md일때 나머지가 0일수 있게 만드는 경우의 수
  if(vis == (1<<n)-1) {
    if(md) return 0;
    else return 1;
  }
  if(dp[vis][md] != -1) return dp[vis][md];
  dp[vis][md] = 0;
  for(int i = 0; i < n; i ++) {
    if(vis & (1<<i)) continue;
    dp[vis][md] += func(vis | (1<<i), (md*md10[sz(A[i])] + mdA[i])%k);
  }
  return dp[vis][md];
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i ++) {
    cin >> A[i];
  }
  cin >> k;
  for(int i = 0; i < (1<<n); i ++) fill(dp[i], dp[i]+k+1, -1);
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < sz(A[i]); j ++) {
      mdA[i] = (mdA[i]*10 + (A[i][j]-'0'))%k;
    }
  }
  md10[0] = 1%k;
  for(int i = 1; i <= 50; i ++) {
    md10[i] = (md10[i-1] * 10) %k;
  }
  int a1 = func(0, 0);
  int a2 = fac(n);
  int G = __gcd(a1, a2);
  cout << a1/G << '/' << a2/G;
}

// ************************************

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
        solve();
    }
}