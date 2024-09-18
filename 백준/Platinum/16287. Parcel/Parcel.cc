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
  int W, N;
  cin >> W >> N;
  vector<int> A(N), pre;
  for(auto &e : A) cin >> e;
  sort(all(A));
  vector<int> d1(400005, -1), d2(400005, -1);
  for(int i = 0; i < N; i ++) {
    for(int j = i+1; j < N; j ++) {
      int sum = A[i] + A[j];
      pre.pb(sum);
      d1[sum] = i, d2[sum] = j;
    }
  }
  sort(all(pre));
  for(int i = 0; i < N; i ++) {
    for(int j = i+1; j < N; j ++) {
      int sum = W-A[i]-A[j];
      if(sum < 0 || sum > 400000) continue;
      if(d1[sum] != -1 && d2[sum] != -1) {
        if(i == d1[sum] || j == d1[sum] || i == d2[sum] || j == d2[sum]) continue;
        cout << "YES";
        return;
      }
    }
  }
  cout << "NO\n";
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