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
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int p[4000005];

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if(a == b) return;
  p[a] = b;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  fill(p, p+n+1, -1);
  vector<int> A(m);
  for(int i = 0; i < m; i ++) {
    cin >> A[i];
  }
  sort(all(A));
  int cur = 0;
  for(int i = 1; i <= n; i ++) {
    if(cur < m && i == A[cur]) cur ++;
    else merge(i, i+1);
  }
  while(k --) {
    int t;
    cin >> t;
    int cur = find(t+1);
    cout << cur << nl;
    merge(cur, cur+1);
  }
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