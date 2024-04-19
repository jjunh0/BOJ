#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define ll long long

using namespace std;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';
const int mx = 0x3f3f3f3f;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int board[15][15];
vi X, Y;
bool flag = false;
bool row[10][10], col[10][10], area[10][10];


void func(int cur) {
  if(cur == sz(X)) {
    flag = true;
    for(int i = 0; i < 9; i ++) {
      for(int j = 0; j < 9; j ++) { 
        cout << board[i][j];
      } 
      cout << nl;
    }
    return;
  }
  int i = X[cur];
  int j = Y[cur];


  int r, c, a; 
  r = i; c = j; a = (i/3)*3 + j/3;
  for(int k = 1; k <= 9; k ++) {
    if(row[r][k] || col[c][k] || area[a][k]) continue;
    board[i][j] = k;
    row[r][k] = 1; col[c][k] = 1; area[a][k] = 1;
    func(cur+1);
    row[r][k] = 0; col[c][k] = 0; area[a][k] = 0;
    if(flag) return;
  }
  board[i][j] = 0;
}

void solve() {
  string s;
  int r, c, a; 
  for(int i = 0; i < 9; i ++) {
    cin >> s;
    for(int j = 0; j < 9; j ++) {
      board[i][j] = s[j]-'0';
      if(board[i][j] == 0) {
        X.pb(i);
        Y.pb(j);
      }
      else {
        r = i; c = j; a = (i/3)*3 + j/3;
        int k = board[i][j];
        row[r][k] = 1; col[c][k] = 1; area[a][k] = 1;

      }
      
    }
  }
  func(0);

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