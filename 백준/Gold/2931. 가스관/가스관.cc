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
const int mx = 0x3f3f3f3f;

int dx[] = {-1, 0, 1, 0}; // 위 오른쪽 아래 왼  
int dy[] = {0, 1, 0, -1};

char board[30][30];
char cand[] = {'|', '-', '+', '1', '2', '3', '4'};
int vis[30][30];
map<char, int> mp;
int x, y;
int n, m;
vector<int> df[8] = {{0, 2}, {1, 3}, {0, 1, 2, 3}, {1, 2}, {0, 1}, {0, 3}, {2, 3}, {0, 1, 2, 3}};


bool dfs() {
  for(int l = 0; l < n; l ++) fill(vis[l], vis[l]+m, 0);
  queue<pi> q;
  vis[x][y] = 1;
  for(int i = 0; i < 4; i ++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if(board[nx][ny] != '.' && board[nx][ny] != 'Z') q.push({nx, ny});
  }
  bool flag = false;
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    int d = mp[board[cur.X][cur.Y]];
    for(int dir = 0; dir < sz(df[d]); dir ++) {
      int ndir = df[d][dir];
      int nx = cur.X + dx[ndir];
      int ny = cur.Y + dy[ndir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) return false;
      if(board[nx][ny] == 'Z' || board[nx][ny] == 'M') {
        flag = true;
        continue;
      }
      if(ndir == 0 && !(board[nx][ny] == '|' || board[nx][ny] == '+'|| board[nx][ny] == '1' || board[nx][ny] == '4')) return false;
      if(ndir == 1 && !(board[nx][ny] == '-' || board[nx][ny] =='+' || board[nx][ny] == '3' || board[nx][ny] == '4')) return false;
      if(ndir == 2 && !(board[nx][ny] == '|' || board[nx][ny] == '+' || board[nx][ny] == '2' || board[nx][ny] == '3')) return false;
      if(ndir == 3 && !(board[nx][ny] == '-' || board[nx][ny] == '+' || board[nx][ny] == '1' || board[nx][ny] == '2')) return false; 
      if(vis[nx][ny] != 0) continue;
      q.push({nx, ny});
      vis[nx][ny] = 1;
    }
  }
  return flag;
}

void solve() {
  cin >> n >> m;
  mp['|'] = 0;
  mp['-'] = 1;
  mp['+'] = 2;
  mp['1'] = 3;
  mp['2'] = 4;
  mp['3'] = 5;
  mp['4'] = 6;
  mp['M'] = 7;
  mp['S'] = 7;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) { 
      cin >> board[i][j];
      if(board[i][j] == 'M') {
        x = i;
        y = j;
      }
    } 
  }
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) {
      if(board[i][j] != '.') continue;
      for(int k = 0; k < 7; k ++) {
        board[i][j] = cand[k];
        if(dfs()) {
          cout << i+1 << ' ' << j+1 << ' ' << board[i][j];
          return;
        }
        board[i][j] = '.';
      }
    }
  }
  cout << -1;
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