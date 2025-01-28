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

int A[1005][1005], dp[1005][1005][5];
int N;

int f(int x, int y, int val) {
  if(x >= N || y >= N) return 0;
  if(dp[x][y][val] >= 0) return dp[x][y][val];
  dp[x][y][val] = 0;
  if(val == A[x][y]) {
    dp[x][y][val] = max(dp[x][y][val], 1 + f(x+1, y, (val+1)%3));
    dp[x][y][val] = max(dp[x][y][val], 1 + f(x, y+1, (val+1)%3));
  }
  dp[x][y][val] = max(dp[x][y][val], f(x+1, y, val));
  dp[x][y][val] = max(dp[x][y][val], f(x, y+1, val));
  return dp[x][y][val];
}

void solve() {
  cin >> N;
  memset(dp, -1, sizeof(dp));
  for(int i = 0; i < N; i ++) {
    for(int j = 0; j < N; j ++) {
      cin >> A[i][j];
    }
  }
  cout << f(0, 0, 0);
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