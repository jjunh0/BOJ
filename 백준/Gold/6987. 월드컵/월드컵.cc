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

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int A[6][3];
pi cord[15] = {
  {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5},
  {1, 2}, {1, 3}, {1, 4}, {1, 5},
  {2, 3}, {2, 4}, {2, 5},
  {3, 4}, {3, 5},
  {4, 5}
};
bool f(int cur) {
  if(cur == 15) {
    for(int i = 0; i < 6; i ++) 
      for(int j = 0; j < 3; j ++) if(A[i][j]) return false;
    return true;
  }
  for(int j = 0; j <= 2; j ++) {
    A[cord[cur].X][j] --;
    A[cord[cur].Y][2-j] --;
    if(A[cord[cur].X][j] >= 0 && A[cord[cur].Y][2-j] >= 0 && f(cur + 1)) return true;
    A[cord[cur].X][j] ++;
    A[cord[cur].Y][2-j] ++;
  }
  return false;
}
void solve() {
  for(int i = 0; i < 6; i ++) {
    for(int j = 0; j < 3; j ++) {
      cin >> A[i][j];
    }
  }
  cout << f(0) << ' ';
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests = 4;
    while(tests--) {
        solve();
    }
}