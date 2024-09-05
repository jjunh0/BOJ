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
  int n, m, b;
  cin >> n >> m >> b;
  int N = n * m;
  vector<int> A(N);
  for(int i = 0; i < N; i ++) {
    cin >> A[i];
  }
  int mx = *max_element(all(A)), mn = *min_element(all(A));
  int ans = MX, val;
  for(int h = mn; h <= mx; h ++) {
    int B = b;
    int cur = 0;
    for(int i = 0; i < N; i ++) {
      if(A[i] > h) {
        cur += 2 * (A[i] - h);
        B += A[i]-h;
      }
    }
    for(int i = 0; i < N; i ++) {
      if(A[i] < h) {
        cur += h - A[i];
        B -= h - A[i];
      }
    }
    if(B >= 0 && cur <= ans) {
      val = h;
      ans = cur;
    }
  }
  cout << ans << ' ' << val;
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