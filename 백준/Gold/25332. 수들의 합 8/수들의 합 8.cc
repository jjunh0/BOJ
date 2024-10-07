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
  int N;
  cin >> N;
  vector<int> A(N), B(N), preA(N+1), preB(N+1);
  map<int, int> mp;
  for(auto &e : A) cin >> e;
  for(auto &e : B) cin >> e;
  ll ans = 0;
  mp[0] = 1;
  for(int i = 0; i < N; i ++) {
    preA[i+1] = preA[i] + A[i];
    preB[i+1] = preB[i] + B[i];
    ans += mp[preA[i+1]-preB[i+1]];
    mp[preA[i+1] - preB[i+1]] ++; 
  }
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