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

template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

struct SegTree{
	int size, N;
	vector<pi> arr;
	SegTree(int n){
		size = n;
		N = 1;
		while(N < size) N *= 2;
    arr.resize(2*N+1);
	}
	void update(int i, ll val){
    int idx = i;
		i += N;
		arr[i].X = val;
    arr[i].Y = idx;
		while(i > 1){
			i /= 2;
			arr[i] = min(arr[i*2], arr[i*2+1]);
		}
	}
  void construct(){
		for(int i=N-1; i>0; i--)
			arr[i] = min(arr[i*2], arr[i*2+1]);
	}
  void init(int i, ll val){
    int idx = i;
		i += N;
    arr[i].X = val;
    arr[i].Y = idx;
	}
  pi get(int L, int R, int nodeNum, int nodeL, int nodeR){
      if(R < nodeL || nodeR < L) return {MX, MX};
      if(L <= nodeL && nodeR <= R) return arr[nodeNum];
      int mid = (nodeL + nodeR) / 2;
      return min(get(L, R, nodeNum*2, nodeL, mid), get(L, R, nodeNum*2+1, mid+1, nodeR));
  }
  pi get(int L, int R) {
    return get(L, R, 1, 0, N-1);
  }
};

void solve() {
  int n;
  cin >> n;
  SegTree st(n);
  for(int i = 0; i < n; i ++) {
    int t;
    cin >> t;
    st.init(i, t);
  }
  st.construct();
  int q;
  cin >> q;
  while(q--) {
    int v, i, j;
    cin >> v >> i >> j;
    if(v == 1) {
      st.update(i-1, j);
    }
    else {
      cout << st.get(i-1, j-1).Y+1 << nl;
    }
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