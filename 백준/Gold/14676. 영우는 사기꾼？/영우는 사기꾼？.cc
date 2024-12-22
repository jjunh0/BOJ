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

vector<int> adj[100005], vis(100005), cnt_const(100005), cnt(100005);

bool can_build(int n) {
  return cnt_const[n] == vis[n];
}

void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  for(int i = 0; i < M; i ++) {
    int x, y;
    cin >> x >> y;
    adj[x].pb(y);
    cnt_const[y] ++;
  }
  for(int i = 0; i < K; i ++) {
    int val, n;
    cin >> val >> n;
    if(val == 1 && can_build(n)) {
      if(cnt[n] == 0)
        for(auto nxt : adj[n]) {
          vis[nxt] ++;
        }
      cnt[n] ++;
    }
    else if(val == 2 && cnt[n] > 0) {
      cnt[n] --;
      if(cnt[n] == 0) {
        for(auto nxt : adj[n]) {
          vis[nxt] --;
        }
      }
    }
    else {
      cout << "Lier!";
      return;
    }
  }
  cout << "King-God-Emperor";
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