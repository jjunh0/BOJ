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

void solve() {
  int n, m;
  cin >> n >> m;
  queue<int> q;
  vector<int> A(n);
  for(int i = 0; i < n; i ++) {
    int t; cin >> t;
    q.push(t);
    A[i] = t;
  }
  sort(all(A));
  for(int i = 0; i < n; i ++) {
    while(q.front() < A.back()) {
      q.push(q.front());
      q.pop();
      m = (m-1 + sz(q)) % sz(q);
    }
    if(m == 0) {
      cout << i+1 << nl;
      break;
    }
    q.pop();
    m--;
    A.pop_back();
  }
  
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