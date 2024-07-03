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
vector<int> A(10);
int board[45];
int nxt[45];
int move(int cur, int mv) {
  if(cur%5 == 0 && cur < 20 && cur > 0) {
    if(cur == 5) cur = 22;
    if(cur == 10) cur = 25;
    if(cur == 15) cur = 27;
    mv --;
  }
  while(mv != 0 && cur != -1) {
    mv --;
    cur = nxt[cur];
  }
  return cur;
}

int func(int cur, vector<int> B) {
  if(cur == 10) return 0;
  int ret = 0;
  for(int i = 0; i < 4; i ++) {
    if(B[i] == -1) continue;
    bool flag = false;
    int cur_b = B[i];
    int mv = move(B[i], A[cur]);
    for(int j = 0; j < 4; j ++) {
      if(mv != -1 && mv == B[j]) flag = true;
    }
    if(flag) continue;
    B[i] = mv;
    int p = 0;
    if(mv != -1) p = board[mv];
    ret = max(ret, p + func(cur+1, B));
    B[i] = cur_b;
  }
  return ret;
}

void solve() {
  for(auto &e : A) cin >> e;
  for(int i = 0; i <= 20; i ++) {
    board[i] = i*2;
    nxt[i] = i+1;
  }
  nxt[21] = -1;
  nxt[22] = 23; nxt[23] = 24; nxt[24] = 30;
  nxt[25] = 26; nxt[26] = 30;
  nxt[27] = 28; nxt[28] = 29; nxt[29] = 30;
  nxt[30] = 31; nxt[31] = 32; nxt[32] = 20;
  board[22] = 13; board[23] = 16; board[24] = 19;
  board[25] = 22; board[26] = 24;
  board[27] = 28; board[28] = 27; board[29] = 26;
  board[30] = 25; board[31] = 30; board[32] = 35;
  vector<int> B(4);
  cout << func(0, B) << nl;
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