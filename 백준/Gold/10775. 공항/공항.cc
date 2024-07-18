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
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
  int g, p;
  cin >> g >> p;
  vector<int> nxt(g+1), vis(g+1);
  int t, i;
  for(int i = 1; i <= g; i ++) nxt[i] = i;
  for(i = 0; i < p; i ++) {
    cin >> t;
    bool flag = false;
    for(int j = nxt[t]; j >= 1; j --) {
      if(vis[j]) continue;
      flag = true;
      vis[j] = 1;
      nxt[t] = j;
      break;
    }
    if(!flag) break;
  }
  cout << i;
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