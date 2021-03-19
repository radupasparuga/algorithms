#include <bits/stdc++.h>

using namespace std;

int dp[51][1501];

int solve(int N, int K, int P, int plates[50][50]) {
  for(int i = 0; i < N; ++i) {
    // for(int z = 0; z < 50; ++z) {
    //   cout << dp[i+1][z] << ' ' << dp[i][z] << endl;
    // }
    // cout << endl;
    memcpy(dp[i+1], dp[i], sizeof(dp[0]));
    // for(int z = 0; z < 1501; ++z) {
    //   cout << dp[i+1][z] << ' ' << dp[i][z] << endl;
    // }
    for(int j = 0; j < K; ++j) {
      for(int l = 0; l+j+1 <= P; ++l) {
        // cout << dp[i][l]+plates[i][j] << ' ' << dp[i+1][l+j+1] << endl;
        dp[i+1][l+j+1] = max(dp[i][l]+plates[i][j], dp[i+1][l+j+1]);
      }
    }
  }
  cout << dp[N][P] << "\n";
  return 1;
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tc = 1;
  cin >> tc;

  memset(dp, 0xc0, sizeof(dp));
  dp[0][0] = 0;

  for(int t = 1; t <= tc; ++t) {
    // cout << "Case #" << t  << ": ";
    int N, K, P, plates[50][50];
    cin >> N >> K >> P;

    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < K; ++j) {
        cin >> plates[i][j];
        if(j) plates[i][j] += plates[i][j-1];
      }
    }

    // for(int i = 0; i < N; ++i) {
    //   for(int j = 0; j < K; ++j) {
    //     cout << plates[i][j] << ' ';
    //     // if(j) plates[i][j] += plates[i][j-1];
    //   }
    //   cout << endl;
    //  }
    
    cout << "Case #" << t  << ": ";
    solve(N, K, P, plates);
  }
}