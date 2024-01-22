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



void solve() {
  int n, k;
  cin >> n >> k;
  string s = "";
  for(int i = 0; i < n; i ++) {
    int t;
    cin >> t;
    s += to_string(t);
  }
  map<string, int> st;
  string tar;


  tar = s;
  sort(all(tar));
  queue<string> q;
  q.push(s);
  st[s] = 1;
  while(!q.empty()) {
    string cur = q.front();
    if(cur.compare(tar) == 0) {
      cout << st[cur]-1;
      return;
    }
    q.pop();
    for(int i = 0; i + k - 1 < sz(cur); i ++) {
      string t = cur;
      reverse(t.begin() + i, t.begin() + i + k);
      if(st.find(t) != st.end()) continue;
      st[t] = st[cur] + 1;
      q.push(t);
    }
  }
  cout << -1;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++) {
  //#ifdef DEBUG
  //cout << "Case " << i << ":\n";
  //#endif
  solve();
  //#ifdef DEBUG
  //cout << "============\n";
  //#endif
  }
}