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
int B[505][505], col[505];
void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  for(auto &e : A) cin >> e;
  priority_queue<pi, vector<pi>,less<>> q;
  for(int i = 0; i < N; i ++) {
    int t;
    cin >> t;
    if(t == 0) continue;
    col[i] = t;
    q.push({t, i});
  }
  for(int i = 0; i < N; i ++) {
    priority_queue<pi, vector<pi>,less<>> q2;
    for(int j = 0; j < A[i]; j ++) {
      if(q.empty()) {
        cout << -1;
        return;
      }
      auto cur = q.top();
      q.pop();
      B[i][cur.Y] = 1;
      if(cur.X > 1) q2.push({cur.X-1, cur.Y});
    }
    while(!q.empty()) {
      q2.push(q.top());
      q.pop();
    }
    q = q2;
  }
  for(int j = 0; j < N; j ++) {
    int sum = 0;
    for(int i = 0; i < N; i ++) {
      sum += B[i][j];
    }
    if(sum != col[j]) {
      cout << -1;
      return;
    }
  }
  cout << 1 << nl;
  for(int i = 0; i < N; i ++) {
    for(int j = 0; j < N; j ++) {
      cout << B[i][j];
    }
    cout << nl;
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