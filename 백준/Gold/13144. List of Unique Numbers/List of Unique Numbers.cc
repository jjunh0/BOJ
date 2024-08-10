#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int cnt[100005];


int nu = 0;

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i ++) {
    cin >> arr[i];
  }
  int st = 0, en = 0;
  cnt[arr[st]] ++;
  long long ans = 0;
  while(st <= en) {
    if(st >= n || en >= n) break;
    if(st == en || nu == 0) ans += en - st + 1;
    if(nu == 0) {
      en ++;
      cnt[arr[en]] ++;
      if(cnt[arr[en]] >= 2) nu ++;
    }
    else {
      if(cnt[arr[st]] >= 2 && cnt[arr[st]] - 1 <= 1) nu--;
      cnt[arr[st]] --;
      st ++;
    }
  }
  cout << ans;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}