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
  int n;
  cin >> n;
  priority_queue<pi, vector<pi>, less<pi>> A; 
  for(int i = 0; i < n ; i ++) {
    int x, y;
    cin >> x >> y;
    A.push({x, y});
  }
  int ans = 0;
  priority_queue<int, vector<int>, less<int>> pq;
  int cur = A.top().X;
  for(int i = cur; i >= 1; i --) {
    while(sz(A) && A.top().X >= i) {
      pq.push(A.top().Y);
      A.pop();
    }
    if(sz(pq)) {
      ans += pq.top();
      pq.pop();
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