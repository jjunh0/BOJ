#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define ll long long
#define X first
#define Y second
#define int ll
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

int cross(pi p1, pi p2) {
  return p1.X * p2.Y - p2.X * p1.Y;
}
pi p_sub(pi p1, pi p2) {
  return make_pair(p2.X - p1.X, p2.Y - p1.Y);
}
int ccw(pi p1, pi p2, pi p3) {
  pi v1 = p_sub(p1, p2), v2 = p_sub(p1, p3);
  int res = cross(v1, v2);
  if(res < 0) return -1;
  if(res > 0) return 1;
  return 0;
}


void solve() {
  pi v[4];
  for(int i = 0; i < 4; i ++) cin >> v[i].X >> v[i].Y;
  if(v[0] > v[1]) swap(v[0], v[1]);
  if(v[2] > v[3]) swap(v[2], v[3]);
  int c[4];
  c[0] = ccw(v[0], v[1], v[2]), c[1] = ccw(v[0], v[1], v[3]), c[2] = ccw(v[2], v[3], v[0]), c[3] = ccw(v[2], v[3], v[1]);
  bool flag = false;
  for(int i = 0; i < 4; i ++) {
    if(c[i]) {
      flag = true;
      break;
    }
  }  
  
  if(!flag) {
    if(v[2] >= v[0] && v[2] <= v[1] || v[2] < v[0] && v[3] >= v[0]) cout << 1;
    else cout << 0;
  }
  else if(c[0] * c[1] <= 0 && c[2] * c[3]  <= 0) cout << 1;
  else if(c[0] == 0 && v[2] >= v[0] && v[2] <= v[1]) cout << 1;
  else if(c[1] == 0 && v[0] <= v[3] && v[3] <= v[1]) cout << 1; 
  else cout << 0;  
}

// ************************************

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
        solve();
    }
}