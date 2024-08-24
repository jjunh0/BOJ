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

string a[8] = {
                "WBWBWBWB",
                "BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW"
              }, b[8] = {
                "BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW",
                "WBWBWBWB"
              };

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> A(n);
  for(auto &e : A) cin >> e;
  int ans = MX;
  for(int i = 0; i <= n-8; i ++) {
    for(int j = 0; j <= m-8; j ++) {
      int cnt1 = 0, cnt2 = 0;
      for(int x = 0; x < 8; x ++) {
        for(int y = 0; y < 8; y ++) {
          if(a[x][y] != A[i+x][j+y]) cnt1 ++;
          if(b[x][y] != A[i+x][j+y]) cnt2 ++;
        }
      }
      ans = min(ans, min(cnt1, cnt2));
    }
  }
  cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
        solve();
    }
}