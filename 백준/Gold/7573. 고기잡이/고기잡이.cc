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
  int N, I, M;
  cin >> N >> I >> M;
  vector<pi> cand(M);
  for(int i = 0; i < M; i ++) {
    int x, y;
    cin >> x >> y;
    cand[i] = {x, y};
  }
  int ans = 0;
  sort(all(cand));
  for(int i = 0; i < M; i ++) {
    for(int j = 0; j < M; j ++) {
      int rec_x = cand[i].X;
      int rec_y = cand[j].Y;
      for(int ri = 1; ri < I/2; ri ++) {
        int rj = I/2 - ri;
        int cnt = 0; 
        for(int k = 0; k < M; k ++) {
          if(cand[k].X >= rec_x && cand[k].X <= rec_x + ri &&
            cand[k].Y >= rec_y && cand[k].Y <= rec_y + rj) cnt ++;
        }
        ans = max(ans, cnt);
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