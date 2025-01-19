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
int P[10005], dp[10005];
vector<vector<int>> C;
void dfs(int idx, int cur) {
  dp[idx] = cur;
  for(auto nxt : C[idx]) {
    dfs(nxt, cur+1);
  }
} 

int f2(int x, int y) {
  if(x == y) return x;
  if(dp[x] == dp[y]) return f2(P[x], P[y]);
  if(dp[x] > dp[y]) return f2(P[x], y);
  return f2(x, P[y]);
}

void solve() {
  int N;
  cin >> N;
  fill(P, P+N+1, -1);
  fill(dp, dp+N+1, -1);
  C.assign(N+1, vector<int>());
  for(int i = 0; i < N-1; i ++) {
    int A, B;
    cin >> A >> B;
    P[B] = A;
    C[A].pb(B);
  }
  for(int i = 1; i <= N; i ++) {
    if(P[i] == -1) {
      dfs(i, 1);
      break;
    }
  }
  int A, B;
  cin >> A >> B;
  cout << f2(A, B) << nl;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    while(tests--) {
        solve();
    }
} 