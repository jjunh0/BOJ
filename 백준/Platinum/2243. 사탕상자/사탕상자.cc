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
		arr[i] += val;
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
  int n;
  cin >> n;
  SegTree st(1000001);
  while(n--) {
    int a, b, c;
    cin >> a;
    if(a == 1) {
      cin >> b;
      int lo = 0, hi = 1000000;
      while(lo+1 < hi) {
        int mid = (lo+hi)/2;
        int sum = st.get(0, mid);
        if(sum >= b) hi = mid;
        else lo = mid;
      }
      cout << hi << nl;
      st.update(hi, -1);
    }
    else {
      cin >> b >> c;
      st.update(b, c);
    }
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