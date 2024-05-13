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
// const int mx = 0x3f3f3f3f;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> adj[10'005], radj[10'000];
bool vis[10'0050], vis2[10'005];
int func(int cur) {
  int cnt = 1;
  vis[cur] = 1;
  for(int nxt : adj[cur]) {
    if(!vis[nxt]) {
      cnt += func(nxt);
    }
  }
  return cnt;
}
int func2(int cur) {
  int cnt = 1;
  vis2[cur] = 1;
  for(int nxt : radj[cur]) {
    if(!vis2[nxt]) {
      cnt += func2(nxt);
    }
  }
  return cnt;
}


void solve() {
  int N, M, X;
  cin >> N >> M >> X;
  for(int i = 0; i < M; i ++) {
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    radj[b].pb(a);
  }


  cout << func2(X) << ' ' << N-func(X)+1;
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