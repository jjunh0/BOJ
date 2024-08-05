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
int board[105];
int p[105];

int find(int x) {
  if(p[x] == -1) return x;
  return p[x] = find(p[x]);
}

bool merge(int a, int b) {
  a = find(a);
  b = find(b);
  if(a == b) return 1;
  p[a] = b;
  return 0;
}

void solve() {
  int n, m, T = 0;
  cin >> n >> m;
  fill(p, p+105, -1);
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) {
      cin >> board[i*m+j];
      if(board[i*m+j]) T ++;
    }
  }
  vector<ti> A;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) {
      if(board[i*m + j] == 0) continue;
      for(int dir = 0; dir < 4; dir ++) {
        int nx = i, ny = j, cnt = 0;
        while(1) {
          nx += dx[dir];
          ny += dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) break;
          if(board[nx*m + ny] == 1) {
            if(cnt != 1)
              A.pb({cnt, i*m+j, nx*m+ny});
            break;
          }
          cnt ++;
        }
      }
    }
  }
  sort(all(A));
  int ans = 0, cnt = 0;
  for(int i = 0; i < sz(A); i ++) {
    int cost, a, b;
    tie(cost, a, b) = A[i];
    if(merge(a, b)) continue;
    ans += cost;
    cnt ++;
  }
  cout << (T-1 == cnt ? ans : -1);  
}

// ************************************

int main() {
    // ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
        solve();
    }
}