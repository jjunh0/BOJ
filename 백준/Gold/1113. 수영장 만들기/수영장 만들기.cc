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
int A[55][55];
bool vis[55][55];
void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i ++) {
    string s;
    cin >> s;
    for(int j = 0; j < m; j ++) {
      A[i][j] = s[j] - '0';
    }
  }
  queue<pi> q;
  int ans = 0;
  for(int h = 1; h < 10; h ++) {
    for(int i = 0; i < n; i ++) {
      for(int j = 0; j < m; j ++) {
        if(A[i][j] != h) continue;
        q.push({i, j});
        for(int i = 0; i < n; i ++) fill(vis[i], vis[i] + m, 0);
        bool flag = false;
        int mn = MX;
        while(!q.empty()) {
          auto cur = q.front();
          q.pop();
          for(int dir = 0; dir < 4 && !flag; dir ++) {
            int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
              flag = true;
              continue;
            }
            if(A[i][j] < A[nx][ny]) {
              mn = min(mn, A[nx][ny]);
              continue;
            }
            if(vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
          }
        }
        if(!flag) {
          ans += mn - A[i][j];
          A[i][j] = mn;
        }
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