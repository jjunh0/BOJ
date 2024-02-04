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

int board[20][20];
int n, m, d;
int ans = 0;
int nxt[20][20], b[20][20];

void setBoard() {
  for(int i = 0; i <= n; i ++) {
    for(int j = 0; j < m; j ++) { 
      b[i][j] = board[i][j];
      nxt[i][j] = b[i][j];
    } 
  }
}

void func() {
  int cnt = 0;
  setBoard();
  for(int l = 0; l <= n; l ++) {
    for(int k = 0; k < m; k++) {
      if(!b[n][k]) continue;
      bool flag = false;
      for(int dd = 1; dd <= d; dd ++) {
        for(int i = min(k - dd, 0); i < m; i ++) {
          for(int j = 1; j <= min(dd - abs(k-i), n); j ++) {
            if(!b[n - j][i]) continue;
            if(nxt[n-j][i] != 0) cnt ++;
            nxt[n-j][i] = 0;
            flag = true;
            break;
          }
          if(flag) break;
        } 
        if(flag) break;
      }
    }
    // for(int i = 0; i <= n; i ++) {
    //   for(int j = 0; j < m; j ++) { 
    //     cout << nxt[i][j] << ' ';
    //   } 
    //   cout << nl;
    // }
    // cout << nl;
    
    for(int i = n-2; i >= 0; i --) {
      for(int j = 0; j < m; j ++) {
        nxt[i+1][j] = nxt[i][j];
      }
    }
    for(int i = 0; i < m; i ++) nxt[0][i] = 0;

    for(int i = 0; i <= n; i ++) {
      for(int j = 0; j < m; j ++) { 
        b[i][j] = nxt[i][j];
      } 
    }
  }
  ans = max(ans, cnt);

}

void solve() {
  cin >> n >> m >> d;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) {
      cin >> board[i][j];
    }
  }
  for(int i = 0; i < m; i ++) {
    for(int j = i+1; j < m; j ++) {
      for(int k = j+1; k < m; k ++) {
        board[n][i] = 1;
        board[n][j] = 1;
        board[n][k] = 1;
        func();
        board[n][i] = 0;
        board[n][j] = 0;
        board[n][k] = 0;
      }
    }
  }
  cout << ans;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++) {
  //#ifdef DEBUG
  //cout << "Case " << i << ":\n";
  //#endif
  solve();
  //#ifdef DEBUG
  //cout << "============\n";
  //#endif
  }
}