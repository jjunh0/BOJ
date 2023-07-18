#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define X first
#define Y second

void solve() {
  int case_cnt = 1;
  while(1) {
    int n, m;
    cin >> n >> m;
    if(n == 0 && m == 0) break;
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++) {
      int t1, t2;
      cin >> t1 >> t2;
      adj[t1].pb(t2);
      adj[t2].pb(t1);
    }
    int cnt = 0;
    vector<bool> vis(n+1);
    vector<int> par(n+1);
    for(int i = 1; i <= n; i ++) {
      if(vis[i]) continue;
      queue<int> q;
      q.push(i);
      vis[i] = 1;
      //cout << i << ' ';
      bool flag = false;
      while(!q.empty()) {
        int cur = q.front();
        //cout << i << ' ' << cur << '\n';
        q.pop();
        for(int nxt : adj[cur]) {
          if(par[cur] == nxt) continue;
          if(vis[nxt]) {
            flag = true;
            //cout << cur << ' ' << nxt << "break" << '\n';
            break;
          }
          par[nxt] = cur;
          vis[nxt] = 1;
          q.push(nxt);
        }
        if(flag) break;
      }
      if(!flag) cnt ++;
    }
    if(cnt == 0) {
      cout << "Case " << case_cnt++ <<':' << " No trees.\n";
    }
    else if(cnt == 1) {
      cout << "Case " << case_cnt++ <<':' << " There is one tree.\n";
    }
    else {
      cout << "Case " << case_cnt++ <<':' << " A forest of " << cnt << " trees.\n";
    }
  }
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}