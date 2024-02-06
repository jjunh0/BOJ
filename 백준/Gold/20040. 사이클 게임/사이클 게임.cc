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

vector<int> p(500005, -1);

int find(int x) {
  if(p[x] == -1) return x;
  return p[x] = find(p[x]);
}

bool merge(int a, int b) {
  a = find(a);
  b = find(b);
  if(a == b) return 1;
  p[b] = a;
  return 0;
}

void solve() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  while(m--) {
    int a, b;
    cin >> a >> b;
    if(merge(a, b)) {
      cout << ans+1;
      return;
    }
    ans ++;
  }
  cout << 0;
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