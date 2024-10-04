#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define ll long long
#define X first
#define Y second
using namespace std;

#define int ll
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;
typedef pair<ll,ll> pl;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool cmp(pi a, pi b) {
  return 1. * a.X/a.Y < 1. * b.X/b.Y;
}

void solve() {
  int N;
  cin >> N;
  vector<pi> A(N);
  int sumT = 0, sumV = 0;
  for(int i = 0; i < N; i ++) {
    cin >> A[i].Y >> A[i].X;
    sumT +=  A[i].Y;
    sumV += A[i].X;
  }
  int ans = sumV * sumT;
  sort(rall(A), cmp);
  for(int i = 0; i < N; i ++) {
    ans -= sumT * A[i].X;
    sumT -= A[i].Y;
  }
  cout << 2*ans;
}

// ************************************

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests = 1;
    while(tests--) {
        solve();
    }
}