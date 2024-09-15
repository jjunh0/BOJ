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
  int N;
  cin >> N;
  vector<int> A(N), B;
  for(auto &e : A) cin >> e;
  set<int> st;
  B = A;
  sort(all(B));
  map<int, int> o, s;
  for(int i = 0; i < N; i ++) {
    o[A[i]] = i;
    s[B[i]] = i;
  }
  int ans = 0;
  for(int i  =0; i < N; i ++) {
    ans = max(o[A[i]] - s[A[i]], ans);
  }
  cout << ans;
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