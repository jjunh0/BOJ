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

pair<int, int> p[3] = {{0, 1}, {1, 2}, {0,2}};
void solve() {
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];
  queue<tuple<int, int, int>> q;
  sort(all(a));
  q.push({a[0], a[1], a[2]});
  set<tuple<int, int, int>> st;
  st.insert({a[0], a[1], a[2]});
  while(!q.empty()) {
    vector<int> b(3);
    tie(b[0], b[1], b[2]) = q.front();
    if(b[0] == b[1] && b[1] == b[2]) {
      cout << 1;
      return;
    }
    q.pop();   
    //0, 1 / 1, 2 / 0, 2
    vector<int> c;
    for(int i = 0; i < 3; i ++) {
      c = b;
      c[p[i].Y] = c[p[i].Y] - c[p[i].X];
      c[p[i].X] = c[p[i].X]*2;
      sort(all(c));
      if(c[0] > 0 && st.find({c[0], c[1], c[2]}) == st.end()) {
        st.insert({c[0], c[1], c[2]});
        q.push({c[0], c[1], c[2]});
      }
    }
  }
  cout << 0;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
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