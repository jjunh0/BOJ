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

int val(int v, int cur) {
  if(cur == 0) return v-1;
  else if(cur == 1) return v+1;
  else return v*2;
}

vector<int> d(200005, -1);
int N, K, ans = 0;

void solve() {
  cin >> N >> K;
  queue<int> q;
  q.push(N);
  d[N] = 0;
  int C = -1;
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    if(cur == K) {
      ans ++;
      continue;
    }
    for(int i = 0; i < 3; i ++) {
      int nxt = val(cur, i);
      if(nxt < 0 || nxt > 200000) continue;
      if(d[nxt] == -1 || d[nxt] == d[cur]+1) {
        if(C != -1 && d[cur]+1 > C) continue;
        d[nxt] = d[cur] + 1;
        q.push(nxt);
      }
    }
  }
  cout << d[K] << nl << ans;
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