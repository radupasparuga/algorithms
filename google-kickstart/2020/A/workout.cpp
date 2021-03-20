#include <bits/stdc++.h>

using namespace std;
int n, arr[100000], k;
void solve() {
  cin >> n >> k;
  for(int i = 0; i < n; ++i) cin >> arr[i];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tc = 1;
  cin >> tc;

  for(int t = 1; t <= tc; ++t) {
    cout << "Case #" << t  << ": ";
    solve();
  }
}