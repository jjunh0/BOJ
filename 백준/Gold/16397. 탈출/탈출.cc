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

vector<int> v(100000);
void solve() {
  int n, t, g;
  cin >> n >> t >> g;
  queue<int> q;
  q.push(n);
  v[n] = 1;
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    if(cur == g) {
      cout << v[cur]-1;
      return;
    }
    if(v[cur] > t) continue;
    int tt;
    // +1
    tt = cur+1;
    if(v[tt] == 0 && tt <= 99999) {
      q.push(tt);
      v[tt] = v[cur] + 1;
    }
    // *2 
    tt = cur*2;
    if(tt <= 99999) {
      int k = 10;
      while(k <= tt) {
        k *= 10;
      }
      k /= 10;
      tt -= k;
      if(v[tt] == 0 && tt > 0) {
        q.push(tt);
        v[tt] = v[cur]+1;
      }
    }
  } 
  cout << "ANG";
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++) {
  //#ifdef DEBUG
  //cout << "Case " << i << ":\n";
  //#endif
  solve();
  //#ifdef DEBUG
  //cout << "============\n";
  //#endif
  }
}