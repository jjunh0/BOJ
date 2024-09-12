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

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> A(n, vector<int>(n));
  for(int i = 0; i < n; i ++) {
    string s;
    cin >> s;
    for(int j = 0; j < n; j ++) {
      if(s[j] == 'T') A[i][j] = 1;
      else A[i][j] = 0;
    }
  }
  int ans = MX;
  for(int bit = 0; bit < (1<<n); bit ++) {
    auto B = A;
    for(int i = 0; i < n; i ++) {
      if((bit >> i) & 1) {
        for(int j = 0; j < n; j ++) {
          B[i][j] = !B[i][j];
        }
      }
    }
    int cur = 0;
    for(int j = 0; j < n; j ++) {
      int cnt = 0;
      for(int i = 0; i < n; i ++) {
        if(B[i][j]) cnt ++;
      }
      cur += min(cnt, n-cnt);
    }
    ans = min(ans, cur);
  }
  cout << ans;
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