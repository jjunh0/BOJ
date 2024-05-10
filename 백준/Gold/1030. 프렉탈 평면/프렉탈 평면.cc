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
int a[10][10];
int pw(int n, int k) {
  int rt = 1;
  for(int i = 0; i < k; i ++) {
    rt *= n;
  }
  return rt;
}

int s, N, K, R1, R2, C1, C2;
bool func(int t, int x, int y) {
  if(t == 0) return 0;
  int n = N*pw(N, t-1);
  int k = K*pw(N, t-1);
  if(x >= (n-k)/2 && x < (n+k)/2 && y >= (n-k)/2 && y < (n+k)/2) return 1;
  return func(--t, x%(n/N), y%(n/N));
}

void solve() {
  cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;
  for(int i = R1; i <= R2; i ++) {
    for(int j = C1; j <= C2; j ++) {
      cout << (func(s, i, j) ? 1 : 0);
    }
    cout << nl;
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