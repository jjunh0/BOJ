#include <bits/stdc++.h>
using namespace std;

int a[500005];
vector<int> v[500005];
int vis[500005];
void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for(int i = 1; i <= n; i ++) {
      cin >> a[i];
    }
    for(int i = 0; i < m; i ++) {
      int t1, t2;
      cin >> t1 >> t2;
      v[t1].push_back(t2);
      v[t2].push_back(t1);
    }
    queue<int> q;
    for(int i = 0; i < y; i ++) {
      int t;
      cin >> t;
      q.push(t);
      vis[t] = 1;
      while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto c : v[cur]) {
          if(vis[c] != 0 && vis[c] <= vis[cur] + 1) continue; 
          vis[c] = vis[cur] + 1;
          q.push(c);
        }
      }
    }
    vector<long long> val;
    for(int i = 1; i <= n; i ++) {
      val.push_back(1ll * (vis[i]-1) * a[i]);
    }
    sort(val.begin(), val.end());
    // for(int i = 0; i < n; i ++) {
    //   cout << val[i] << ' ';
    // }
    if(val[0] < 0) cout << -1;
    else {
      long long ans = 0;
      for(int i = 0; i < x; i ++) {
        ans += val[val.size() - 1 - i];
      }
      cout << ans;
    }
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}