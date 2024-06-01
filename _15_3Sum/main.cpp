#include <iostream>
#include <vector>
#include <string>
using namespace std;
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
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> result;
      sort(nums.begin(), nums.end());
      int target = 0;
      int n = nums.size();
      int r = n - 1;
      for (int i = 0; i < n; ++i){
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
};


int main(){
    Solution *s = new Solution();
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = s->threeSum(nums);
    for(auto i : result){
      for(auto j : i){
        cout << j << " ";
      }
      cout << endl;
    }
    return 0;
}