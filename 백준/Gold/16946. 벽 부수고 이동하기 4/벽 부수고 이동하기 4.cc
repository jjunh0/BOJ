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
int board[1000005];
int p[1000005];

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if(a == b) return;
  p[a] += p[b];
  p[b] = a;
}

void solve() {
  int n, m;
  cin >> n >> m;
  fill(p, p+n*m, -1);
  for(int i = 0; i < n*m; i ++) {
    char c;
    cin >> c;
    board[i] = c-'0';
  }
  for(int i = 0; i < n*m; i ++) {
    if(board[i]) continue;
    int x = i/m, y = i%m;
    for(int dir = 0; dir < 4; dir ++) {
      int nx = x + dx[dir], ny = y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx*m+ny]) continue;
      merge(x*m+y, nx*m+ny);
    }
  }
  for(int i = 0; i < n*m; i ++) {
    if(!board[i]) {
      cout << 0;
      if((i+1)%m == 0) cout << nl;
      continue;
    }
    int x = i/m, y = i%m;
    set<int> st;
    for(int dir = 0; dir < 4; dir ++) {
      int nx = x + dx[dir], ny = y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx*m + ny]) continue;
      st.insert(find(nx*m + ny));
    }
    int cur = 0;
    for(auto e : st) {
      cur -= p[e];
      cur %= 10;
    }
    cout << (cur+1)%10;
    if((i+1)%m == 0) cout << nl;
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