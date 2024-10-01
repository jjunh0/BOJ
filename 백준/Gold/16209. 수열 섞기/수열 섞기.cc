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

bool cmp(int a, int b) {
  return abs(a) < abs(b);
}

void f(vector<int> &A, vector<int> & B) {
  sort(all(A), cmp);
  int N = sz(A);
  if(N > 0)
    B.pb(A[0]);
  for(int i = 2; i < N; i += 2) B.pb(A[i]);
  if(N&1) {
    for(int i = N-2; i >= 2; i -= 2) B.pb(A[i]);
  }
  else {
    for(int i = N-1; i >= 2; i -= 2) B.pb(A[i]);
  }
  if(N > 1)
   B.pb(A[1]);
}

void solve() {
  int n;
  cin >> n;
  vector<int> pos, neg;
  for(int i = 0; i < n; i ++) {
    int t;
    cin >> t;
    if(t <= 0) neg.pb(t);
    else pos.pb(t);
  }
  vector<int> A, B;
  f(pos, A), f(neg, B);
  if(sz(A) && A.back() < A.front()) reverse(all(A));
  if(sz(B) && B.back() < B.front()) reverse(all(B));
  for(auto &e : B) cout << e << ' ';
  for(auto &e : A) cout << e << ' ';
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