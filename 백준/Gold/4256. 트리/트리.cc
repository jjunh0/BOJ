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
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n; 
vector<int> A(1005), B(1005), vis(1005);
vector<int> adj[1005];

void func(int cur, int st, int en) { 

  for(int i = st; i <= en; i ++) {
    if(B[i] == A[cur]) {
      func(cur+1, st, i-1); // 왼
      func(cur+i-st+1, i+1, en); // 우
      cout << B[i] << ' '; // 가운데
      break;
    }
  }
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i ++) cin >> A[i];
  for(int i = 0; i < n; i ++) cin >> B[i];
  func(0, 0, n-1);
  cout << nl;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}