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
#define int ll
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int arr[2097152];
int n, Q, N = 1;

int sum(int L, int R, int nodeNum, int nodeL, int nodeR){
    if(R < nodeL || nodeR < L) return 0;
    if(L <= nodeL && nodeR <= R) return arr[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return sum(L, R, nodeNum*2, nodeL, mid) + sum(L, R, nodeNum*2+1, mid+1, nodeR);
}

void update(int i, int val){
    i += N;
    arr[i] += val;
    while(i > 1){
        i /= 2;
        arr[i] = arr[i*2] + arr[i*2+1];
    }
}


void solve() {
  cin >> n >> Q;
  while(N < n) {
    N = (N<<1);
  }
  while(Q--) {
    int a, b, c;
    cin >> a >> b >> c;
    if(a == 1) {
      update(b-1, c);
    }
    else {
      cout << sum(b-1, c-1, 1, 0, N-1) << nl;
    }
  }
}

// ************************************

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while(tt--) {
        solve();
    }
}