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
  int D, K;
  cin >> D >> K;
  vector<int> a(D+1);
  vector<int> b(D+1);
  a[1] = 1;
  b[2] = 1;
  for(int i = 3; i <= D; i ++) {
    a[i] = a[i-1] + a[i-2];
    b[i] = b[i-1] + b[i-2];
  }
  int A = a[D], B = b[D];
  for(int i = 1; i <= K; i ++) {
    // for(int j = (K-A*i)/B; A*i + B*j <= K; j ++) {
    //   cout << i << ' ' << j << ' ' << A*i + B*j << nl;
    //   if(A*i + B*j == K) {
    //     cout << i << nl << j << nl;
    //     return;
    //   }
    // }
    if((K-A*i)%B == 0) {
      cout << i << nl << (K-A*i)/B << nl;
      return;
    }  
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