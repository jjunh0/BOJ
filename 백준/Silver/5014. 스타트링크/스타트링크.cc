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

int F, S, G, U, D;
int vis[1000005];

void solve() {
  cin >> F >> S >> G >> U >> D;
  vector<int> d = {-D, U};
  vis[S] = 1;
  queue<int> q;
  q.push(S);
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(auto dd : d) {
      int nxt = dd + cur;
      if(nxt > F || nxt < 1 || vis[nxt]) continue;
      vis[nxt] = vis[cur]+1;
      q.push(nxt);
    }
  }
  if(vis[G]) cout << vis[G]-1;
  else cout << "use the stairs";
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