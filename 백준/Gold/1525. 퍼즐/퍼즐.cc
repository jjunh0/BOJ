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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

char board[5][5];
map<string, int> mp;


void solve() {
  int idx;
  string s;
  for(int i = 0; i < 3; i ++)
    for(int j = 0; j < 3; j ++) {
      cin >> board[i][j];
      if(board[i][j] == '0') {
        idx = i*3 + j;
      }
      s += (board[i][j]);
    }
  queue<pair<int, string>> q;
  q.push({idx, s});
  mp[s] = 1;
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    if(cur.Y == "123456780") break;
    for(int dir = 0; dir < 4; dir ++) {
      int nx = cur.X/3 + dx[dir];
      int ny = cur.X%3 + dy[dir];
      if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
      string nxt = cur.Y;
      swap(nxt[cur.X], nxt[nx*3+ny]);
      if(mp.find(nxt) != mp.end()) continue;
      mp[nxt] = mp[cur.Y] + 1;
      q.push({nx*3+ny, nxt});
    }
  }
  if(mp.find("123456780") != mp.end()) cout << mp["123456780"]-1;
  else cout << -1;
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