#include <bits/stdc++.h>
using namespace std;

void solve() {
  int k, l;
  cin >> k >> l;
  unordered_map<string, int> m;
  for(int i = 0; i < l; i ++) {
    string s;
    cin >> s;
    m[s] = i;
  }
  vector<pair<int, string>> v;
  for(auto e : m) {
    v.push_back({e.second, e.first});
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < k && i < v.size(); i ++) {
    cout << v[i].second << '\n';
  }
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}