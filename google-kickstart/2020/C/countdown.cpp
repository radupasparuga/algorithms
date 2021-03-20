#include <bits/stdc++.h>

using namespace std;

int n, arr[100000], k;

int solve() {
  cin >> n >> k;
  for(int i = 0; i < n; ++i) cin >> arr[i];
  int count = 0, verifier = 0;
  for(int i = 1; i < n; ++i) {
    if(arr[i] == arr[i-1] -1) verifier++;
    else verifier = 0;
    if(arr[i] == 1 && verifier >= k-1) count++;
  }

  return count;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tc = 1;
  cin >> tc;

  for(int t = 1; t <= tc; ++t) {
    cout << "Case #" << t  << ": ";
    cout << solve() << endl;
  }
}