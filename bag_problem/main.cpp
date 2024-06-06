#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cassert>
using namespace std;

class Solution {
public:
    int bagProblem(vector<int>& val, vector<int>& wt, int N, int W) {
      // cout << N << endl;
      // cout << sizeof(wt) << endl;
      // cout << sizeof(wt[0]) << endl;
      // assert(N == sizeof(wt) / sizeof(wt[0]));
      vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
      for (int i = 1; i <= N; ++ i){
        for (int w = 1; w <= W; ++w){
          if(w - wt[i - 1] <= 0){
            dp[i][w] = dp[i - 1][w];
          }
          else{
            dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
          }
        }
      }
      return dp[N][W];
    }
};

int main(){
    Solution *s = new Solution();
    // vector<int> nums = {1,0,-1,0,-2,2};
    int N = 3, W = 4;
    vector<int> val = {2, 1, 3};
    vector<int> wt = {4, 2, 3};
    // nums = [1,0,-1,0,-2,2], target = 0
    // int target = 0;
    int result = s->bagProblem(val, wt, N, W);
    cout << result << endl;
    return 0;
}