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
typedef tuple<int, int, int> ti;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int board[105];

int n;
bool isUsed1[25], isUsed2[25];
int func(int cur, int flag) {
  int ret = 0;
  for(int i = cur; i < n*n; i ++) {
    int x = i/n, y = i%n;
    if(isUsed1[y-x+n] || isUsed2[y+x] || !board[i] || (x+y)%2 == flag) continue;
    isUsed1[y-x+n] = 1, isUsed2[y+x] = 1;
    ret = max(ret, 1+func(i+1, flag));
    isUsed1[y-x+n] = 0, isUsed2[y+x] = 0;
  }
  return ret;

}
void solve() {
  cin >> n;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++) {
      cin >> board[i*n+j];
    }
  }
  int ans = 0;
  ans += func(0, 1) + func(1, 0); 
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