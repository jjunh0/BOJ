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
bool vis[305][305];
void solve() {
  int N, M;
  cin >> N >> M;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  x1 --, y1 --, x2 --, y2 --;
  vector<string> A(N);
  for(auto &e : A) cin >> e;
  priority_queue<ti, vector<ti>, greater<ti>> pq;
  pq.push({1, x1, y1});
  while(!pq.empty()) {
    auto [cnt, x, y] = pq.top();
    pq.pop();
    if(x == x2 && y == y2) {
      cout << cnt;
      return;
    }
    for(int dir = 0; dir < 4; dir ++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx < 0 || nx >= N || ny< 0 || ny >= M) continue;
      if(vis[nx][ny]) continue;
      int ncnt = cnt;
      if(A[nx][ny] == '1') ncnt ++;
      pq.push({ncnt, nx, ny});
      vis[nx][ny] = 1;
    }
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