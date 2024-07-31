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
#define int ll
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct SegTree{
	int size, N;
	vector<ll> arr;
	SegTree(int n){
		size = n;
		N = 1;
		while(N < size) N *= 2;
    arr.resize(2*N+1);
	}
	void update(int i, ll val){
		i += N;
		arr[i] = val;
		while(i > 1){
			i /= 2;
			arr[i] = arr[i*2] + arr[i*2+1];
		}
	}
  void construct(){
		for(int i=N-1; i>0; i--)
			arr[i] = arr[i*2] + arr[i*2+1];
	}
  void init(int i, ll val){
		i += N;
    arr[i] = val;
	}
  ll get(int L, int R, int nodeNum, int nodeL, int nodeR){
      if(R < nodeL || nodeR < L) return 0;
      if(L <= nodeL && nodeR <= R) return arr[nodeNum];
      int mid = (nodeL + nodeR) / 2;
      return get(L, R, nodeNum*2, nodeL, mid) + get(L, R, nodeNum*2+1, mid+1, nodeR);
  }
  ll get(int L, int R) {
    return get(L, R, 1, 0, N-1);
  }
};


void solve() {
  int n, sum = 0;
  cin >> n;
  vector<pi> A(n);
  SegTree st(n);
  for(int i = 0; i < n; i ++) {
    cin >> A[i].X;
    A[i].Y = i;
    st.init(i, 1);
  }
  st.construct();
  sort(all(A));
  vector<int> ans(n);
  for(int i = 0; i < n; i ++) {
    ans[A[i].Y] = st.get(0, A[i].Y)*A[i].X + st.get(A[i].Y+1, n-1)*(A[i].X-1) + sum;
    sum += A[i].X;
    st.update(A[i].Y, 0);
  }
  for(int i = 0; i < n; i ++) cout << ans[i] << nl;
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