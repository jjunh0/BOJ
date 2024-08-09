#include <bits/stdc++.h>
using namespace std;

char board[15][15];
char board_[15][15];
char tmp[15][15];
int n, m;
int ans = 15;
int rx, ry;
int bx, by;
bool flag = false;
void roll() {
  swap(n, m);
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) { 
      tmp[i][j] = board_[m-1-j][i];
    } 
  }

  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) { 
      board_[i][j] = tmp[i][j];
    } 
  }

} 

bool func() { // r, b 동시에
  bool r = false;
  int i = rx+1;
  while(board_[i][ry] == '.') {
    i ++;
  }
  if(board_[i][ry] == 'O') {
    board_[rx][ry] = '.';
    r = true;
  }
  else if(board_[i][ry] == '#') {
    board_[rx][ry] = '.';
    rx = i - 1;
    board_[rx][ry] = 'R';
  }
  i = bx+1;
  while(board_[i][by] == '.') {
    i++;
  }
  if(board_[i][by] == 'O') {
    r = true;
    flag = true;
  }
  else  {
    board_[bx][by] = '.';
    bx = i-1;
    board_[bx][by] = 'B';
  }
  return r;
}
bool func2() { // r, b 동시에
  bool r = false;
  int i = bx+1;
  while(board_[i][by] == '.') {
    i++;
  }
  if(board_[i][by] == 'O') {
    board_[bx][by] = '.';
    r = true;
    flag = true;
  }
  else if(board_[i][by] == '#') {
    board_[bx][by] = '.';
    bx = i-1;
    board_[bx][by] = 'B';
  }
  i = rx+1;
  while(board_[i][ry] == '.') {
    i ++;
  }
  if(board_[i][ry] == 'O') {
    r = true;
  }
  else {
    board_[rx][ry] = '.';
    rx = i - 1;
    board_[rx][ry] = 'R';
  }

  return r;
}

void solve() {
  cin >> n >> m;
  int n_ = n; int m_ = m;
  for(int i = 0; i < n; i ++) {
    string s;
    cin >> s;
    for(int j = 0; j < m; j ++) {     
      board[i][j] = s[j];   
      if(board[i][j] == 'R') {
        rx = i; ry = j;
      }
      else if(board[i][j] == 'B') {
        bx = i; by = j;
      }
    } 
  }

  for(int cases = 0; cases < (1<<20); cases ++) {
    n = n_; m = m_;
    int cnt = 0;
    flag = false;
    for(int i = 0; i < n; i ++) {
      for(int j = 0; j < m; j ++) { 
        board_[i][j] = board[i][j];
      } 
    }
    int brute = cases;
    for(int i = 0; i < 10; i ++) {
      cnt ++;
      int dir = brute % 4;
      brute /= 4;
      if(i != 0 && dir == 0) break;
      while(dir --) roll();
      for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) { 
          if(board_[i][j] == 'R') {
            rx = i; ry = j;
          }
          else if(board_[i][j] == 'B') {
            bx = i; by = j;
          }
        } 
      }
      if(bx < rx) {
        if(func()) {
          if(!flag) {
            ans = min(cnt, ans);
          }
          break;
        }
      }
      else {
        if(func2()) {
          if(!flag) {
            ans = min(cnt, ans);
          }
          break;
        }     
      }

    } 
  }
  if(ans <= 10)
    cout << ans;
  else
    cout << -1;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}