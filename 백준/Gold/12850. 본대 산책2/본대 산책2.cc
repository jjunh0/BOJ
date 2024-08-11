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
typedef vector<int> vi;
typedef vector<ll> vl;
#define int ll
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<vector<int>> matrix_mul(vector<vector<int>> a) {
  vector<vector<int>> b(8, vector<int>(8, 0));
  for(int k = 0; k < 8; k ++) {
    for(int i = 0; i < 8; i ++) {
      for(int j = 0; j < 8; j ++) {
        b[i][j] += (a[i][k] * a[k][j]) % MOD;
        b[i][j] %= MOD;
      }
    }
  }
  return b;
}

vector<vector<int>> func(int cur, vector<vector<int>> a) {
  if(cur == 1) return a;
  vector<vector<int>> b = func(cur/2, a);
  b = matrix_mul(b);
  if(cur%2) {
    vector<vector<int>> c(8, vector<int>(8, 0));
    for(int k = 0; k < 8; k ++) {
      for(int i = 0; i < 8; i ++) {
        for(int j = 0; j < 8; j ++) { 
          c[i][j] += (b[i][k]*a[k][j]) % MOD;
          c[i][j] %= MOD;
        }
      } 
    }
    return c;
  }
  else return b;
}

void solve() {
  int d;
  cin >> d;
  vector<vector<int>> a = {
    {0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 1},
    {0, 1, 0, 1, 0, 1, 1, 0},
    {0, 0, 1, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 1, 0, 0, 1, 0, 1},
    {1, 1, 0, 0, 0, 0, 1, 0}
  };
  a = func(d, a);
  cout << a[0][0]; 
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