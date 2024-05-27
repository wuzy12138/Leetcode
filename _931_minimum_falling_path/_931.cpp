#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
// private:
//  vector<vector<int>>& memo;
public:
 int dp(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memo) {
   if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()) {
     return 99999;
   }
   if (i == 0) {
     return matrix[i][j];
   }
   if (memo[i][j] != 66666) {
     return memo[i][j];
   }
   memo[i][j] = matrix[i][j] + threeMin(dp(matrix, i - 1, j, memo),
                                     dp(matrix, i - 1, j - 1, memo),
                                     dp(matrix, i - 1, j + 1, memo));
   return memo[i][j];
 }
int threeMin(int a, int b, int c){
    return min(a, min(b, c));
}
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int res = INT_MAX;
    vector<vector<int>> memo(n, vector<int>(n, 66666));
    for (int i = 0; i < n; ++i) {
        res = min(res, dp(matrix, n - 1, i, memo));
    }
    return res;
}
};

int main(){
    Solution *s = new Solution();
    vector<vector<int>> test = {{2,1,3},{6,5,4},{7,8,9}};
    cout << s->minFallingPathSum(test) << endl;
    ;
}