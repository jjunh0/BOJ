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
bool vis[1000005];
void solve() {
  ll mn, mx;
  cin >> mn >> mx;
  ll ans = mx - mn + 1;
  
  for(ll i = 2; i*i <= mx; i ++) {
    for(ll j = (mn/(i*i))*(i*i); j <= mx; j +=i*i) { // j는 제곱수
      if(j >= mn && j <= mx) {
        if(!vis[j-mn]) {
          vis[j-mn] = 1;
          ans --;
        }
      }
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