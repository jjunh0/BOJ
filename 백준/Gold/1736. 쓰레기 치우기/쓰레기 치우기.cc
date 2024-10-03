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
int A[105][105], B[105][105];

int N, M;
void f(int x, int y, int cur) {
  if(x >= N) return;
  B[x][y] = cur;
  for(int i = y+1; i < M; i ++) {
    if(A[x][i] && !B[x][i]) {
      f(x, i, cur);
      return;
    }
  }
  f(x+1, y, cur);
}

void solve() {
  cin >> N >> M;
  for(int i = 0; i < N; i ++) {
    for(int j = 0; j < M; j ++) {
      cin >> A[i][j];
    }
  }
  int cur = 1;
  for(int i = 0; i < N; i ++) {
    for(int j = 0; j < M; j ++) {
      if(A[i][j] && !B[i][j]) f(i, j, cur ++);
    }
  }
  cout << cur-1 << nl;
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