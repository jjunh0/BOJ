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

set<int> cord[50005];
void solve() {
  int N, T;
  cin >> N >> T;
  for(int i = 0; i < N; i ++) {
    int x, y;
    cin >> x >> y;
    cord[y].insert(x);
  }
  cord[0].insert(0);
  queue<ti> q;
  set<pi> vis;
  q.push({0, 0, 0});
  vis.insert({0, 0});
  int ans = MX;
  while(!q.empty()) {
    auto [x, y, dist] = q.front();
    q.pop();
    if(y == T) {
      ans = min(dist, ans);
    }
    for(int yy = y-2; yy <= y+2; yy ++) {
      if(yy < 0) continue;
      for(int xx = x - 2; xx <= x + 2; xx ++) {
        if(xx < 0 || vis.count({xx, yy}) || !cord[yy].count(xx)) continue;
        q.push({xx, yy, dist+1});
        vis.insert({xx, yy});
      }
    }
  }
  cout << (ans != MX ? ans : -1);
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests = 1;
    while(tests--) {
        solve();
    }
}