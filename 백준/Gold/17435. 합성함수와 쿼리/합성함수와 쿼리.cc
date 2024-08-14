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

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int nxt[200005][20];
void solve() {
  int m, q;
  cin >> m;
  for(int i = 1; i <= m; i ++) {
    int t;
    cin >> t;
    nxt[i][0] = t;
  }
  for(int j = 1; (1<<j) <= 500000; j ++) {
    for(int i = 1; i <= m; i ++) {
      nxt[i][j] = nxt[nxt[i][j-1]][j-1];
    }
  }
  cin >> q;
  while(q--) {
    int n, x;
    cin >> n >> x;
    int cur = x;
    for(int i = 0; n != 0; i ++) {
      if(n%2) {
        cur = nxt[cur][i];
      }
      n/= 2;
    }
    cout << cur << nl;
  }

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