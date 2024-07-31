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

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> A(m);
  for(auto &e : A) cin >> e;
  ll st = 0, en = 100000010000;
  ll cnt = 0;
  while(st + 1 < en) {
    cnt = 0;
    ll mid = (st+en)/2;
    for(int i = 0; i < m; i ++) {
      cnt += mid/A[i] + 1;
    }
    if(mid == 0) cnt = 0;
    if(n > cnt) st = mid;
    else en = mid;
  }
  cnt = 0;
  for(int i = 0; i < m; i ++) {
    cnt += st/A[i] + 1;
    if(st == 0 && cnt == n) {
      cout << i+1;
      return;
    }
  }
  
  n -= cnt;
  for(int i = 0; i < m; i ++) {
    if(en%A[i] == 0) {
      n --;
    }    
    if(n == 0) {
      cout << i+1;
      break;
    }
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