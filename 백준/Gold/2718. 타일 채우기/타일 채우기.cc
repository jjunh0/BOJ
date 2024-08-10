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

int n;
int dp[30][20];
map<int, vector<int>> adj;
int func(int cur, int bit) {
  if(cur == n) {
    return bit == 0;
  }
  if(dp[cur][bit] != -1) return dp[cur][bit];
  dp[cur][bit] = 0;
  for(auto nxt : adj[bit]) {
    dp[cur][bit] += func(cur+1, nxt);
  } 
  return dp[cur][bit];
}

void solve() {
  cin >> n;
  for(int i = 0; i < 30; i ++) fill(dp[i], dp[i]+20, -1);
  adj[0] = {0, 3, 9, 12, 15};
  adj[3] = {0, 12};
  adj[6] = {9};
  adj[9] = {0, 6};
  adj[12] = {0, 3};
  adj[15] = {0};
  cout << func(0, 0) << nl;
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