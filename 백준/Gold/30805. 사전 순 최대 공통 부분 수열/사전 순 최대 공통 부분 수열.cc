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
typedef pair<ll, ll> pl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void solve() {
  int AN, BN;
  cin >> AN;
  priority_queue<pi> apq, bpq;
  vector<int> A(AN);
  for (int i = 0; i < AN; i++) {
    cin >> A[i];
    apq.push({A[i], -i});
  }
  cin >> BN;
  vector<int> B(BN);
  for (int i = 0; i < BN; i++) {
    cin >> B[i];
    bpq.push({B[i], -i});
  }
  int a_idx = -1, b_idx = -1;
  vector<int> ans;
  while (!apq.empty() && !bpq.empty()) {
    if (apq.top().X > bpq.top().X) apq.pop();
    else if (apq.top().X < bpq.top().X) bpq.pop();
    else if (-apq.top().Y < a_idx) apq.pop();
    else if (-bpq.top().Y < b_idx) bpq.pop();
    else {
      ans.pb(apq.top().X);
      a_idx = -apq.top().Y;
      b_idx = -bpq.top().Y;
      apq.pop();
      bpq.pop();
    }
  }
  cout << ans.size() << nl;
  for (auto e : ans)
    cout << e << ' ';
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tests = 1;
  while (tests--) {
    solve();
  }
}