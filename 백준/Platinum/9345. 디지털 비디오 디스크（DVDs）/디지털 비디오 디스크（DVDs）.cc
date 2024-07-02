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
const int MAX = 0x3f3f3f3f;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct SegTree{
	int size, N;
	vector<ll> arr;
	SegTree(int n, int val){
		size = n;
		N = 1;
		while(N < size) N *= 2;
    arr.resize(2*N+1);
    fill(all(arr), val);
	}
	void updatemn(int i, ll val){
		i += N;
		arr[i] = val;
		while(i > 1){
			i /= 2;
			arr[i] = min(arr[i*2], arr[i*2+1]);
		}
	}
	void updatemx(int i, ll val){
		i += N;
		arr[i] = val;
		while(i > 1){
			i /= 2;
			arr[i] = max(arr[i*2], arr[i*2+1]);
		}
	}
  void init(int i, ll val){
		i += N;
    arr[i] = val;
	}
  ll getmn(int L, int R, int nodeNum, int nodeL, int nodeR){
      if(R < nodeL || nodeR < L) return MAX;
      if(L <= nodeL && nodeR <= R) return arr[nodeNum];
      int mid = (nodeL + nodeR) / 2;
      return min(getmn(L, R, nodeNum*2, nodeL, mid), getmn(L, R, nodeNum*2+1, mid+1, nodeR));
  }
  ll getmn(int L, int R) {
    return getmn(L, R, 1, 0, N-1);
  }
  ll getmx(int L, int R, int nodeNum, int nodeL, int nodeR){
      if(R < nodeL || nodeR < L) return 0;
      if(L <= nodeL && nodeR <= R) return arr[nodeNum];
      int mid = (nodeL + nodeR) / 2;
      return max(getmx(L, R, nodeNum*2, nodeL, mid), getmx(L, R, nodeNum*2+1, mid+1, nodeR));
  }
  ll getmx(int L, int R) {
    return getmx(L, R, 1, 0, N-1);
  }
  void swapmn(int idx1, int idx2) {
    int t = arr[N+idx1];
    updatemn(idx1, arr[N+idx2]);
    updatemn(idx2, t);
  }
  void swapmx(int idx1, int idx2) {
    int t = arr[N+idx1];
    updatemx(idx1, arr[N+idx2]);
    updatemx(idx2, t);
  }
};

void solve() {
  int n, k;
  cin >> n >> k;
  SegTree mn(n, MAX), mx(n, -1);
  for(int i = 0; i < n; i ++) {
    mn.updatemn(i, i);
    mx.updatemx(i, i);
  }
  while(k--) {
    int a, x, y;
    cin >> a >> x >> y;
    if(a) {
      if(x == mn.getmn(x, y) && y == mx.getmx(x, y)) cout << "YES\n";
      else cout << "NO\n";
    }
    else {
      mn.swapmn(x, y);
      mx.swapmx(x, y);
    }
  }
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}