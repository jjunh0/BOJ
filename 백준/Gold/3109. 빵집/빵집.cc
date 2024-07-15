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

int dx[] = {-1, 0, 1};
int dy[] = {1, 1, 1};
int r, c;
string s[10005];

bool func(int x, int y) {
  if(y == c-1) return true;
  for(int dir = 0; dir < 3; dir ++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 0 || nx >= r) continue;
    if(s[nx][ny] != '.') continue;
    s[nx][ny] = 'x';
    if(func(nx, ny)) return true;
  }

  return false;
}
void solve() {
  cin >> r >> c;
  int ans = 0;

  for(int i = 0; i < r; i ++) cin >> s[i];
  for(int i = 0; i < r; i ++) {
    if(s[i][0] == '.') if(func(i, 0)) ans ++;
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