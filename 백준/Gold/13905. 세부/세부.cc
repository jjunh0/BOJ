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
vector<pi> adj[100005];
int N, M, S, E;

bool check(int min_weight) {
  vector<bool> visited(N+1, false);
  queue<int> q;
  q.push(S);
  visited[S] = true;
  
  while (!q.empty()) {
      int cur = q.front();
      q.pop();
      if (cur == E) return true;
      
      for (auto &edge : adj[cur]) {
          int next = edge.second;
          int weight = edge.first;
          if (!visited[next] && weight >= min_weight) {
              visited[next] = true;
              q.push(next);
          }
      }
  }
  return false;
}

void solve() {
  cin >> N >> M >> S >> E;
  for(int i = 0; i < M; i ++) {
    int h1, h2, k;
    cin >> h1 >> h2 >> k;
    adj[h1].pb({k, h2});
    adj[h2].pb({k, h1});
  }
  int st = 0, en = 1000001;
  while(st+1 < en) {
    int mid = (st+en) / 2;
    if(check(mid)) st = mid;
    else en = mid;
  }
  cout << st;
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