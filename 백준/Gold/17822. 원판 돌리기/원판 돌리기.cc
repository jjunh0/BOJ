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
  const int MX = 0x3f3f3f3f;
  const int MOD = 1'000'000'007;

  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  int board[55][55];
  void solve() {
    int n, m, T;
    cin >> n >> m >> T;
    for(int i = 1; i <= n; i ++) {
      for(int j = 0; j < m; j ++) {
        cin >> board[i][j];
      }
    }
    while(T--) {
      int x, d, k;
      cin >> x >> d >> k;
      for(int i = x; i <= n; i += x) {
        int tmp[m+1];
        for(int j = 0; j < m; j ++) {
          if(d == 0) {
            tmp[(j+k)%m] = board[i][j];
          }
          else {
            tmp[(j-k+m)%m] = board[i][j];
          }
        }
        for(int j = 0; j < m; j ++) board[i][j] = tmp[j];
      }
      vector<vector<bool>> vis(n+1, vector<bool>(m+1));
      for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < m; j ++) {
          int cur = board[i][j];
          if(i-1 >= 1 && board[i-1][j] == cur) {
            vis[i-1][j] = 1;
          }
          if(board[i][(j+1)%m] == cur) {
            vis[i][(j+1)%m] = 1;
          }
          if(board[i][(j+m-1)%m] == cur) {
            vis[i][(j+m-1)%m] = 1;
          }
          if(i+1 <= n && board[i+1][j] == cur) {
            vis[i+1][j] = 1;
          }
        }
      }
      int sum = 0, flag = 0, cnt = 0;
      for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < m; j ++) {
          if(!board[i][j]) continue;
          sum += board[i][j];
          cnt ++;
          if(vis[i][j]) {
            flag = 1;
            board[i][j] = 0;
          }
        }
      }
      if(cnt != 0 && !flag) {
        double avg = 1. * sum / cnt;
        for(int i = 1; i <= n; i ++) {
          for(int j = 0; j < m; j ++) {
            if(!board[i][j]) continue;
            if(board[i][j] > avg) {
              board[i][j] --;
            }
            else if(board[i][j] < avg) {
              board[i][j] ++;
            }
          }
        }
      }
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
      for(int j = 0; j < m; j ++) { 
        ans += board[i][j];
      } 
    }
    cout << ans;
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