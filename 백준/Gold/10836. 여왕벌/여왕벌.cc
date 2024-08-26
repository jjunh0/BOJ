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
  int n, D;
  cin >> n >> D;
  vector<int> A(2*n-1);
  A[0] = 1;
  for(int i = 0; i < D; i ++) {
    int c[3];
    cin >> c[0] >> c[1] >> c[2];  
    int idx = 0;
    for(int j = 0; j < 2; j ++) {
      A[idx+c[j]] ++;
      idx += c[j];
    }
  }
  for(int i = 1; i < 2*n-1; i ++) A[i] += A[i-1];
  for(int i = 0; i < n; i ++) {
    cout << A[n-1-i] << ' ';
    for(int j = n; j < 2*n-1; j ++) cout << A[j] << ' ';
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