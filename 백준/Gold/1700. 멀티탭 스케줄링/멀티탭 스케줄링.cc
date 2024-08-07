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
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool used[105];
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> A(k);
  int ans = 0;
  for(auto &e : A) cin >> e;
  int cnt = 0;
  for(int i = 0; i < k; i ++) {
    if(used[A[i]]) continue;
    if(cnt < n) {
      cnt ++;
      used[A[i]] = 1;
    }
    else {
      int mx = 0, val;
      for(int j = 1; j <= k; j ++) {
        if(!used[j]) continue;
        int len = k+1;
        for(int l = i+1; l < k; l ++) {
          if(A[l] == j) {
            len = l - i;
            break;
          }
        }
        if(len > mx ) {
          mx = len;
          val = j;
        }
      }
      used[val] = 0;
      used[A[i]] = 1;
      ans ++; 
    }
  }
  cout << ans;
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