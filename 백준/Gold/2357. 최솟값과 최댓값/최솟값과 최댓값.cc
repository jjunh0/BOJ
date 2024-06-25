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
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int arr[262144];
int arrMn[262144];
int n, k, m, N=1;

int mx(int L, int R, int nodeNum, int nodeL, int nodeR){
    if(R < nodeL || nodeR < L) return 0;
    if(L <= nodeL && nodeR <= R) return arr[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return max(mx(L, R, nodeNum*2, nodeL, mid), mx(L, R, nodeNum*2+1, mid+1, nodeR));
}
int mn(int L, int R, int nodeNum, int nodeL, int nodeR){
    if(R < nodeL || nodeR < L) return 0x3f3f3f3f;
    if(L <= nodeL && nodeR <= R) return arrMn[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return min(mn(L, R, nodeNum*2, nodeL, mid), mn(L, R, nodeNum*2+1, mid+1, nodeR));
}

void constructMx(){
    for(int i = N-1; i > 0; --i)
        arr[i] = max(arr[i*2],arr[i*2+1]);
}
void constructMn(){
    for(int i = N-1; i > 0; --i)
        arrMn[i] = min(arrMn[i*2],arrMn[i*2+1]);
}



void solve() {
  cin >> n >> m;
  while(N < n) {
    N = (N<<1);
  }
  fill(arrMn, arrMn+262144, 0x3f3f3f3f);
  for(int i = 0; i < n; i ++) {
    cin >> arr[N+i];
    arrMn[N+i] = arr[N+i];
  }
  constructMx();
  constructMn();
  for(int i = 0; i < m; i ++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    cout << mn(a, b, 1, 0, N-1) << ' ' << mx(a, b, 1, 0, N-1) << nl;
  }
}

// ************************************

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
        solve();
    }
} 