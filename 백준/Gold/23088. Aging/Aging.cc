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
typedef tuple<int, int, int, int> fi;
typedef pair<ll,ll> pl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
  int N;
  cin >> N;
  priority_queue<fi, vector<fi>, greater<>> A;
  int et = MX;
  for(int i = 0; i < N; i ++) {
    int a, b, c;
    cin >> a >> b >> c;
    A.push({a, b, c, i});
    et = min(a, et);
  }
  
  priority_queue<ti, vector<ti>, greater<>> pq;
  while(!A.empty()) {
    while(!A.empty() && get<0>(A.top()) <= et) {
      auto [a, b, c, i] = A.top();
      A.pop();
      pq.push({a-b, c, i});
    }
    if(!pq.empty()) {
      cout << get<2>(pq.top())+1 << ' ';
      et += get<1>(pq.top());
      pq.pop();
    }
  }
  while(!pq.empty()) {
    cout << get<2>(pq.top()) + 1 << ' ';
    pq.pop();
  }
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