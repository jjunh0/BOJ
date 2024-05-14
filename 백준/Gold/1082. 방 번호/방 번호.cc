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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
int p[55];

int cmp(string a, string b) {
  if(sz(a) != sz(b)) return sz(a) < sz(b);
  return a < b;
}

string dp[55];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i ++) cin >> p[i];
  cin >> m;
  for(int i = 0; i <= m; i ++) {
    for(int j = 0; j < n; j ++) {
        if(i - p[j] < 0) continue;
        char cur = '0' + j;
        if(cmp(dp[i], cur + dp[i-p[j]])) dp[i] = cur + dp[i-p[j]];
      }
  }
  string ans = "";
  for(int i = 0; i <= m; i ++) {
    string t = "";
    for(int j = 1; j < n; j ++) {
      if(i - p[j] < 0) continue;
      char cur = '0' + j;
      if(cmp(t, cur + dp[i-p[j]])) {
        t = cur + dp[i-p[j]];
      }
    }
    if(cmp(ans, t)) ans = t;
  }
  if(sz(ans) == 0) cout << 0;
  else cout << ans;
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