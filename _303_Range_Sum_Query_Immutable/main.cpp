#include <iostream>
#include <vector>
using namespace std;

class NumArray {
 public:
    vector<int> preSum;
    NumArray(vector<int>& nums) {
    int n = nums.size();
    preSum.push_back(0);
    for (int i = 1; i <= n; ++i) {
      preSum.push_back(preSum[i - 1] + nums[i - 1]);
      cout << "preSum[" << i << "] = " << preSum[i] << endl;
    }
  }

  int sumRange(int left, int right) { return preSum[right+1] - preSum[left]; }
};

class NumMatrix {
public:
    vector<vector<int>> preSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; ++i){
            vector<int> temp;
            for(int j = 1; j <= n; ++j){
                temp[0] = 0;
                temp.push_back(temp[j-1] + matrix[i][j - 1]);
            }
            preSum.push_back(temp);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; ++i){
            sum += preSum[i][col2 + 1] - preSum[i][col1 + 1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(){
  vector<int> a = {-2, 0, 3, -5, 2, -1};
  vector<vector<int>> m = {{3, 0, 1, 4, 2},
                           {5, 6, 3, 2, 1},
                           {1, 2, 0, 1, 5},
                           {4, 1, 0, 1, 7},
                           {1, 0, 3, 0, 5}};
//   NumArray* na = new NumArray(a);
  NumMatrix* nm = new NumMatrix(m);
  //   int prompt = 3;
  vector<vector<int>> prompts = {{2, 1, 4, 3}, {1, 1, 2, 2}, {1, 2, 2, 4}};
  for (int i = 0; i < prompts.size(); ++i) {
    int temp = nm->sumRegion(prompts[i][0], prompts[i][1], prompts[i][2], prompts[i][3]);
    cout << "#" << i << ": " << temp << endl;
    
  }
}