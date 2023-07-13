#include <bits/stdc++.h>
using namespace std;

int imost[500005];
int imosb[500005];
int imos[500005];
int tp[500005];
int bm[500005];

void solve() {
  int n, h;
  cin >> n >> h;
  for(int i = 1; i <= n; i ++) {
    int t;
    cin >> t;
    if(i%2 == 1) { // ¼®¼ø
      bm[0] ++;
      bm[t+1] --;
    } 
    else {
      tp[h] ++;
      tp[h - t] --;
    }
  }
  imosb[0] = bm[0];
  for(int i = 1; i <= h; i ++) {
    imosb[i] = imosb[i-1] + bm[i];
  }
  imost[h] = tp[h];
  for(int i = h-1; i > 0; i --) {
    imost[i] = imost[i+1] + tp[i];
  }
  int mn = 200005;
  int mn_cnt = 0;
  for(int i = 1; i <= h; i ++) {
    int tmp = imost[i] + imosb[i];
    if(tmp < mn) {
      mn = tmp;
      mn_cnt = 1;
    }
    else if(tmp == mn) mn_cnt ++;
  }
  cout << mn << ' ' << mn_cnt;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}