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
  string s;
  cin >> s;
  stack<char> stk;
  map<char, int> mp;
  mp['-'] = 0; mp['+'] = 0; mp['*'] = 1; mp['/'] = 1; mp['('] = -1;
  for(int i = 0; i < sz(s); i ++) {
    if(s[i] >= 'A' && s[i] <= 'Z') {
      cout << s[i];
    }
    else {
      if(s[i] == '(') stk.push(s[i]);
      else if(s[i] == ')') {
        while(stk.top() != '(') {
          cout << stk.top();
          stk.pop();
        }
        stk.pop();
      }
      else {
        while(sz(stk) && mp[stk.top()] >= mp[s[i]]) {
          cout << stk.top();
          stk.pop();
        }
        stk.push(s[i]);
      }
    }
  }
  while(sz(stk)) {
    cout << stk.top();
    stk.pop();
  }
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