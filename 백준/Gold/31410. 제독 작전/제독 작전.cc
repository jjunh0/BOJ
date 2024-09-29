#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define ll long long
#define X first
#define Y second
using namespace std;

typedef pair<ll, ll> pi;
typedef tuple<int, int, int> ti;
typedef pair<ll,ll> pl;

const char nl = '\n';
const ll MX = 1e18 + 5;
const int MOD = (int)1e9 + 7;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
  ll N;
  cin >> N;
  vector<pi> A(N);
  for(auto &e : A) cin >> e.X >> e.Y;
  sort(all(A));
  ll L = 0, R = 0;
  L += A[0].Y;
  for(int i = 1; i < N; i ++) {
    L += A[i].Y + (A[i].X - A[i-1].X) * i;
    
  }
  R += A[N-1].Y;
  for(int i = N-2; i >= 0; i --) {
    R += A[i].Y + (A[i+1].X - A[i].X) * (N-1 - i);
  }
  ll ans = MX;
  for(int i = 1; i < N-1; i ++) {
    ans = min(ans, min(L - (
     A[i].Y + A[N-1].X - A[i].X 
    ),
      R - (
        A[i].Y + A[i].X - A[0].X
      )
    ));
  }
  ans = min(ans, min(
    {
      L - (A[0].Y + A[N-1].X - A[0].X), R-(A[N-1].Y + A[N-1].X - A[0].X),
    L - (A[N-1].Y + (N-1) * (A[N-1].X - A[N-2].X)), R - (A[0].Y + (N-1) * (A[1].X - A[0].X))
}));
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