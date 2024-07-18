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
int cnt[10][1005][1005];
int vis[1005][1005];
void solve() {
  int n, m, p;
  cin >> n >> m >> p;
  vector<int> s(p+1);
  for(int i = 0; i < p; i++) cin >> s[i+1];
  queue<tuple<int, int, int>> q[p+1];
  for(int i = 0; i < n; i ++) {
    string str;
    cin >> str;
    for(int j = 0; j < m; j ++) {
      if(str[j] == '#') {
        vis[i][j] = 10;
      }
      else if(str[j] >= '1' && str[j] <= '9') {
        int cur = str[j]-'0';
        q[cur].push({1, i, j});
        vis[i][j] = cur;
        cnt[cur][i][j] = 1;
      }
    }
  }
  int stage = 1;
  while(1) {
    bool flag = false;
    for(int i = 1; i <= p; i ++) {
      while(sz(q[i])) {
        auto [val, xx, yy] = q[i].front();
        if(val-1 == stage * s[i]) break;
        q[i].pop();
        for(int dir = 0; dir < 4; dir ++) {
          int nx = xx + dx[dir];
          int ny = yy + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if(cnt[i][nx][ny] > val+1 || vis[nx][ny] > 0) continue;
          flag = true;
          cnt[i][nx][ny] = val + 1;
          vis[nx][ny] = i;
          q[i].push({cnt[i][nx][ny], nx, ny});
        }
      }
    }
    if(!flag) break;
    stage ++;
  }
  vector<int> ans(15);
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) { 
      ans[vis[i][j]] ++;
    } 
  }
  for(int i = 1; i <= p; i ++) cout << ans[i] << ' ';
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
        solve();
    }
    return 0;
}