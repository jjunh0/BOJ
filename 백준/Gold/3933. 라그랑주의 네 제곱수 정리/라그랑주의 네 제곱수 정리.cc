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

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int A[(1<<15)+1];

void f(int idx, int val, int sum) {
  if(idx == 4) return;
  for(int i = val; i*i <= (1<<15); i ++) {
    if(sum + i*i <= (1<<15)) {
      A[sum+i*i] ++;
      f(idx+1, i, sum + i*i);
    }
  }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    f(0, 1, 0);
    while(cin >> t, t) {
      cout << A[t] << nl;
    }
}