#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[130][7][7][7];
int board_[130][7][7][7];
int shuffled[5] = {0, 1, 2, 3, 4};
int dx[] = {0, 0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 0, -1, 1};
int dz[] = {-1, 1, 0, 0, 0, 0};
int ans = 987654321;
void rotate(int cur, int all_shuffled) {
  int tmp[7][7];
  for(int i = 0; i < 5; i ++) {
    for(int j = 0; j < 5; j ++) {
      tmp[i][j] = board_[all_shuffled][cur][4-j][i];
    }
  }
  for(int i = 0; i < 5; i ++) {
    for(int j = 0; j < 5; j ++) {
      board_[all_shuffled][cur][i][j] = tmp[i][j];

    } 
  }
}
bool flag = false;
void solve() {
  for(int z = 0; z < 5; z ++) {
    for(int x = 0; x < 5; x ++) {
      for(int y = 0; y < 5; y ++) {
        cin >> board[0][z][x][y];
      }
    }
  }
  int shuffle_i = 0;
  int z_index = 0;
  do {
    for(int i = 0; i < 5; i ++) { // shuffled[1] == 1 => z index
      for(int x = 0; x < 5; x ++) 
        for(int y = 0; y < 5; y ++) {
          board[shuffle_i][i][x][y] = board[0][shuffled[i]][x][y];
        }
    }
    //cout << "shuffled_i:" << shuffle_i << ' ';
    shuffle_i ++;
    //for(int i = 0; i < 5; i ++) cout << shuffled[i] << ' '; cout << '\n';
  } while(next_permutation(shuffled, shuffled + 5));
  //cout << shuffle_i;
  for(int all_shuffled = 0; all_shuffled < shuffle_i; all_shuffled ++) {
    for(int tmp = 0; tmp < (1<<10); tmp ++) { 
      //spin
      int b = tmp;
      for(int k = 0; k < 5; k ++) {
        int dir = b % 4;
        b /= 4;
        for(int i = 0; i < 5; i ++)
          for(int j = 0; j < 5; j ++)
            board_[all_shuffled][k][i][j] = board[all_shuffled][k][i][j];
        //cout << k << ' ' << dir << '\n';
        while(dir -- > 0) rotate(k, all_shuffled);

      }
      if(board_[all_shuffled][0][0][0] == 0) continue;
      //suffle 0 ~4 
      
      // solve the maze
      int vis[7][7][7];
      for(int i = 0; i < 5; i ++) 
        for(int j = 0; j < 5; j ++)
          for(int l = 0; l < 5; l ++)
            vis[i][j][l] = 0;

      queue<pair<int, pair<int, int>>> q;
      q.push({0, {0, 0}}); // target : 4, 4, 4
      vis[0][0][0] = 1;
      while(!q.empty()) {
        auto cur = q.front(); q.pop();
        //cout << cur.X << ' ' << cur.Y.X << ' ' << cur.Y.Y << '\n';
        for(int dir = 0; dir < 6; dir ++) {
          int nz = cur.X + dz[dir];
          int nx = cur.Y.X + dx[dir];
          int ny = cur.Y.Y + dy[dir];
          //cout << nz << ' ' << nx << ' ' << ny << '\n';
          if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
          if(vis[nz][nx][ny] > 0 || board_[all_shuffled][nz][nx][ny] == 0) continue;
          if(nx == 4 && ny == 4 && nz == 4) {
            // cout << all_shuffled << '\n';
            // for(int k = 0; k < 5; k ++)
            // for(int i = 0; i < 5; i ++) {
            //   for(int j = 0; j < 5; j ++) {
            //     cout << board_[all_shuffled][k][i][j] << ' ';
            //   } cout << '\n';
            // } cout<<'\n';
            // cout << vis[cur.X][cur.Y.X][cur.Y.Y] + 1 << '\n';
            ans = min(ans, vis[cur.X][cur.Y.X][cur.Y.Y] + 1);
            flag = true;
            //cout << ans << '!';
            while(!q.empty()) q.pop();
            break;
          }
          vis[nz][nx][ny] = vis[cur.X][cur.Y.X][cur.Y.Y] + 1;
          q.push({nz, {nx, ny}});
        }
      }
    }

  }
  if(flag)
    cout << ans-1;
  else
    cout << -1;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}