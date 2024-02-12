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

vector<bool> isPrime(10005, 1);
//vector<bool> mp(10005);
void solve() {
  string a, b;
  cin >> a >> b;
  map<string, int> mp;
  queue<string> q;
  q.push(a);
  mp[a] = 1;
  for(int i = 2; i*i <= 10001; i ++) {
    if(!isPrime[i]) continue;
    for(int j = i*i; j <= 10001; j += i) {
      isPrime[j] = 0;
    }
  }
  while(!q.empty()) {
    string cur = q.front();
    q.pop();
    if(cur.compare(b) == 0) {
      cout << mp[cur]-1 << nl;
      return;
    }
    for(int dir = 0; dir < 4; dir ++) {
      for(char i = '0'; i <= '9'; i ++) {
        if(dir == 0 && i == '0') continue;
        string nxt = cur;
        nxt[dir] = i;
        if(mp[nxt] != 0) continue;
        if(!isPrime[stoi(nxt)]) continue;
        q.push(nxt);
        mp[nxt] = mp[cur] + 1;
      }
    }
  }
  cout << "Impossible\n";
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
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