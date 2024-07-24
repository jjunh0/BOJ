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

void solve() {
  int n, m;
  cin >> n >> m;
  
  vector<bool> A(n+1);
  vector<pi> B(m);
  for(auto &e : B) cin >> e.Y >> e.X;
  sort(all(B));
  int ans = 0;
  for(int i = 0; i < m; i ++) {
    int x, y;
    tie(y, x) = B[i];
    for(int i = x; i <= y; i ++) {
      if(A[i]) continue;
      A[i] = 1;
      ans ++;
      break;
    }
  }
  cout << ans << '\n';
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}