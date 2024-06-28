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
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';
const int mx = 0x3f3f3f3f;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
pair<int, int> A[100005];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i ++) {
    int a, b;
    cin >> a >> b;
    A[i] = {a, b};
  }
  sort(A, A+n);
  vector<int> arr;
  vector<pi> path(500005);
  arr.pb(A[0].Y);
  path[A[0].Y] = {1, -1};
  for(int i = 1; i < n; i ++) {
    if(arr.back() < A[i].Y) {
      path[A[i].Y] = {sz(arr)+1, arr.back()};
      arr.pb(A[i].Y);
    }
    else {
      int idx = lower_bound(all(arr), A[i].Y) - arr.begin();
      arr[idx] = A[i].Y;
      if(idx == 0) path[A[i].Y] = {idx+1, -1};
      else path[A[i].Y] = {idx+1, arr[idx-1]};
    }
  }
  int max_sz = 0, max_val = -1;
  for(int i = 1; i <= 500000; i ++) {
    if(path[i].X > max_sz) {
      max_sz = path[i].X;
      max_val = i;
    }
  }
  int cur = max_val;
  cout << n - path[cur].X << nl;
  vector<bool> lis(500005);
  while(cur != -1) {
    lis[cur] = 1;
    cur = path[cur].Y;
  }
  for(int i = 0; i < n; i ++) {
    if(!lis[A[i].Y]) cout << A[i].X << nl;
  }
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
        solve();
    }
}