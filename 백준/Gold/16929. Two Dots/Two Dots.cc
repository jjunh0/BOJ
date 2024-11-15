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
int vis[55][55];
int N, M;
vector<string> A(55);
bool f(int x, int y) {
  bool ret = false;
  for(int dir = 0; dir < 4; dir ++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
    if(A[x][y] != A[nx][ny]) continue;
    if(vis[nx][ny] && abs(vis[nx][ny]- vis[x][y]) > 1) {
      return true;
    }
    if(vis[nx][ny]) continue;
    vis[nx][ny] = vis[x][y] + 1;
    ret |= f(nx, ny);
    vis[nx][ny] = 0;
  }
  return ret;
}

void solve() {
  cin >> N >> M;
  stack<pi> q;
  for(auto &e : A) cin >> e;
  for(int i = 0; i < N; i ++) {
    for(int j = 0; j < M; j ++) {
      vis[i][j] = 1;
      if(f(i, j)) {
        cout << "Yes";
        return;
      }
      vis[i][j] = 0;
    }
  }


  cout << "No";
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