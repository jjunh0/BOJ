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
void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) {
      cin >> board[i][j];
    }
  }
  int ans = 0;
  bool vis[5][5];
  for(int tmp = 0; tmp < (1<<n*m); tmp ++) {
    int cur = 0;
    for(int i = 0; i < n*m; i ++) {
      vis[i/m][i%m] = ((tmp>>i) & 1);
    }
    for(int i = 0; i < n; i ++) {
      string s = "";
      for(int j = 0; j < m; j ++) { 
        if(vis[i][j]) {
          s += board[i][j];
        }
        else {
          if(sz(s)) cur += stoi(s);
          s = "";
        }
      }
      if(sz(s)) cur += stoi(s); 
    }
    for(int j = 0; j < m; j ++) { 
      string s = "";
      for(int i = 0; i < n; i ++) {
        if(!vis[i][j]) {
          s += board[i][j];
        }
        else {
          if(sz(s)) cur += stoi(s);
          s = "";
        }
      }
      if(sz(s)) cur += stoi(s); 
    }
    ans = max(ans, cur);
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