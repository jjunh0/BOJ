#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m;
int b[55][55];
int ans = 2500 * 13 + 1;
void solve() {
  cin >> n >> m;
  vector<pair<int, int>> chicken;
  vector<int> v;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++) {
      cin >> b[i][j];
      if(b[i][j] == 2) chicken.push_back({i, j});
    }
  }
  for(int i = 0; i < chicken.size(); i ++) {
    v.push_back(i < m ? 0 : 1);
  }

  do {
    vector<pair<int, int>> cand;
    for(int i = 0; i < v.size(); i ++) {
      if(v[i] == 0) {
        cand.push_back(chicken[i]);
      }
    }
    int length = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j ++) {
        if(b[i][j] != 1) continue;
        int mn = 2500;
        for(int k = 0; k < cand.size(); k ++) {
          int nx = cand[k].X;
          int ny = cand[k].Y;
          mn = min(mn, abs(nx - i) + abs(ny - j));
        }
        length += mn;
      }
    }
    ans = min(ans, length);
  } while(next_permutation(v.begin(), v.end()));
  cout << ans;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}