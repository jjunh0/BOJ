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
vector<pi> cand(105);
int N, I, M;

int f(int sx, int sy, int xx, int yy) {
  int ret = 0;
  for(int i = 0; i < M; i ++) {
    if(cand[i].X >= sx && cand[i].X <= sx + xx &&
    cand[i].Y >= sy && cand[i].Y <= sy + yy) ret ++;
  }
  return ret;
}

void solve() {
  cin >> N >> I >> M;
  for(int i = 0; i < M; i ++) {
    int x, y;
    cin >> x >> y;
    cand[i] = {x, y};
  }
  int ans = 0;
  for(int i = 0; i < M; i ++) {
    for(int xx = 1; xx < I/2; xx ++) {
      int yy = I/2 - xx;
      for(int xxx = max(cand[i].X - xx, 1); xxx <= cand[i].X; xxx ++) {
        int ret = f(xxx, cand[i].Y, xx, yy);
        ans = max(ret, ans);
      }
    }
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