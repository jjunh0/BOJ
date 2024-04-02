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

int n;
vector<int> A(85);
bool is_like(int cur) {
  vector<int> cand;
  for(int i = cur; i > cur/2; i --) {
    cand.pb(A[i]);
    bool not_like = false;
    for(int j = cur-sz(cand); j > cur-2*sz(cand); j --) {
      if(A[j] != cand[cur-sz(cand)-j]) {
        not_like = true;
        break;
      }
    }
    if(!not_like) return false;
  }
  return true;
}
bool flag = false;
void func(int cur) {
  if(flag) return;
  if(cur == n) {
    for(int i = 0; i < n; i ++) cout << A[i];
    flag = true;
    return;
  }
  for(int i = 1; i <= 3; i ++) {
    A[cur] = i;
    if(is_like(cur)) func(cur+1);
  }
}

void solve() {
  cin >> n;
  func(0);
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