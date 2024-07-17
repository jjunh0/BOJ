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

void down(int y, int t, vector<vector<int>> &b) {
  if(t == 1) {
    int i = 0;
    while(i <= 5 && b[i][y] == 0) i ++;
    i --;
    b[i][y] = 1;
  }
  else if(t == 2) {
    int i = 0;
    while(i <= 5 && b[i][y] == 0 && b[i][y+1] == 0) i ++;
    i --;
    b[i][y] = 1;
    b[i][y+1] = 1;
  }
  else {
    int i = 0;
    while(i <= 5 && b[i][y] == 0) i ++;
    i --;
    b[i][y] = 1;
    b[i-1][y] = 1;
  }
}

int score(vector<vector<int>> &b) {
  int cnt = 0;
  for(int i = 5; i >= 0; i --) {
    bool flag = false;
    for(int j = 0; j <= 3; j ++) {
      if(b[i][j] == 0) {
        flag = true;
        break;
      }
    }
    if(!flag) {
      for(int j = 0; j <= 3; j++) {
        b[i][j] = 0;
      }
    }
    for(int j = 0; j <= 3; j ++) {
      b[i+cnt][j] = b[i][j];
    }
    if(!flag) cnt ++;
  }
  if(cnt != 0) for(int j = 0; j <= 3; j ++) b[0][j] = 0;
  return cnt;
}

void spec(vector<vector<int>> &b) {
  int cnt = 0;
  for(int i = 0; i <= 1; i ++) {
    for(int j = 0; j <= 3; j ++) {
      if(b[i][j]) {
        cnt ++;
        break;
      }
    }
  }
  if(cnt == 0) return;
  for(int i = 5 - cnt; i  >= 0; i --) {
    for(int j = 0; j <= 3; j ++) {
      b[i+cnt][j] = b[i][j];
    }
  }
  for(int i = 0; i <= 1; i ++)
    for(int j = 0; j <= 3; j ++) 
      b[i][j] = 0;
}


void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g(6, vector<int>(4, 0)), b(6, vector<int>(4, 0));
  int ans = 0;
  while(n --) {
    int t, x, y;
    cin >> t >> x >> y;
    if(t == 1) {
      down(y, 1, g);
      down(x, 1, b);
    }
    else if(t == 2) {
      down(y, 2, g);
      down(x, 3, b);
    }
    else {
      down(y, 3, g);
      down(x, 2, b);
    }


    ans += score(g) + score(b);
    spec(g); spec(b);
  }
  cout << ans << nl;
  int cnt = 0;
  for(int i = 0; i <= 5; i ++) {
    for(int j = 0; j <= 3; j ++) {
      if(g[i][j]) cnt ++;
      if(b[i][j]) cnt ++;
    }
  }
  cout << cnt;
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