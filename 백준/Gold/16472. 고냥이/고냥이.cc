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

vector<int> vis(30);
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int st = 0, en = 0;
  int cnt = 1, ans = 1;
  vis[s[0]-'a'] ++;
  while(1) {
    if(cnt <= n) {
      en ++;
      if(en >= sz(s)) break;
      if(vis[s[en]-'a'] == 0) cnt ++;
      vis[s[en]-'a'] ++;
    }
    else {
      vis[s[st]-'a'] --;
      if(vis[s[st]-'a'] == 0) cnt --;
      st ++;
    }
    if(cnt <= n)
      ans = max(ans, en-st+1);
  }
  cout << ans;
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