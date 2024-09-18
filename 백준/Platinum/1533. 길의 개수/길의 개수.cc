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
const int MOD = 1000003;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int N, S, E, T;

vvi mul(vvi &a, vvi &b) {
  vvi ret(5*N+5, vector<ll>(5*N+5, 0));
  for(int i = 1; i <= 5*N; i ++) {
    for(int j = 1; j <= 5*N; j ++) {
      for(int k = 1; k <= 5*N; k ++) {
        ret[i][j] += a[i][k] * b[k][j] % MOD;
        ret[i][j] %= MOD;
      }
    }
  }
  return ret;
}
vvi pw(vvi A, int sq) {
  if(sq == 1) return A;
  vvi ret = pw(A, sq/2);
  ret = mul(ret, ret);
  if(sq%2) ret = mul(ret, A);
  return ret;
}

void solve() {
  cin >> N >> S >> E >> T;
  vvi A(5*N+1, vector<ll>(5*N+1));
  for(int i = 1; i <= N; i ++) {
    for(int j = 1; j < 5; j ++) {
      A[i*5 - j][i*5 - j + 1] = 1;
    }
  }
  for(int i = 1; i <= N; i ++) {
    string s;
    cin >> s;
    for(int j = 0; j < N; j ++) {
      if(s[j] == '0') continue;
      A[i*5][(j+1)*5 - (s[j]-'0') + 1] = 1;
    }
  }
  A = pw(A, T);

  cout << A[S*5][E*5]%MOD;
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