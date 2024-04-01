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
vector<int> c(15);
vector<int> adj[15];
int sum = 0;
int n;
vector<int> cand(15);



bool link() {
  int cnt1 = 0, cnt2 = 0;;
  queue<int> q1, q2;
  vector<bool> vis1(n+1), vis2(n+1);
  for(int i = 1; i <= n; i ++) {
    if(cand[i] == 1) {
      cnt1 ++;
      if(q1.empty()) {
        q1.push(i);
        vis1[i] = 1;
      }
    }
    else {
      cnt2 ++;
      if(q2.empty()) {
        q2.push(i);
        vis2[i] = 1;
      }
    }
  }  
  int bfs1 = 1, bfs2 = 1;
  while(!q1.empty()) {
    int cur = q1.front();
    q1.pop();
    for(auto nxt : adj[cur]) {
      if(vis1[nxt] || cand[nxt] == 0) continue;
      vis1[nxt] = 1;
      bfs1 ++;
      q1.push(nxt);
    }
  }
  while(!q2.empty()) {
    int cur = q2.front();
    q2.pop();
    for(auto nxt : adj[cur]) {
      if(vis2[nxt]|| cand[nxt] == 1) continue;
      vis2[nxt] = 1;
      bfs2 ++;
      q2.push(nxt);
    }
  }
  if(bfs1 == cnt1 && bfs2 == cnt2) return true;
  else return false;
}
int mn = mx;
void func(int cur) {
  if(cur > n) {
    if(link()) {

      int sum1 = 0, sum2 = 0;
      for(int i = 1; i <= n; i ++) {
        if(cand[i] == 0) sum1 += c[i];
        else sum2 += c[i];
      }
      mn = min(mn, abs(sum1-sum2));
    }
    return;
  }
  cand[cur] = 1;
  func(cur+1);
  cand[cur] = 0;
  func(cur+1);
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i ++) cin >> c[i+1];
  sum = accumulate(all(c), 0);
  for(int i = 1; i <= n; i ++) {
    int t;
    cin >> t;
    while(t--) {
      int a;
      cin >> a;
      adj[i].pb(a);
    }
  }

  func(1);
  cout << (mn==mx ? -1 : mn);


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