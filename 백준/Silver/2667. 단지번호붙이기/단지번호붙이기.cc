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
int board[30][30];

const int N = 1000;
vector<int> p(N, -1);
int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool merge(int a, int b) {
  a = find(a);
  b = find(b);
  if(a == b) return 0;
  p[a] += p[b];
  p[b] = a;
  return 1;
}

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i ++) {
    string s;
    cin >> s;
    for(int j = 0; j < n; j ++) {
      board[i][j] = s[j]-'0';
    }
  }
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++) {
      if(board[i][j] == 0) continue;
      for(int dir = 0; dir < 4; dir ++) {
        int nx = i+dx[dir];
        int ny = j + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 0) continue;
        merge(nx*n+ ny, i*n + j);
      }
    }
  }
  vector<int> vis(n*n), ans;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++) {
      if(board[i][j] == 0) continue;
      int cur = find(i*n+j);
      if(vis[cur]) {
        continue;
      }
      else {
        vis[cur] = 1;
        ans.pb(-p[cur]);
      }
    }
  }
  sort(all(ans));
  cout << sz(ans) << nl;
  for(auto e : ans) cout << e << nl;
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