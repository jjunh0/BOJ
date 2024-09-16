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
typedef vector<vector<ll>> vvi;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const ll MOD = 1000;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

ll N, b;

vvi matrixMul(vvi A, vvi B) {
  vvi ret(N, vector<ll>(N, 0));
  for(int i = 0; i < N; i ++) {
    for(int j = 0; j < N; j ++) {
      for(int k = 0; k < N; k ++) {
        ret[i][j] += A[i][k] * B[k][j] % MOD;
        ret[i][j] %= MOD;
      }
    }
  }
  return ret;
}

vvi pw(vvi A, ll sq) {
  if(sq == 1) return A;
  vvi ret = pw(A, sq/2);
  ret = matrixMul(ret, ret);
  if(sq%2) ret = matrixMul(ret, A);
  return ret; 
}

void solve() {
  cin >> N >> b;
  vvi A(N, vector<ll>(N));
  for(int i = 0; i < N; i ++) {
    for(int j = 0; j < N; j ++) {
      cin >> A[i][j];
    }
  }
  A = pw(A, b);
  for(int i = 0; i < N; i ++) {
    for(int j = 0; j < N; j ++) {
      cout << A[i][j]%MOD << ' ';
    }
    cout << nl;
  }

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