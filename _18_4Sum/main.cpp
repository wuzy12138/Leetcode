#include <iostream>
#include <vector>
#include <string>
using namespace std;
// void printVector(vector<vector<int>>& nums){
//   cout << "-----start print vector ------" << endl;
//   for (vector<int> v : nums) {
//     for(int num : v){
//       cout << num << " ";
//     }
//     cout << endl;
//   }
//   cout << "-----finish print vector ------" << endl;
// }
class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int l, int r, int target) {
      // int n = nums.size();
      vector<vector<int>> result;
      while (l < r) {
        int left = nums[l], right = nums[r];
        int sum = left + right;
        if(sum < target){
          while (l < r && nums[l] == left) l++;
        }
        else if(sum > target){
          while (l < r && nums[r] == right) r--;
        }
        else{
          result.push_back({nums[l], nums[r]});
          while (l < r && nums[l] == left) l++;
          while (l < r && nums[r] == right) r--;
        }
      }
      return result;
    }
    vector<vector<int>> threeSum(vector<int>& nums, int l, int target) {
      vector<vector<int>> result;
      // int target = 0;
      int n = nums.size();
      int r = n - 1;
      for (int i = l; i < n; ++i){
        vector<vector<int>> twoSumResult = twoSum(nums, i+1, r, target - nums[i]);
        if(twoSumResult.size() != 0){
          for(vector<int> temp : twoSumResult){
            temp.push_back(nums[i]);
            result.push_back(temp);
          }
        }
        while (i < n - 1 && nums[i] == nums[i + 1]) i++;
      }
      return result;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      vector<vector<int>> result;
      sort(nums.begin(), nums.end());
      int n = nums.size();
      // int r = n - 1;
      for (int i = 0; i < n; ++i){
        vector<vector<int>> threeSumResult = threeSum(nums, i+1, target - nums[i]);
        // printVector(threeSumResult);
        if (threeSumResult.size() != 0) {
          for(vector<int> temp : threeSumResult){
            temp.push_back(nums[i]);
            result.push_back(temp);
          }
        }
        while (i < n - 1 && nums[i] == nums[i + 1]) i++;
      }
      return result;
    }
};


int main(){
    Solution *s = new Solution();
    // vector<int> nums = {1,0,-1,0,-2,2};
    vector<int> nums = {-1000000000,1000000000,-1000000000,1000000000};
    // nums = [1,0,-1,0,-2,2], target = 0
    int target = 0;
    vector<vector<int>> result = s->fourSum(nums, target);
    for(auto i : result){
      for(auto j : i){
        cout << j << " ";
      }
      cout << endl;
    }
    return 0;
}