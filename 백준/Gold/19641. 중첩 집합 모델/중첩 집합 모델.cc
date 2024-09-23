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
vector<int> adj[100005];
int L[100005], R[100005], cnt = 1;
void f(int cur, int p) {
  L[cur] = cnt ++;
  for(auto nxt : adj[cur]) {
    if(nxt == p) continue;
    f(nxt, cur);
  }  
  R[cur] = cnt ++;
}

void solve() {
  int N;
  cin >> N;
  for(int i = 0; i < N; i ++) {
    int t, cur;
    cin >> cur;
    while(cin >> t, t != -1) {
      adj[cur].pb(t);
    }
  }
  for(int i = 1; i <= N; i ++) sort(all(adj[i]));
  int S; cin >> S;
  f(S, -1);
  for(int i = 1; i <= N; i ++) {
    cout << i << ' ' << L[i] << ' ' << R[i] << nl;
  }
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