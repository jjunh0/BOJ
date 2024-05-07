#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define ll long long
#define X first
#define Y second

using namespace std;

const char nl = '\n';
const int mx = 0x3f3f3f3f;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> A;
int dp[100'005][5][5];

int to(int x, int y) {
  if(x == 0) return 2;
  else if(x == y) return 1;
  else if((x+2)%4 + 1 == y || x%4 + 1 == y) return 3;
  else return 4;
}
int func(int idx, int x, int y) {
  if(idx == sz(A)) return 0;
  if(dp[idx][x][y] != 0) return dp[idx][x][y];
  return dp[idx][x][y] = min(to(x, A[idx]) + func(idx+1, A[idx], y), to(y, A[idx]) + func(idx+1, x, A[idx]));
}
void solve() {
  int cur;
  cin >> cur;
  while(cur != 0) {
    A.pb(cur);  
    cin >> cur;
  }
  cout << func(0, 0, 0);
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