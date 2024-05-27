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

void solve() {
  int n, d;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> pq, cand;
  vector<pi> xx;
  for(int i = 0; i < n; i ++) {
    int a, b;
    cin >> a >> b;
    xx.pb({max(a,b), min(a,b)});
  }
  sort(all(xx));
  cin >> d;
  int ans = 0;
  for(int i = 0; i < sz(xx); i ++) {
    cand.push(xx[i].Y);
    while(!cand.empty() && xx[i].X-d > cand.top()) cand.pop();
    ans = max(sz(cand), ans);
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