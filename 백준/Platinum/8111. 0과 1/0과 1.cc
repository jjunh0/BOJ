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

vector<pair<int, int>> p(20005);
vector<bool> vis(20005);
int n;

void prt(int cur) {
  if(cur == -1) {
    return;
  }
  prt(p[cur].X);
  cout << p[cur].Y;
}

void solve() {
  cin >> n;
  queue<int> q;
  q.push(1%n);
  fill(all(vis), 0);
  p[1%n] = {-1, 1};
  vis[1%n] = 1;
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    if(cur == 0) break;
    for(int i = 0; i <= 1; i ++) {
      int nxt = (cur*10 + i)  % n;
      if(vis[nxt]) continue;
      p[nxt].X = cur;
      p[nxt].Y = i;
      q.push(nxt);
      vis[nxt] = 1;
    }
  }
  prt(0);
  cout << nl;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}