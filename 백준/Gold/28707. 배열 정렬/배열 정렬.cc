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
typedef pair<int, vector<int>> iv;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
bool is_sorted(vector<int>& v) {
  for(int i = 1; i < n; i ++) {
    if(v[i-1] > v[i]) return false;
  }
  return true;
}

void solve() {
  cin >> n;
  vector<int> A(n);
  for(auto &e : A) cin >> e;
  cin >> m; 
  vector<ti> M(m);
  for(int i = 0; i < m; i ++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b --;
    M[i] = {c, a, b};
  }
  sort(all(M));
  priority_queue<iv, vector<iv>, greater<iv>> pq;
  pq.push({0, A});
  set<vector<int>> st;
  while(!pq.empty()) {
    auto [dist, V] = pq.top();
    pq.pop();
    if(st.count(V)) continue;
    st.insert(V);
    if(is_sorted(V)) {
      cout << dist << nl;
      return;
    } 
    for(auto [cost, x, y] : M) {
      vector<int> nxt = V;
      swap(nxt[x], nxt[y]);
      pq.push({dist + cost, nxt});
    }
  }
  cout << -1;
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